#include <FastLED.h>

#define NUM_LEDS 150      // количество светодиодов в гирлянде
#define DATA_PIN 6        // пин, к которому подключен сигнальный вход гирлянды

CRGB leds[NUM_LEDS];      // массив трехбайтовых цветов для передачи в гирлянду

void setup()
{
  // Инициализация библиотеки FastLED
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop()
{
  for(int y = 0 ; y < NUM_LEDS ; y++) 
  {
    leds[y] = CRGB::White;  // устанавливаем белый цвет
    FastLED.show();         // включаем отображение
    delay(200);
  }
  delay(10000);
}
