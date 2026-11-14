document.addEventListener("DOMContentLoaded", function () {
  const postContent = document.querySelector(".post-content");
  const tocList = document.getElementById("toc-list");
  const inPageToc = document.getElementById("in-page-toc");
  if (!postContent || !tocList || !inPageToc) return;

  // Find all h2 and h3 inside .post-content
  const rawHeadings = Array.from(postContent.querySelectorAll("h2, h3"));
  const headings = [];

  rawHeadings.forEach(function (h) {
    // Skip if inside card widgets or figures
    if (h.closest(".card-grid, .value-card, .stat-row, .subsystem-card, figure")) {
      return;
    }
    const txt = h.textContent.trim();
    if (!txt) return;

    // Filter out page title if repeated as an H2 (e.g. "1. Context...", "2. Robot Body...", "3. Robot Legs...")
    if (h.tagName.toLowerCase() === "h2" && /^[0-9]+\.\s+/.test(txt)) {
      return;
    }

    // Filter out detailed appendix sub-items (e.g. "Appendix A: ...", "Appendix B: ...")
    if (/^Appendix\s+[A-Za-z0-9]/i.test(txt)) {
      return;
    }

    headings.push(h);
  });

  if (headings.length < 2) {
    inPageToc.style.display = "none";
    return;
  }

  const items = [];

  headings.forEach(function (heading, index) {
    if (!heading.id) {
      const slug = heading.textContent
        .trim()
        .toLowerCase()
        .replace(/[^a-z0-9]+/g, "-")
        .replace(/^-|-$/g, "");
      heading.id = slug || "section-" + index;
    }

    const li = document.createElement("li");
    li.className = "toc-item " + heading.tagName.toLowerCase();

    const a = document.createElement("a");
    a.href = "#" + heading.id;
    a.className = "toc-link";
    a.textContent = heading.textContent.trim();

    a.addEventListener("click", function (e) {
      e.preventDefault();
      const target = document.getElementById(heading.id);
      if (target) {
        const yOffset = -75;
        const y = target.getBoundingClientRect().top + window.pageYOffset + yOffset;
        window.scrollTo({ top: y, behavior: "smooth" });
        if (history.pushState) {
          history.pushState(null, null, "#" + heading.id);
        } else {
          location.hash = "#" + heading.id;
        }
      }
    });

    li.appendChild(a);
    tocList.appendChild(li);
    items.push({ heading: heading, link: a });
  });

  // ScrollSpy to highlight the current active heading link
  let ticking = false;

  function updateActiveHeading() {
    const scrollPos = window.scrollY + 120;
    let activeLink = null;

    for (let i = 0; i < items.length; i++) {
      const top = items[i].heading.getBoundingClientRect().top + window.pageYOffset;
      if (top <= scrollPos) {
        activeLink = items[i].link;
      } else {
        break;
      }
    }

    if (!activeLink && items.length > 0 && window.scrollY < 250) {
      activeLink = items[0].link;
    }

    items.forEach(function (item) {
      if (item.link === activeLink) {
        item.link.classList.add("active");
      } else {
        item.link.classList.remove("active");
      }
    });

    ticking = false;
  }

  window.addEventListener("scroll", function () {
    if (!ticking) {
      window.requestAnimationFrame(updateActiveHeading);
      ticking = true;
    }
  }, { passive: true });

  updateActiveHeading();
});
