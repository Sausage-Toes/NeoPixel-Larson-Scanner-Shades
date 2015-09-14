#include <Adafruit_NeoPixel.h>

#define PIN 6
#define NUM_LED 7

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LED, PIN, NEO_GRB + NEO_KHZ800);
const uint32_t OFF = strip.Color(0, 0, 0);
int r = 64;
int g = 16;
int b = 8;
int wait = 100;


void setup() {
  strip.begin();
  //strip.setBrightness(64);
  SetAllPixelsToOff();
  strip.show(); // Initialize all pixels to 'off'
  
}

int pos = 0, dir = 1; // Position, direction of "eye"
 
void loop() {
  int j;
 
  // Draw 5 pixels centered on pos.  setPixelColor() will clip any
  // pixels off the ends of the strip, we don't need to watch for that.
//  strip.setPixelColor(pos - 2, 0x100000); // Dark red
//  strip.setPixelColor(pos - 1, 0x800000); // Medium red
//  strip.setPixelColor(pos    , 0xFF3000); // Center pixel is brightest
//  strip.setPixelColor(pos + 1, 0x800000); // Medium red
//  strip.setPixelColor(pos + 2, 0x100000); // Dark red

  strip.setPixelColor(pos - 2, r*0.1,g*0.1,b*0.1); // Dark
  strip.setPixelColor(pos - 1, r*0.6,g*0.6,b*0.6); // Medium 
  strip.setPixelColor(pos    , r,g,b); // Center pixel is brightest
  strip.setPixelColor(pos + 1, r*0.6,g*0.6,b*0.6); // Medium 
  strip.setPixelColor(pos + 2, r*0.1,g*0.1,b*0.1); // Dark 

  strip.show();
  delay(wait);
 
  // Rather than being sneaky and erasing just the tail pixel,
  // it's easier to erase it all and draw a new one next time.
  for(j=-2; j<= 2; j++) strip.setPixelColor(pos+j, 0);
 
  // Bounce off ends of strip
  pos += dir;
  if(pos < 0) {
    pos = 1;
    dir = -dir;
  } else if(pos >= strip.numPixels()) {
    pos = strip.numPixels() - 2;
    dir = -dir;
  }
}

void SetAllPixelsToOff()
{
  for (uint8_t i = 0; i < NUM_LED; i++)
  {
    strip.setPixelColor(i, OFF);
  }
  strip.show();
}
  
