# ESP32 NimBLE Combo Keyboard & Mouse library

This library allows you to make the ESP32 act as a Bluetooth keyboard and mouse with Arduino and the efficient NimBLE library.

NimBLE allows the program to take up about half as much storage on the ESP32 than the standard BLE library, with the exact same functionality.


## Installation
- (Make sure you can use the ESP32 with the Arduino IDE. [Instructions can be found here.](https://github.com/espressif/arduino-esp32#installation-instructions))
- Download the latest NimBLE library through the "Manage Libraries" tab in the Arduino IDE.
- [Download the latest release of this library from the release page.](https://github.com/pdcook/ESP32-NimBLE-Combo/releases)
- In the Arduino IDE go to "Sketch" -> "Include Library" -> "Add .ZIP Library..." and select the file you just downloaded.
- You can now go to "File" -> "Examples" -> "ESP32 BLE Combo" and select any of the examples to get started.

## Example

```
#include <NimBleCombo.h>

void setup() {
  Serial.begin(115200);
  Serial.println("Starting work!");
  Keyboard.begin();
  Mouse.begin();
}

void loop() {
  if(Keyboard.isConnected()) {
    Serial.println("Sending 'Hello world'");
    Keyboard.println("Hello World");

    Serial.println("Sending Enter key...");
    Keyboard.write(KEY_RETURN);

    Serial.println("Sending Play/Pause media key...");
    Keyboard.write(KEY_MEDIA_PLAY_PAUSE);

    Serial.println("Sending Ctrl+Alt+Delete...");
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_DELETE);
    delay(100);
    Keyboard.releaseAll();

    Serial.println("Move mouse pointer up");
    Mouse.move(0,-10);
    
    Serial.println("Scroll Down");
    Mouse.move(0,0,-1);

    Serial.println("Left click");
    Mouse.click(MOUSE_LEFT);
  }
  
  Serial.println("Waiting 2 seconds...");
  delay(2000);
}

```
## Credits

This is a fork of [blackketter's ESP32-BLE-Combo library](https://github.com/blackketter/ESP32-BLE-Combo).

This is fork of _a fork of_ @T-kV's excellent [ESP32-BLE-Mouse](https://github.com/T-vK/ESP32-BLE-Mouse)
and [ESP32-BLE-Keyboard](https://github.com/T-vK/ESP32-BLE-Keyboard) libraries.

You might also be interested in:

- [ESP32-BLE-Mouse](https://github.com/T-vK/ESP32-BLE-Mouse)
- [ESP32-BLE-Keyboard](https://github.com/T-vK/ESP32-BLE-Keyboard)
- [ESP32-BLE-Gamepad](https://github.com/lemmingDev/ESP32-BLE-Gamepad)

