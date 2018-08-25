#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include <DS3231.h>
#include "small4pt7b.h"
//#include <IRremote.h>
#define LED 8
//#define RECV_PIN 11

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(21, 11, LED,
	NEO_MATRIX_TOP + NEO_MATRIX_LEFT +
	NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG,
	NEO_GRB + NEO_KHZ800);

DS3231 clock;
RTCDateTime dt;

//IRrecv irrecv(RECV_PIN);

//decode_results results;
const uint16_t colors[] = {
 matrix.Color(255, 0, 0), matrix.Color(0, 255, 0), matrix.Color(0, 0, 255) };

void setup() {
	// Serial.begin(9600);
	 // In case the interrupt driver crashes on setup, give a clue
	 // to the user what's going on.
	// Serial.println("Enabling IRin");
	// irrecv.enableIRIn(); // Start the receiver
	// Serial.println("Enabled IRin");

	clock.begin();
	// clock.setDateTime(DATE, TIME);

	matrix.begin();
	matrix.setTextWrap(false);
	matrix.setBrightness(5);
	matrix.setTextColor(colors[0]);
	matrix.setFont(&small_5x34pt7b);
}

void loop() {
	// if (irrecv.decode(&results)) {
	//   Serial.println(results.value, HEX);
	//   irrecv.resume(); // Receive the next value
   //  }

	matrix.fillScreen(0);
	dt = clock.getDateTime();
	matrix.setTextColor(0x2E3F);
	matrix.setCursor(2, 4);
	matrix.print(clock.dateFormat("H", dt));
	matrix.setCursor(10, 4);
	if ((dt.second % 2) == 1)
	{
		matrix.print(':');
	}
	matrix.setCursor(12, 4);
	matrix.print(clock.dateFormat("i", dt));
	matrix.setTextColor(0x8E84);
	matrix.setCursor(2, 10);
	matrix.print(clock.dateFormat("d.m", dt));

	matrix.show();
	delay(100);
}
