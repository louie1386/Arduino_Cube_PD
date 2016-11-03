void Timer_setup() {
  timer.every(100, Timer_ADC);
  //timer.every(10, Timer_RXD);
  timer.every(1000, Timer_Sec);
}

void Timer_ADC() {
  for (int ch = 0; ch < Wellnum; ch++) {
    ADCdata[ch * 2] = SPI_Read_channel(ChannelPin[ch * 2]);
    ADCdata[ch * 2 + 1] = SPI_Read_channel(ChannelPin[ch * 2 + 1]);
    if (button[ch] == true) {
      ADCdata[ch * 2] += ButtonStatusByte;
      ADCdata[ch * 2 + 1] += ButtonStatusByte;
    }
    if (LEDonoff[ch] == true) {
      ADCdata[ch * 2] += LEDStatusByte;
      ADCdata[ch * 2 + 1] += LEDStatusByte;
    }
  }
  Serial_Command(ADCdata, false);
}

void Timer_RXD() {
  RX_check();
}

void Timer_Sec() {
  Button_Check();
  LED_Switch();
}
