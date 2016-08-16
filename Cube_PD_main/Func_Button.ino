void Button_setup() {
  pinMode(Button_0, INPUT);
  pinMode(Button_1, INPUT);
  pinMode(Button_2, INPUT);
  pinMode(Button_3, INPUT);
  for (int i = 0; i < Wellnum; i++) {
    button[i] = false;
    delaycounter[i] = ButtonDelay;
  }
}

void Button_Check() {
  button[0] = digitalRead(Button_0);
  button[1] = digitalRead(Button_1);
  button[2] = digitalRead(Button_2);
  button[3] = digitalRead(Button_3);
}

