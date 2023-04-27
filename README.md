# atmega32u4-pwm-fan-controller

Naive PWM fan controller for ATMega 32u4.

## Tested Device

- [Adafruit Feather 32u4 Bluefruit LE](https://learn.adafruit.com/adafruit-feather-32u4-bluefruit-le) (`feather32u4`)

## Build

1. Install [PlatformIO Core (CLI)](https://docs.platformio.org/en/latest/core/)
2. Clone this project.
3. Connect your device to your computer.
3. Upload the code by `pio run --target upload`.

## Setup

Connect PWM signal to pin `5`, and the RPM signal to the `GND`.

## LICENSE

MIT. See [LICENSE](LICENSE) for details.

