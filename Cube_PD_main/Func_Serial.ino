void Serial_setup() {
  Serial.begin(115200);
  //Serial.println("Start/Reset");
}

void Serial_log(unsigned int data[Channelnum]) {
  double volt[Channelnum];
  for (int i = 0; i < Channelnum; i++)
    volt[i] = (double)(data[i]) / 16384 * 4.096 * 3;
  Serial.print("Ch0: ");
  Serial.print(volt[0]);
  Serial.print(" V, Ch1: ");
  Serial.print(volt[1]);
  Serial.print(" V, Ch2: ");
  Serial.print(volt[2]);
  Serial.print(" V, Ch3: ");
  Serial.print(volt[3]);
  Serial.print(" V, Ch4: ");
  Serial.print(volt[4]);
  Serial.print(" V, Ch5: ");
  Serial.print(volt[5]);
  Serial.print(" V, Ch6: ");
  Serial.print(volt[6]);
  Serial.print(" V, Ch7: ");
  Serial.println(volt[7]);
}

void Serial_TXD(char str) {
  Serial.print(str);
}

char Serial_RXD() {
  char rxstr;
  rxstr = Serial.read();
  return rxstr;
}

void RX_check() {
  char RXD_buffer;
  if (Serial.available() > 0) {
    RXD_buffer = Serial_RXD();
    if (RXD_buffer == command_tag) {
      Serial_Command(ADCdata, false);
    }
  }
}

void Serial_Command(unsigned int data[Channelnum], bool logtype) {
  char databyte[dataBytenum];
  for (int i = 0; i < Channelnum; i++) {
    databyte[i * 2] = byte(data[i] / 256);
    databyte[i * 2 + 1] = byte(data[i]);
  }
  if (logtype) {
    for (int j = 0; j < dataBytenum; j++) {
      if (byte(databyte[j]) < 0x10)
        Serial.print(0);
      Serial.print(byte(databyte[j]), HEX);
      Serial.print(" ");
    }
    Serial.println("");
  }
  else {
    for (int j = 0; j < dataBytenum; j++) {
      Serial_TXD(databyte[j]);
    }
  }
}
