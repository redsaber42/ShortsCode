#include <IRremote.h>

// Place the code from whichever button you want here
// You can find the code by switching which function is enabled in loop()
#define POWER 3125149440

// If IR receiver's data pin is on A1
const int RECV_PIN = A1;
// If LED is on A0
const int LED_PIN = A0;

void setup(){
  Serial.begin(9600);
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);
  IrReceiver.enableIRIn();
  IrReceiver.blink13(true);
}

void loop(){
  // To actually turn on/off the LED
  ControlLED();
  // To print out any received codes so you can record your remotes codes
  // PrintCodes();
}

void ControlLED() {
  if (IrReceiver.decode()){
    if (IrReceiver.decodedIRData.decodedRawData == POWER) {
      analogWrite(LED_PIN, 255);
    }
    IrReceiver.resume();
  }
}

void PrintCodes() {
  if (IrReceiver.decode()){
    Serial.println(IrReceiver.decodedIRData.decodedRawData);
    IrReceiver.resume();
  }
}
