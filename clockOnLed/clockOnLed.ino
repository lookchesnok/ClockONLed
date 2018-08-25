#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include <DS3231.h>
#include "small4pt7b.h"
#include <IRremote.h>
#define PIN 3
IRrecv irrecv(2); // указываем вывод, к которому подключен приемник
decode_results results;


Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(21, 11, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800);

DS3231 clock;
RTCDateTime dt;

const uint16_t colors[] = {
 matrix.Color(255, 0, 0), matrix.Color(0, 255, 0), matrix.Color(0, 0, 255) };

void setup() {
//  Serial.begin(9600); // выставляем скорость COM порта
//  irrecv.enableIRIn(); // запускаем прием
  clock.begin();
// clock.setDateTime(DATE, TIME);

  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(5);
  matrix.setTextColor(colors[0]);
  matrix.setFont(&small_5x34pt7b);
}

void loop() {
  
 
  matrix.fillScreen(0);
  dt = clock.getDateTime();
  matrix.setTextColor(0x2E3F);
  matrix.setCursor(2, 4);
  matrix.print(clock.dateFormat("H:i", dt));
  matrix.setTextColor(0x12B8);
  matrix.setCursor(2, 10);
  matrix.print(clock.dateFormat("d.m", dt));

  matrix.show();
  delay(60000);
}
