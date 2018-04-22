AetherOneForArduino *aetherOne;

void setup() {
  aetherOne = new AetherOneForArduino();
  aetherOne->init();
  Serial.begin(9600);
}

void loop() {

  String input = "";

  if (Serial.available() > 0 ) {
    char inChar = Serial.read();

    while (inChar != '#') {
      input += inChar;

      if (Serial.available() > 0 ) {
        inChar = Serial.read();
      } else {
        break;
      }
    }

    Serial.write("read end\n");
  }

  delay(1000);

  aetherOne->executeCommand(input);
}
