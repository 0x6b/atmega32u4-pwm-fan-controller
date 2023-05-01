#include "Arduino.h"
#include "Adafruit_BluefruitLE_SPI.h"

#if SOFTWARE_SERIAL_AVAILABLE
#include <SoftwareSerial.h>
#endif

#define VERBOSE_MODE         true
#define BLUEFRUIT_SPI_CS     8
#define BLUEFRUIT_SPI_IRQ    7
#define BLUEFRUIT_SPI_RST    4
#define PWM_OUT              5
#define FACTORY_RESET_ENABLE 1

Adafruit_BluefruitLE_SPI ble(BLUEFRUIT_SPI_CS, BLUEFRUIT_SPI_IRQ, BLUEFRUIT_SPI_RST);

void setup() {
    pinMode(PWM_OUT, OUTPUT);
    analogWrite(PWM_OUT, 19); // 0-255
    delay(500);

    Serial.begin(115200);
    Serial.println("Adafruit Bluefruit PWM Fan Controller");
    Serial.println("-------------------------------------");

    Serial.print("Initialising the Bluefruit LE module: ");

    if (!ble.begin(VERBOSE_MODE)) {
        Serial.println("Couldn't find Bluefruit, make sure it's in CoMmanD mode & check wiring?");
    }
    Serial.println("OK!");

    /* Perform a factory reset to make sure everything is in a known state */
    if (FACTORY_RESET_ENABLE == 1) {
        Serial.println("Performing a factory reset: ");
        if (!ble.factoryReset()) {
            Serial.println("Couldn't factory reset");
        }
    }

    /* Disable command echo from Bluefruit */
    ble.echo(false);

    /* Print Bluefruit information */
    ble.info();

    Serial.println("Please use atmega32u4-pwm-fan-controller-cli to control the fan speed.");
    Serial.println();

    ble.verbose(false);

    while (!ble.isConnected()) {
        delay(500);
    }
}

void loop() {
    delay(1000);

    // Check for incoming characters from Bluefruit
    ble.println("AT+BLEUARTRX");
    ble.readline();
    if (strcmp(ble.buffer, "OK") == 0) {
        // no data
        return;
    }
    // Some data was found
    Serial.print("[Recv] ");

    int val = int(strtol(ble.buffer, nullptr, 10));
    Serial.println(val);
    if (val < 0) {
        val = 0;
    }
    if (val > 255) {
        val = 255;
    }
    analogWrite(PWM_OUT, val); // 0-255
    ble.waitForOK();
}
