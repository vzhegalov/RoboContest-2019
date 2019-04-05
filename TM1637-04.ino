#define buttonUpClock A0
#define CLK 2
#define DIO 3
#define EEPROMADDR 0

#include <EEPROM.h>
#include "TM1637.h"
#include <ErriezTM1637.h>

#define TM1637_CLK_PIN      2
#define TM1637_DIO_PIN      3

//используется только для вывода на ТМ1637
jTM1637 disp(CLK, DIO);
uint32_t Now;
uint32_t tmr;
boolean flag;
static byte buff[4] = {_S, _H, _O, _P};
byte hrs = 0, mins = 0;

//используется только для считывания кнопок подключенных к TM1637
TM1637 tm1637(TM1637_CLK_PIN, TM1637_DIO_PIN);
static uint8_t keysLast = 0;
uint8_t keys;

void setup() 
{
  Serial.begin(9600);
  while (!Serial) 
  {
      ;
  }
  Serial.println(F("TM1637 example"));
  
  disp.clear();
  disp.brightness(7);  // яркость минимум =0, стандарт=2,  максимум=7)
  Now = millis();

  EEPROMread();
  pinMode(buttonUpClock,INPUT);
  //digitalWrite(buttonUpClock,PULLUP);
}

  
void loop() 
{


  readkeysdisplay();

  
  //running_text();
  //scrolling_text();
  //scrolling_text();
  //rotation_all_sign();
  //rotation_one_sign();
  //blinking_text();

  //normClock();
  twistClock();
  //scrollClock();
}


void readkeysdisplay()
{
  keys = tm1637.getKeys();

  // Check key down
  if (keysLast != keys) 
  {
    keysLast = keys;
    Serial.print(F("Keys: 0x"));
    Serial.println(keys, HEX);
    if(keys == 0x0)
    {
      hrs=0; mins = 0;
      EEPROMwrite();
    }

  }
}



void twistClock()  //часы с вращающимися цифрам//если нажата buttonUpClock то часы +10
{
  //byte hrs = 19, mins = 53;
  //uint32_t tmr;
  //Now = millis();
  //while (millis () - Now < 10000) {   // каждые 10 секунд
  if (millis () - Now < 10000) {
    Now = millis(); 
    if (millis() - tmr > 500) {       // каждые полсекунды
      tmr = millis();
      flag = !flag;
      disp.point(flag);   // выкл/выкл точки

      if (flag) 
      {
        // ***** часы! ****
        //mins ++;
        if(digitalRead(buttonUpClock))
        {
          mins=mins+10;
          EEPROMwrite();
        }
        if (mins > 99)//59) 
        {
          mins = 0;
          hrs++;
          if (hrs > 99) hrs = 0;//24) hrs = 0;
        }
        // ***** часы! ****
        disp.displayClockTwist(hrs, mins, 35);    // показываем часы
      }
    }
  }
  disp.point(0);   // выключить разделитель :
}

void EEPROMread()
{
  hrs = EEPROM.read(EEPROMADDR);
  mins = EEPROM.read(EEPROMADDR+1);

  Serial.print("hrs = ");
  Serial.print(hrs,DEC);
  Serial.print("\t");
  Serial.print("mins = ");
  Serial.print(mins,DEC);
  Serial.println();
}

void EEPROMwrite()
{
  EEPROM.write(EEPROMADDR, hrs);
  EEPROM.write(EEPROMADDR+1, mins);

  Serial.print("WRITE hrs = ");
  Serial.print(hrs,DEC);
  Serial.print("\t");
  Serial.print("mins = ");
  Serial.print(mins,DEC);
  Serial.println();
}



