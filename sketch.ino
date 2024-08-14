#include <LiquidCrystal.h>
#include <Adafruit_NeoPixel.h>

#define LCD_RS 6
#define LCD_EN 7
#define LCD_D4 8
#define LCD_D5 9
#define LCD_D6 10
#define LCD_D7 11
#define BUTTON_PIN 2
#define SLIDER_PIN A0 // gp26 adc0 31st pin
#define BUZZER_PIN 3
#define PIXEL_PIN 4

LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);
Adafruit_NeoPixel pixel = Adafruit_NeoPixel(1, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
    lcd.begin(16, 2);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(BUZZER_PIN, OUTPUT);
    pixel.begin();
    pixel.show();
}

void loop() {
    // TODO
}
