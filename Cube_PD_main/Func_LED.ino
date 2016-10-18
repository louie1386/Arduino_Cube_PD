void LED_setup() {
  pinMode(LED_0, OUTPUT);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  digitalWrite(LED_0, LOW);
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, LOW);
  digitalWrite(LED_3, LOW);
  for (int i = 0; i < Wellnum; i++) {
    LED_SecCounter[i] = LED_CycleSec;
    LED_OffTimesCounter[i] = LED_EnableTimes;
  }
}

void LED_Switch() {
  for (int i = 0; i < Wellnum; i++) {
    if (button[i] == true) {
      if (LED_SecCounter[i] > 0)
        LED_SecCounter[i]--;
      else {
        LED_SecCounter[i] = LED_CycleSec;
        if (LED_OffTimesCounter[i] > 0)
          LED_OffTimesCounter[i]--;
      }
    }
    else {
      LED_SecCounter[i] = LED_CycleSec;
      LED_OffTimesCounter[i] = LED_EnableTimes;
    }

    if (LED_SecCounter[i] > LED_OnSec)
      LEDonoff[i] = false;
    else if (LED_SecCounter[i] <= LED_OnSec) {
      if (LED_OffTimesCounter[i] > LED_OnTimes || LED_OffTimesCounter[i] == 0)
        LEDonoff[i] = false;
      else
        LEDonoff[i] = true;
    }
  }
  digitalWrite(LED_0, LEDonoff[0]);
  digitalWrite(LED_1, LEDonoff[1]);
  digitalWrite(LED_2, LEDonoff[2]);
  digitalWrite(LED_3, LEDonoff[3]);
}

