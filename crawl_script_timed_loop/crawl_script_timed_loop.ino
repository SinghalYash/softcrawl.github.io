int fvalve = 12;
int bvalve = 11;
int k1valve = 10;
int k2valve = 8;
int k3valve = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(fvalve,OUTPUT);
  pinMode(bvalve,OUTPUT);
  pinMode(k1valve,OUTPUT);
  pinMode(k2valve,OUTPUT);
  pinMode(k3valve,OUTPUT);

  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Start");

  delay(3000);

  digitalWrite(fvalve,HIGH);
  delay(1000) //change accordingly
  Serial.println("front suction enabled");

  digitalWrite(k1valve,HIGH);
  digitalWrite(k2valve,HIGH);
  digitalWrite(k3valve,HIGH);
  Serial.println("kresling suction enabled");
  delay(5000);

  digitalWrite(bvalve,HIGH);
  Serial.println("back suction enabled");
  delay(2000);

  digitalWrite(fvalve,LOW);
  Serial.println("front suction disabled");
  delay(1000); //change

  digitalWrite(k1valve,LOW);
  digitalWrite(k2valve,LOW);
  digitalWrite(k3valve,LOW);
  Serial.println("kresling suction disabled");
  delay(5000); //change

  digitalWrite(bvalve,LOW);
  Serial.println("back suction disabled");
  delay(2000);


}
