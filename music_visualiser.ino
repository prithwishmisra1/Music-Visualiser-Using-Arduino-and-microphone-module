#include <Adafruit_NeoPixel.h>
#define strip_pin 6
#define mic_input A0
int sensorVal, led_val,r,g,b, t, rcolor;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, strip_pin, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  rcolor = 1;
  t= 0;
  strip.begin();
  strip.show(); // to initialise all strips to be off in the beginning
}
void rainbow(int i)
{
  // violet rgb(180, 24, 180)
  // indigo rgb(89, 0, 153)
  // blue rgb(51, 51, 255)
  // green rgb(0, 255, 0)
  // yellow rgb(179, 179, 0)
  // orange rgb(255, 133, 51)
  // red rgb(255, 0, 0)
  if(i == 1)
  {
    for(int i=0; i<=led_val; i++)
    {
      strip.setPixelColor(30+i, strip.Color(180, 24, 180));
      strip.setPixelColor(30-i+1, strip.Color(180, 24, 180));
      strip.show();
    }
  }
  else if(i == 2)
  {
    for(int i=0; i<=led_val; i++)
    {
      strip.setPixelColor(30+i, strip.Color(89, 0, 153));
      strip.setPixelColor(30-i+1, strip.Color(89, 0, 153));
      strip.show();
    }
  }
  else if(i == 3)
  {
    for(int i=0; i<=led_val; i++)
    {
      strip.setPixelColor(30+i, strip.Color(51, 51, 255));
      strip.setPixelColor(30-i+1, strip.Color(51, 51, 255));
      strip.show();
    }
  }
  else if(i == 4)
  {
    for(int i=0; i<=led_val; i++)
    {
      strip.setPixelColor(30+i, strip.Color(0, 255, 0));
      strip.setPixelColor(30-i+1, strip.Color(0, 255, 0));
      strip.show();
    }
  }
  else if(i == 5)
  {
    for(int i=0; i<=led_val; i++)
    {
      strip.setPixelColor(30+i, strip.Color(179, 179, 0));
      strip.setPixelColor(30-i+1, strip.Color(179, 179, 0));
      strip.show();
    }
  }
  else if(i == 6)
  {
    for(int i=0; i<=led_val; i++)
    {
      strip.setPixelColor(30+i, strip.Color(255, 133, 51));
      strip.setPixelColor(30-i+1, strip.Color(255, 133, 51));
      strip.show();
    }
  }
  else if(i == 7)
  {
    for(int i=0; i<=led_val; i++)
    {
      strip.setPixelColor(30+i, strip.Color(255, 0, 0));
      strip.setPixelColor(30-i+1, strip.Color(255, 0, 0));
      strip.show();
    }
  }
}
void loop() {
  sensorVal = analogRead (mic_input);
  led_val = map(sensorVal, 440, 480, 0, 30); // mapping a value to see how much the led will run
  if(t == 0)
  {
    rcolor = random(1,8);
    t++;
  }
  else if(t == 50000000)
  {
    t = 0;
  }
  else
  {
    t++;
  }
    t = 0;
//  r = random(0,256);
//  g = random(0, 256);
//  b = random(0, 256);
//  r=255;
//  g=0;
//  b=0;
  rainbow(rcolor);
//  for(int i=0; i<=led_val; i++)
//    {
//      strip.setPixelColor(30+i, strip.Color(255, 0, 0));
//      strip.setPixelColor(30-i+1, strip.Color(255, 0, 0));
//      strip.show();
//    }
  for(int i=0; i<=led_val; i++)
  {
    strip.setPixelColor(30+led_val-i, strip.Color(0,0,0));
    strip.setPixelColor(30-led_val-1+i, strip.Color(0,0,0));
    strip.show();
  }
}
