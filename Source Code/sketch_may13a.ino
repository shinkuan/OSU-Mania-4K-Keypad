#include "Keyboard.h"

const byte ROWS = 4; //four rows
const byte COLS = 2; //four columns
#include <Adafruit_NeoPixel.h>  //inclusion of Adafruit's NeoPixel (RBG addressable LED) library
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN            A2 // Which pin on the Arduino is connected to the NeoPixels?
#define NUMPIXELS      8 // How many NeoPixels are attached to the Arduino? 13 total, but they are address from 0,1,2,...12.

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

byte rowPins[ROWS] = {4, 5, 6, 7};    //connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 9};  //connect to the column pinouts of the keypad
byte PressedMap[ROWS] = {0b00000000, 0b00000000, 0b00000000, 0b00000000};
byte bitMap[ROWS] = {0b00000000, 0b00000000, 0b00000000, 0b00000000};

void setup() {
  // pixels.begin(); // This initializes the NeoPixel library.
  // for(int i=0; i<NUMPIXELS; i++) {
  //   pixels.setPixelColor(i, pixels.Color(0, 0, 127));
  // }
  // pixels.show();
  Serial.begin(9600);
  for (byte r=0; r<ROWS; r++) {
		pinMode(rowPins[r],INPUT_PULLUP);
	}
	for (byte c=0; c<COLS; c++) {
		pinMode(colPins[c],OUTPUT);
	}
}


void loop() {
  for (byte c=0; c<COLS; c++) {
		digitalWrite(colPins[c], LOW);	// Begin column pulse output.
		for (byte r=0; r<ROWS; r++) {
		  //Serial.print(int(!digitalRead(rowPins[r])));
			if(!digitalRead(rowPins[r]) && !bitRead(PressedMap[r], c)) {
			  int x = r + c * ROWS;
        Keyboard.press(x + 97);
        Serial.print("Press: ");
        Serial.println(x);
        bitWrite(PressedMap[r], c, 1);
      }else if(digitalRead(rowPins[r]) && bitRead(PressedMap[r], c)) {
        int x = r + c * ROWS;
        Keyboard.release(x + 97);
        Serial.print("Release: ");
        Serial.println(x);
        bitWrite(PressedMap[r], c, 0);
      }
	  }
	  digitalWrite(colPins[c],HIGH);
	  
	}

void scanKeys() {
	// bitMap stores ALL the keys that are being pressed.
	for (byte c=0; c<COLS; c++) {
		pinMode(colPins[c],OUTPUT);
		digitalWrite(colPins[c], LOW);	// Begin column pulse output.
		for (byte r=0; r<ROWS; r++) {
			bitWrite(bitMap[r], c, !digitalRead(rowPins[r]));  // keypress is active low so invert to high.
		}
		// Set pin to high impedance input. Effectively ends column pulse.
		digitalWrite(colPins[c],HIGH);
		pinMode(colPins[c],INPUT);
	}
}

