String page(String color, int brightness, int tr, int on) {
  return (
    R"rawliteral(
      <!DOCTYPE HTML>
      <html>
        <head>
          <title>Управление LED</title>
          <meta charset="UTF-8">
          <meta name="viewport" content="width=device-width, initial-scale=1">
        </head>
        <body>
          <h2>Выбор цвета и яркости</h2>
          <form action="/" method="get">
            <label for="color">Цвет:</label>
            <input type="color" id="color" name="color" value=")rawliteral"
          + color + R"rawliteral("><br><br>

            <label for="tr">Через:</label>
            <input type="number" id="tr" name="tr" min="0" max="1000" step="1" placeholder="Через" value=")rawliteral"
          + String(tr) + R"rawliteral("><br><br>

            <label for="on">По:</label>
            <input type="number" id="on" name="on" min="0" max="1000" step="1" placeholder="По" value=")rawliteral"
          + String(on) + R"rawliteral("><br><br>

            <label for="brightness">Яркость:</label>
            <input type="range" id="brightness" name="brightness" min="0" max="255" value=")rawliteral"
          + String(brightness) + R"rawliteral("><br><br>

            <input type="submit" value="Применить">
          </form>
        </body>
      </html>
    )rawliteral");
}