import os
import re
import shutil
import yaml
import markdown
import sass
from http.server import HTTPServer, SimpleHTTPRequestHandler
import threading
import webbrowser

REPO_DIR = os.path.dirname(os.path.abspath(__file__))
SITE_DIR = os.path.join(REPO_DIR, "_site")

def build_site():
    print("[1/5] Cleaning and creating _site directory...")
    if os.path.exists(SITE_DIR):
        shutil.rmtree(SITE_DIR, ignore_errors=True)
    os.makedirs(SITE_DIR, exist_ok=True)

    # 1. Compile SCSS to CSS
    print("[2/5] Compiling SCSS styles...")
    scss_file = os.path.join(REPO_DIR, "assets", "main.scss")
    out_css_dir = os.path.join(SITE_DIR, "assets")
    os.makedirs(out_css_dir, exist_ok=True)
    
    with open(scss_file, "r", encoding="utf-8") as f:
        scss_content = f.read()

    # Strip YAML front matter if present
    if scss_content.startswith("---"):
        parts = scss_content.split("---", 2)
        scss_content = parts[2] if len(parts) >= 3 else scss_content

    # Mixin & Minima stub
    minima_stub = """
    $on-palm: 600px !default;
    $on-laptop: 800px !default;
    @mixin media-query($device) {
        @media screen and (max-width: $device) {
            @content;
        }
    }
    body { margin: 0; font-family: "Poppins", -apple-system, sans-serif; }
    .wrapper { max-width: 1100px; margin: 0 auto; padding: 0 24px; }
    .site-header { min-height: 56px; position: relative; }
    .site-title { font-size: 20px; font-weight: 800; text-decoration: none; }
    .site-nav { float: right; }
    .site-nav .page-link { text-decoration: none; padding: 5px 12px; }
    .site-footer { border-top: 1px solid rgba(31,111,168,.15); padding: 30px 0; margin-top: 60px; font-size: 14px; }
    .post-header { margin-bottom: 24px; }
    .post-title { font-size: 38px; line-height: 1.15; margin: 0; }
    .post-content { margin-bottom: 30px; }
    """
    cleaned_scss = re.sub(r'@import\s+["\']minima["\'];', minima_stub, scss_content)
    compiled_css = sass.compile(string=cleaned_scss)
    with open(os.path.join(out_css_dir, "main.css"), "w", encoding="utf-8") as f:
        f.write(compiled_css)

    # Copy JS files from assets/
    for item in os.listdir(os.path.join(REPO_DIR, "assets")):
        if item.endswith(".js"):
            shutil.copy2(os.path.join(REPO_DIR, "assets", item), os.path.join(out_css_dir, item))

    # 2. Copy images and videos
    print("[3/5] Copying images and videos...")
    images_src = os.path.join(REPO_DIR, "images")
    if os.path.exists(images_src):
        shutil.copytree(images_src, os.path.join(SITE_DIR, "images"), dirs_exist_ok=True)
    videos_src = os.path.join(REPO_DIR, "videos")
    if os.path.exists(videos_src):
        shutil.copytree(videos_src, os.path.join(SITE_DIR, "videos"), dirs_exist_ok=True)

    # 3. Discover Markdown files
    print("[4/5] Processing pages and reports...")
    pages = []
    for root, dirs, files in os.walk(REPO_DIR):
        dirs[:] = [d for d in dirs if d not in ["_site", ".git", "_layouts", "scratch", ".system_generated"]]
        for file in files:
            if file.endswith(".md"):
                full_path = os.path.join(root, file)
                rel_path = os.path.relpath(full_path, REPO_DIR).replace("\\", "/")
                
                with open(full_path, "r", encoding="utf-8") as f:
                    raw_text = f.read()

                fm = {}
                body = raw_text
                if raw_text.startswith("---"):
                    parts = raw_text.split("---", 2)
                    if len(parts) >= 3:
                        try:
                            fm = yaml.safe_load(parts[1]) or {}
                        except Exception:
                            fm = {}
                        body = parts[2]

                # Determine permalink
                permalink = fm.get("permalink")
                if not permalink:
                    if rel_path == "index.md":
                        permalink = "/"
                    elif rel_path.endswith("/index.md"):
                        permalink = "/" + rel_path[:-8] + "/"
                    else:
                        permalink = "/" + rel_path[:-3] + "/"
                if not permalink.endswith("/") and not permalink.endswith(".html"):
                    permalink += "/"

                pages.append({
                    "file": file,
                    "rel_path": rel_path,
                    "full_path": full_path,
                    "fm": fm,
                    "body": body,
                    "title": fm.get("title", file[:-3].replace("-", " ").title()),
                    "layout": fm.get("layout", "default"),
                    "group": fm.get("group", ""),
                    "code": fm.get("code", ""),
                    "nav_order": fm.get("nav_order", 999),
                    "permalink": permalink,
                    "url": permalink
                })

    # Separate report pages
    report_pages = [p for p in pages if p["layout"] == "report" and p["nav_order"] > 0]
    report_pages.sort(key=lambda x: x["nav_order"])

    # 4. Render pages
    def replace_liquid_tags(text):
        # Replace {{ '/path' | relative_url }} with /path
        text = re.sub(r"{{\s*['\"]([^'\"]+)['\"]\s*\|\s*relative_url\s*}}", r"\1", text)
        text = re.sub(r"\{\{.*?\}\}", "", text)
        text = re.sub(r"\{%.*?%\}", "", text)
        return text

    for p in pages:
        body_text = replace_liquid_tags(p["body"])
        html_content = markdown.markdown(body_text, extensions=['tables', 'fenced_code', 'attr_list'])

        # If layout == report
        if p["layout"] == "report" and p["nav_order"] > 0:
            # Build sidebar
            sidebar_items = ""
            for rp in report_pages:
                active_cls = ' class="active"' if rp["url"] == p["url"] else ''
                sidebar_items += f'<li><a href="{rp["url"]}"{active_cls}>{rp["title"]}</a></li>\n'

            # Previous / Next navigation
            curr_idx = -1
            for i, rp in enumerate(report_pages):
                if rp["url"] == p["url"]:
                    curr_idx = i
                    break
            prev_link = ""
            next_link = ""
            if curr_idx > 0:
                prev_p = report_pages[curr_idx - 1]
                prev_link = f'<a href="{prev_p["url"]}">← {prev_p["title"]}</a>'
            if curr_idx >= 0 and curr_idx < len(report_pages) - 1:
                next_p = report_pages[curr_idx + 1]
                next_link = f'<a href="{next_p["url"]}">{next_p["title"]} →</a>'

            tag_html = ""
            if p["group"]:
                code_str = f" · {p['code']}" if p["code"] else ""
                tag_html = f'<span class="tag">{p["group"].upper()}{code_str}</span>'

            main_body = f"""
            <div class="report-layout">
              <aside class="report-nav">
                <p class="report-nav-title">Flight plan</p>
                <p class="report-nav-group">Interim</p>
                <ul>
                  {sidebar_items}
                </ul>
                <div class="in-page-toc" id="in-page-toc">
                  <hr class="toc-divider">
                  <p class="toc-nav-title">On this page</p>
                  <ul id="toc-list" class="toc-list"></ul>
                </div>
              </aside>
              <article class="post">
                <header class="post-header">
                  {tag_html}
                  <h1 class="post-title">{p["title"]}</h1>
                </header>
                <div class="post-content">
                  {html_content}
                </div>
                <nav class="report-pager">
                  <span>{prev_link}</span>
                  <span>{next_link}</span>
                </nav>
              </article>
            </div>
            <script src="/assets/toc.js"></script>
            """
        else:
            # Standard page or report index
            main_body = f"""
            <article class="post">
              <header class="post-header">
                <h1 class="post-title">{p["title"]}</h1>
              </header>
              <div class="post-content">
                {html_content}
              </div>
            </article>
            """

        # Full Site Wrapper (Default Layout)
        full_html = f"""<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>{p["title"]} | Soft Crawl</title>
  <link rel="preconnect" href="https://fonts.googleapis.com">
  <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
  <link href="https://fonts.googleapis.com/css2?family=Montserrat:wght@700;800;900&family=Poppins:wght@400;500;600;700&family=JetBrains+Mono:wght@400;600&display=swap" rel="stylesheet">
  <link rel="stylesheet" href="/assets/main.css">
</head>
<body>
  <header class="site-header">
    <div class="wrapper" style="display: flex; justify-content: space-between; align-items: center; padding: 18px 24px;">
      <a class="site-title" href="/" style="color: #f6eedc; font-family: Montserrat, sans-serif; font-size: 20px; font-weight: 900; letter-spacing: 0.04em;">SOFT CRAWL</a>
      <nav class="site-nav">
        <div class="trigger">
          <a class="page-link" href="/about/" style="color: #99ceee; font-weight: 600; font-size: 14px; margin-left: 16px;">About</a>
          <a class="page-link" href="/report/" style="color: #99ceee; font-weight: 600; font-size: 14px; margin-left: 16px;">Report</a>
          <a class="page-link" href="/contact/" style="color: #99ceee; font-weight: 600; font-size: 14px; margin-left: 16px;">Contact</a>
        </div>
      </nav>
    </div>
  </header>

  <main class="page-content" aria-label="Content" style="padding-top: 36px; padding-bottom: 48px;">
    <div class="wrapper">
      {main_body}
    </div>
  </main>

  <footer class="site-footer">
    <div class="wrapper" style="text-align: center; color: #6b7b8c;">
      <p style="margin: 0; font-size: 14px;">Soft Crawl — A soft pneumatic climbing robot for aircraft fuel tank inspection · ASI-404, NUS</p>
    </div>
  </footer>
</body>
</html>
"""
        # Determine output file location
        if p["permalink"] == "/":
            dest_file = os.path.join(SITE_DIR, "index.html")
        else:
            rel_dir = p["permalink"].strip("/")
            dest_dir = os.path.join(SITE_DIR, rel_dir)
            os.makedirs(dest_dir, exist_ok=True)
            dest_file = os.path.join(dest_dir, "index.html")

        with open(dest_file, "w", encoding="utf-8") as f:
            f.write(full_html)

    # Ensure legacy /report/structure/ redirects to /report/body/
    structure_dir = os.path.join(SITE_DIR, "report", "structure")
    os.makedirs(structure_dir, exist_ok=True)
    with open(os.path.join(structure_dir, "index.html"), "w", encoding="utf-8") as f:
        f.write('<!DOCTYPE html><html><head><meta http-equiv="refresh" content="0; url=/report/body/"><script>window.location.replace("/report/body/");</script></head><body>Redirecting to <a href="/report/body/">Robot Body</a>...</body></html>')

    print(f"[5/5] Successfully rendered {len(pages)} pages to _site/!")

class CustomHandler(SimpleHTTPRequestHandler):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, directory=SITE_DIR, **kwargs)

def run_server(port=8000):
    server_address = ('', port)
    httpd = HTTPServer(server_address, CustomHandler)
    print(f"\n=======================================================")
    print(f"🚀 SITE IS LIVE AT: http://localhost:{port}/")
    print(f"=======================================================\n")
    httpd.serve_forever()

if __name__ == "__main__":
    import sys
    build_site()
    if "--build-only" in sys.argv:
        print("Build complete. Skipping server.")
        sys.exit(0)
    port = 8000
    t = threading.Thread(target=run_server, args=(port,), daemon=True)
    t.start()
    try:
        webbrowser.open(f"http://localhost:{port}/report/next-steps/")
    except Exception:
        pass
    print("Press Ctrl+C to stop the server.")
    t.join()
