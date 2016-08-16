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

#define  SSPin              10

#define  StartBit           B10000000
#define  baseBit            B10000
#define  RangeSelectBits    B0110
#define  ConvStartBits      B0000

#define  ButtonDisableByte  0x8000

#define command_tag         char(0xAA)

#define Wellnum             4
#define Channelnum          Wellnum*2
#define dataBytenum         Channelnum*2
#define DrawPointnum        400

#define ButtonDelay         2

Timer timer;
unsigned int ADCdata[Channelnum];
int TimeCounter[Wellnum];
bool button[Wellnum];
int delaycounter[Wellnum];

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
