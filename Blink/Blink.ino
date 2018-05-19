int led = 16;

/*Hàm gọi 1 lần duy nhất khi khởi động*/
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT); //Cấu hình pin 16 ngõ ra
}

/*Hàm loop() sẽ được gọi liên tục*/
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led, LOW); //Bật LED bởi mức điện áp LOW

  delay(500); //Chờ 1s
  digitalWrite(led, HIGH); //Tắt LED (HIGH là mức cao)
  delay(2000); //Chờ 2s
}
