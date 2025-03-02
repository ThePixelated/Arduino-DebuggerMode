class LED_DebugMode {
  const int digitalPin = 14;

  public:
    int Lenght(int arr[]) { // TODO: benerin ni, masih outputnya 1 terus
      return (sizeof(arr) / sizeof(arr[0]));
    }

    void AddPin(int indexPin) {
      Serial.print("Write LED index to the pin...\n");
        pinMode(targetVar[indexPin], OUTPUT);
    }
    
    void AddPin(int indexPin, int targetVar[]) {
      Serial.print("Added LED index to the pin...\n");
      if (targetVar[indexPin] == -1) {
        // Serial.printf("Index %d have been added...\n", indexPin);
        targetVar[indexPin] = indexPin;
        pinMode(targetVar[indexPin], OUTPUT);
      } else {
        Serial.print("Index occupied...\n");
      }// PrintArr(targetVar);
    }

    void AddPin(int pins[], int targetVar[]) {
      for (int i = 0; i < Lenght(pins); i++) {
        if (targetVar[pins[i]] == -1) {
          targetVar[pins[i]] = pins[i];
          pinMode(targetVar[pins[i]], OUTPUT);
          // Serial.printf("Index %d have been added...\n", pins[i]);
        } else {
          Serial.print("Index occupied...\n");
        }
      }// PrintArr(targetVar);
    }

    void PrintArr(int arr[]) {
      Serial.print("[");
      for (int i = 0; i < digitalPin; i++) {
        Serial.print(arr[i]);
        if(i < 14 - 1) Serial.print(",");
      }Serial.print("] - On Board Pin \n");
    }

    void NeutralizePin(int pins[]) {
      Serial.print("Neutralize pins...\n");
      for (int i = 0; i < digitalPin; i++) pins[i] = -1;
    }

    void TurnOnAll_LED(int LEDPins[]) {
      Serial.print("Trun on all lights...\n");
      for (int i = 0; i < digitalPin; i++) {
        if (LEDPins[i] != -1) digitalWrite(LEDPins[i], HIGH);
      }
    }

    void TurnOffAll_LED(int LEDPins[]) {
      Serial.print("Trun off all lights...\n");
      for (int i = 0; i < digitalPin; i++) {
        if (LEDPins[i] != -1) digitalWrite(LEDPins[i], LOW);
      }
    }

    void BlinkLight(int LEDs[], int duration = 1000) {
      for (int i = 0; i < digitalPin; i++) {
        if (LEDs[i] != -1) digitalWrite(LEDs[i], HIGH);
      } delay(duration);

      for (int i = 0; i < digitalPin; i++) {
        if (LEDs[i] != -1) digitalWrite(LEDs[i], LOW);
      } delay(duration);
    }

    void BlinkLight(int LED, int duration = 1000) {
      digitalWrite(LED, HIGH);
      delay(duration);
      digitalWrite(LED, LOW);
      delay(duration);
    }

    // tambahin:
    // Overwrite - 2 variant (single sama banyakan),
    // OverwriteAll, Delete, DeleteAll; *ini keknya ga usah -> TurnOnLED, TurnOffLED (terkecuali bisa pass array pin)
    // TurnOnLED sama off bisa ada 3 variant*
    // TurnOnLED(int pin)
    // TurnOnLED(int pin, int targetVar[])
    // TurnOnLED(int pins[], int targetVar[])
};