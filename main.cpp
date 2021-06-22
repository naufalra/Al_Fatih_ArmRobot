#include <Arduino.h>
#include <Alfatih.h>
#include <CRC_Generator.h>
#include <packet_servo.h>
#include <pixypixy.h>

void setup()
{
  Serial.begin(115200);
  first_setup();
  AXsetup();
  XLsetup();
  converter(13, 20, 90);  //Higher is lower
  converter(14, 20, 90);  //Higher is upper
  converter(15, 20, 160); //tutup 180, lower is open
  packet_builder(XL);
  delay(1000);
}

void loop()
{
  pixymon();
  
}
// // Serial.println("Haha");
// for (int i = 13; i < 16; i++)
// {
//   converter(i, 50, 180);
// }
// packet_builder(XL);
// delay(200);
// for (int i = 13; i < 16; i++)
// {
//   converter(i, 50, 140);
// }
// packet_builder(XL);
// delay(200);

