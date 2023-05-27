#include <Servo.h>
Servo cotovelo;
Servo pont;
Servo ombro;
int pos;
void setup() {
  Serial.begin(9600);
  cotovelo.attach(5);
  cotovelo.write(0);
  pont.attach(8);
  pont.write(0);
  ombro.attach(11);
  ombro.write(120);

}
void loop() {
  Serial.println("Colocar posição do cotovelo: ");
  while(Serial.available() == 0){};
  pos = Serial.readString().toInt();
  if (pos >=0 && pos <= 60){
    cotovelo.write(pos);
    Serial.print("Turned to: ");
    Serial.println(pos);
  }
  else {
    Serial.println("Invalid postition!");
  }

   Serial.println("Enter position: ");
  while(Serial.available() == 0){};
  pos = Serial.readString().toInt();
  if (pos >= 0 && pos <= 180){
    pont.write(pos);
    Serial.print("Turned to: ");
    Serial.println(pos);
  }
  else {
    Serial.println("Invalid postition!");
  }
}