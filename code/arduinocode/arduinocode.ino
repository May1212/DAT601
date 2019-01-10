#include <Adafruit_NeoPixel.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX
#define PIN            A0
#define NUMPIXELS      300
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 10;
String str = "11";
int precount;
void setup() {
  Serial.begin(9600);
  Serial.setTimeout(3);
  mySerial.begin(4800);
  pixels.begin();
  pinMode(13, OUTPUT);
}

void loop() {

  if (Serial.available()) {
    str = Serial.readString();
    int count = str.toInt();
    mySerial.print(count);
    lightLed((count) *5);
  }
}
void lightLed(int count) {
  //  clearled();
  if (count > precount) {
    for (int i = precount; i <= count; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 255, 0)); // Moderately bright green color.
      pixels.show();
      precount = count;
    }
  }
  else if (count < precount) {
    for (int i = precount; i >= count; i--) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0)); // Moderately bright green color.
      pixels.show();
      precount = count;
    }
  }
}
void clearled() {
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.show();
  }
}

