// Definging varibles
int Red = A3;
int Green = A4;
int Blue = A5;


void setup() {
 delay(1000);
 Serial.begin(9600);
 pinMode(Red, OUTPUT);
 pinMode(Green, OUTPUT);
 pinMode(Blue, OUTPUT);
}

void loop() {
  int ph = analogRead(A0);
  Serial.print("Sensor Vaule: ");
  Serial.println(ph);
  switch(ph){
  case 680:
   digitalWrite(Red, HIGH);
   Serial.println("Red On");
   break;
  case 690:
   digitalWrite(Green, HIGH);
   Serial.println("Green On");
   break;
  case 695:
   digitalWrite(Blue, HIGH);
   Serial.println("Blue On");
   break;
  default:
   digitalWrite(Red, LOW);
   digitalWrite(Green, LOW);
   digitalWrite(Blue, LOW);
   break;
  }
  delay(10);
}
