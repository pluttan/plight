#include <ESP8266WiFi.h>
#include <ESPAsyncWebServer.h>
#include <FastLED.h>

// Настройки Wi-Fi
const char *ssid = "your_ssid";
const char *password = "your_password";

// Настройки светодиодной ленты
#define LED_PIN 2       // Пин, к которому подключена лента
#define NUM_LEDS 1060   // Количество светодиодов в ленте
#define BRIGHTNESS 255  // Максимальная яркость

CRGB leds[NUM_LEDS];

// Создаем экземпляр веб-сервера
AsyncWebServer server(89);

// Переменные для хранения текущих значений яркости
uint8_t brightness = 65;
int tr = 0;
int on = 1;

// Функция для перевода HEX-кода в RGB
void hexToRGB(const String &hex, uint8_t &r, uint8_t &g, uint8_t &b) {
  long number = strtol(hex.substring(1).c_str(), NULL, 16);  // Преобразуем строку в hex-число
  r = (number >> 16) & 0xFF;
  g = (number >> 8) & 0xFF;
  b = number & 0xFF;
}

// Функция для установки цвета и яркости всей ленты
void setLEDsColor(uint8_t r, uint8_t g, uint8_t b, uint8_t bright, int tr, int on) {
  FastLED.setBrightness(bright);
  int j = 0;
  for (int i = 0; i < NUM_LEDS; i++) {
    if (j == on) {
      int ic = i;
      for(int k = i; (k<i+tr)&&(k< NUM_LEDS); k++){
        leds[k] = CRGB(0, 0, 0);
        Serial.print('|');
      }
      i += tr-1;
      j = 0;
    } else{
      leds[i] = CRGB(r, g, b);
      j++;
      Serial.print('r');
    }
  }
  FastLED.show();
}

void setup() {
  // Инициализация светодиодов
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);

  // Инициализация последовательного порта
  Serial.begin(115200);

  // Подключение к Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Подключение к WiFi...");
  }
  Serial.println("WiFi подключен!");
  Serial.print("IP-адрес: ");
  Serial.println(WiFi.localIP());


  // Обработка корневого маршрута
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    String colorParam = "#b4befe";

    if (request->hasParam("color") && request->hasParam("brightness")) {
      colorParam = request->getParam("color")->value();
      brightness = request->getParam("brightness")->value().toInt();
      tr = request->getParam("tr")->value().toInt();
      on = request->getParam("on")->value().toInt();

      Serial.print(colorParam);
      Serial.print(' ');
      Serial.print(brightness);
      Serial.print(' ');
      Serial.print(tr);
      Serial.print(' ');
      Serial.println(on);
      uint8_t red, green, blue;
      hexToRGB(colorParam, red, green, blue);
      setLEDsColor(red, green, blue, brightness, tr, on);
    }
    request->send(200, "text/html", page(colorParam, brightness, tr, on));
  });

  // Запуск веб-сервера
  server.begin();
}

void loop() {
  // Нет необходимости в коде для цикла, т.к. сервер работает асинхронно
}
