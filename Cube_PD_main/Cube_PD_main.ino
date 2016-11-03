#include <Event.h>
#include <Timer.h>
#include <SPI.h>

#define  Button_0           2
#define  Button_1           3
#define  Button_2           4
#define  Button_3           5

#define  LED_0              6
#define  LED_1              7
#define  LED_2              8
#define  LED_3              9

/*
 SPI Pin: 10 (SS), 11 (MOSI), 12 (MISO), 13 (SCK)
*/
#define  SSPin              10

#define Well_0_A            7
#define Well_0_B            4
#define Well_1_A            1
#define Well_1_B            6
#define Well_2_A            3
#define Well_2_B            0
#define Well_3_A            5
#define Well_3_B            2

#define  StartBit           B10000000
#define  baseBit            B10000
#define  RangeSelectBits    B0110
#define  ConvStartBits      B0000

#define  ButtonStatusByte   0x8000
#define  LEDStatusByte      0x4000

#define command_tag         char(0xAA)

#define Wellnum             4
#define Channelnum          Wellnum*2
#define dataBytenum         Channelnum*2
#define DrawPointnum        400

#define LED_EnableTimes     15
#define LED_CycleSec        60
#define LED_OnSec           5

Timer timer;
int ChannelPin[Channelnum] = {Well_0_A, Well_0_B, Well_1_A, Well_1_B, Well_2_A, Well_2_B, Well_3_A, Well_3_B};
unsigned int ADCdata[Channelnum];
bool button[Wellnum];
int LED_SecCounter[Wellnum];
int LED_OffTimesCounter[Wellnum];
bool LEDonoff[Wellnum];

bool  LEDEanbleType[LED_EnableTimes + 1] = {false, false, true, true, true, 
                                            true, true, true, true, true, 
                                            true, true, true, true, true, false};

void setup() {
  // put your setup code here, to run once:
  SPI_setup();
  Serial_setup();
  Timer_setup();
  Button_setup();
  LED_setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  timer.update();
}
