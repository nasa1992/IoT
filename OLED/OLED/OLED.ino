#include<Wire.h>
#include "SSD1306.h"

SSD1306 display(0x3c, 4, 5);

void setup() {
  // put your setup code here, to run once:
  display.init(); //Khởi tạo màn hình
  display.flipScreenVertically(); //Lật ngược màn hình
  display.setFont(ArialMT_Plain_16); //Cài đặt font, size chữ 16
  
  display.clear(); //Clear màn hình
  display.drawString(0,0, "Dao Van Duc\nDep trai"); //Ghi dòng chữ tại tọa độ (0,0) Màn  hình 64*128
  display.display(); //Hiển thị

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 1; i < 11; i++)
  {
    display.clear();
    display.drawString(0,0, String(i));
    display.display();
    delay(1000);
  }
//  static int i = 0;
//  display.clear();
//  display.drawString(0,0, String(++i));
//  delay(1000);
//  i &= 3;
  
}
