void LED_setup() {
  pinMode(LED_0, OUTPUT);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  digitalWrite(LED_0, LOW);
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, LOW);
  digitalWrite(LED_3, LOW);
}

void LED_Switch() {
  bool LEDonoff[Wellnum];
  for (int i = 0; i < Wellnum; i++) {
    if (TimeCounter[i] < DrawPointnum)
      LEDonoff[i] = button[i];
    else
      LEDonoff[i] = false;
  }
  digitalWrite(LED_0, LEDonoff[0]);
  digitalWrite(LED_1, LEDonoff[1]);
  digitalWrite(LED_2, LEDonoff[2]);
  digitalWrite(LED_3, LEDonoff[3]);
}

