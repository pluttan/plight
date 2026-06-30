![Header](header.png)

<div align="center">

# Plight

**1060 WS2812B LED strip controller with web interface on ESP8266**

[![License](https://img.shields.io/badge/license-MIT-2C2C2C?style=for-the-badge&labelColor=1E1E1E)](LICENSE)
[![ESP8266](https://img.shields.io/badge/ESP8266-NodeMCU-2C2C2C?style=for-the-badge&logo=espressif&labelColor=1E1E1E)]()
[![FastLED](https://img.shields.io/badge/FastLED-WS2812B-2C2C2C?style=for-the-badge&labelColor=1E1E1E)]()

</div>

WiFi-controlled WS2812B LED strip with 1060 LEDs. The ESP8266 hosts an async web server with a color picker, brightness slider, and configurable on/off pattern (every N LEDs lit, every M dark). Designed for large-scale ceiling or room installations.

## ■ Features

- ❖ **1060 LEDs** — drives a full WS2812B strip from a single data pin (GPIO 2)
- ❖ **Web color picker** — native HTML `<input type="color">`, converted to RGB on the device
- ❖ **Brightness slider** — 0-255 range via web UI
- ❖ **Pattern control** — set how many LEDs stay lit (`on`) and how many go dark (`tr`) for repeating density effects
- ❖ **Async web server** — ESPAsyncWebServer on port 89, GET form submit
- ❖ **Catppuccin default** — ships with `#b4befe` (lavender) as default color

## ■ Stack

| Component | Technology |
|-----------|------------|
| MCU | ESP8266 (NodeMCU) |
| LED | WS2812B x1060 |
| Framework | Arduino |
| LED library | FastLED |
| Web server | ESPAsyncWebServer |
| Interface | HTML form with color picker |

## ■ Usage

```bash
# Set `ssid` / `password` in Plight.ino to your WiFi network
# Open Arduino IDE
# Select board: NodeMCU 1.0
# Upload Plight.ino
```

The ESP8266 joins your WiFi as a station and prints its IP over serial (115200 baud). Open `http://<IP>:89/` in a browser to control color, brightness, and LED pattern.

## ■ Files

- `Plight.ino` — main firmware (WiFi, LED control, web server routes)
- `page.ino` — HTML page generator with color picker and controls

## ■ License

MIT © [pluttan](https://github.com/pluttan)
