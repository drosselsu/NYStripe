#include <FastLED.h>

#define NUM_LEDS 150        // количество светодиодов в гирлянде
#define DATA_PIN 6          // пин, к которому подключен сигнальный вход гирлянды
#define CMD_NEW_DATA 1      // 1 - начало нового кадра для матрицы
#define BAUD_RATE 500000    // скорость передачи данных по последовательному порту
#define NEW_FRAME_DELAY 50  // задержка перед отображением нового кадра - может настраиваться
                            // для соответствия работы гирлянды и управляющей программы
CRGB leds[NUM_LEDS];        // массив трехбайтовых цветов для передачи в гирлянду

void setup()
{
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // Инициализация библиотеки FastLED
  for(int y = 0 ; y < NUM_LEDS ; y++)                   // Быстрый тест для проверки гирлянды
  {
    leds[y] = CRGB::White;  // устанавливаем белый цвет
    FastLED.show();         // включаем отображение
    delay(50);
  }
  delay(1000);
  Serial.begin(BAUD_RATE); // устанавливаем скорость обмена данными с компьютером
}
 
int serialGlediator()       // ожидаем получения данных от компьютера
{
  while (!Serial.available()) {}
  return Serial.read();
}

void loop()
{
  while (serialGlediator() != CMD_NEW_DATA) {}  // ждем пока не получим признак нового кадра
  Serial.readBytes((char*)leds, NUM_LEDS*3);    // получаем от компьютера массив цветов для гирлянды
  FastLED.show();                               // включаем отображение гирлянды
  delay(NEW_FRAME_DELAY);                       // выжидаем задержку 
}
