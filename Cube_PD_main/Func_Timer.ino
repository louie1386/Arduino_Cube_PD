void Timer_setup() {
  timer.every(100, Timer_ADC);
  timer.every(10, Timer_RXD);
  timer.every(1000, Timer_Button);
  for (int i = 0; i < Wellnum; i++)
    TimeCounter[i] = 0;
}

void Timer_ADC() {
  for (int ch = 0; ch < Wellnum; ch++) {
    if (button[ch] == true) {
      if (delaycounter[ch]) {
        delaycounter[ch]--;
        ADCdata[ch * 2] = ButtonDisableByte;
        ADCdata[ch * 2 + 1] = ButtonDisableByte;
      }
      else {
        ADCdata[ch * 2] = SPI_Read_channel(ch * 2);
        ADCdata[ch * 2 + 1] = SPI_Read_channel(ch * 2 + 1);
      }
    }
    else {
      ADCdata[ch * 2] = ButtonDisableByte;
      ADCdata[ch * 2 + 1] = ButtonDisableByte;
      delaycounter[ch] = ButtonDelay;
    }
  }
  //Serial_log(ADCdata);
  //Serial_Command(ADCdata, true);
}

void Timer_RXD() {
  RX_check();
}

void Timer_Button() {
  Button_Check();
  LED_Switch();
}
