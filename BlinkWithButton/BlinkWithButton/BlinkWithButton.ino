#include <ArduinoOTA.h>

int led = 16;
int btn = 0;
int state = HIGH;

void changeLedState()
{
  digitalWrite(led, !digitalRead(led));

}

bool isPressed()
{
  static bool pressed = false;
  int btnStatus = digitalRead(btn);
  if(btnStatus == LOW  && pressed == false)
  {
    pressed = true;
    return true;
  }

  if(btnStatus == HIGH && pressed == true)
  {
    pressed = false;   
  }

  return false;
}
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(btn, INPUT);
  Serial.begin(115200); //Khởi tạo Serial với tốc độ 115200
}

void loop() {
  // put your main code here, to run repeatedly:
  if(isPressed()){
//    changeLedState();
//    Serial.println(state);
  }
}
