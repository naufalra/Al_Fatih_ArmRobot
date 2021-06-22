#ifndef pixypixy_h
#define pixypixy_h
#include <Pixy2SPI_SS.h>
#include <Arduino.h>
#include <Alfatih.h>
#include <CRC_Generator.h>
#include <packet_servo.h>
Pixy2SPI_SS pixy;
unsigned long lastTime, lastTime2, lastTime3;
bool pixyuwi = 0;

void pixymon()
{
    Serial.println(pixyuwi);
    XLsetup();
    first_setup();
    pixy.init();
    pixy.ccc.getBlocks();
    if (pixy.ccc.numBlocks)
    {

        Serial.print("Detected");
        Serial.println(pixy.ccc.numBlocks);
        pixyuwi = 1;
        if (pixyuwi == 1)
        {
            converter(13, 20, 120);
            converter(14, 20, 140); //Higher is upper
            converter(15, 20, 120); //tutup 180
            packet_builder(XL);
            delay(1000);

            converter(13, 20, 120);
            converter(14, 20, 140); //Higher is upper
            converter(15, 20, 180); //tutup 180
            packet_builder(XL);
            delay(2000);
            
            converter(13, 20, 50);
            converter(14, 20, 60);  //Higher is upper
            converter(15, 20, 180); //tutup 180
            packet_builder(XL);
            delay(2000);
        }
        for (int i = 0; i < pixy.ccc.numBlocks; i++)
        {
            Serial.print(" block ");
            Serial.print(i);
            Serial.print(": ");
            pixy.ccc.blocks[i].print();
        }
    }
    else
    {
        pixyuwi = 0;
    }
    // if (millis() - lastTime > 1000)
    // {
    //     converter(13, 20, 120);
    //     converter(14, 20, 140); //Higher is upper
    //     converter(15, 20, 120); //tutup 180
    //     Serial.println("haha");
    //     packet_builder(XL);
    //     lastTime = millis();
    // }

    // if (millis() - lastTime2 > 2000)
    // {
    //     lastTime2 = millis();
    //     converter(13, 20, 120);
    //     converter(14, 20, 140); //Higher is upper
    //     converter(15, 20, 180); //tutup 180
    //     Serial.println("hihi");
    //     packet_builder(XL);
    // }

    // if (millis() - lastTime3 > 2000)
    // {
    //     lastTime3 = millis();
    //     converter(13, 20, 50);
    //     converter(14, 20, 60);  //Higher is upper
    //     converter(15, 20, 180); //tutup 180
    //     Serial.println("huhu");
    //     packet_builder(XL);
    // }

    delay(1000);
}

#endif
