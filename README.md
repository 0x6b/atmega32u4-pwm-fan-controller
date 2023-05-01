# atmega32u4-pwm-fan-controller

Naive PWM fan controller for ATMega 32u4.

## Tested Device

- [Adafruit Feather 32u4 Bluefruit LE](https://learn.adafruit.com/adafruit-feather-32u4-bluefruit-le) (`feather32u4`)

## Build

1. Install [PlatformIO Core (CLI)](https://docs.platformio.org/en/latest/core/)
2. Clone this project.
3. Connect your device to your computer.
4. Upload the code by `pio run --target upload`.

## Setup

Connect PWM signal to pin `5`, and the RPM signal to the `GND`.

## Usage

Connect to your Feather 32u4 via [Bluefruit Connect on the App Store](https://apps.apple.com/app/adafruit-bluefruit-le-connect/id830125974), and send a value from 0 to 255 to the controller. The controller will set the PWM duty cycle according to the value.

You can control the fan speed from the companion CLI at [0x6b/atmega32u4-pwm-fan-controller-cli](https://github.com/0x6b/atmega32u4-pwm-fan-controller-cli).


## LICENSE

MIT. See [LICENSE](LICENSE) for details.

