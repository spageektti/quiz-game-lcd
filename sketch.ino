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

String questions[] = {"2+2=?", "3+5=?", "7-4=?"};
String answers[][4] = {{"3", "4", "5", "6"}, {"7", "8", "9", "10"}, {"2", "3", "4", "5"}};
int correctAnswers[] = {1, 1, 2};
int currentQuestion = 0;
int selectedAnswer = 0;

void displayQuestion() {
    lcd.clear();
    lcd.print(questions[currentQuestion]);
    lcd.setCursor(0, 1);
    lcd.print("A: " + answers[currentQuestion][0]);
}

void displayAnswers() {
    lcd.setCursor(0, 1);
    lcd.print("A: " + answers[currentQuestion][selectedAnswer]);
}

void loop() {
    displayQuestion();

    int sliderValue = analogRead(SLIDER_PIN);
    selectedAnswer = map(sliderValue, 0, 1023, 0, 3);
    displayAnswers();

    if (digitalRead(BUTTON_PIN) == LOW) {
        if (selectedAnswer == correctAnswers[currentQuestion]) {
            tone(BUZZER_PIN, 1000, 200);
            pixel.setPixelColor(0, pixel.Color(0, 255, 0));
        } else {
            tone(BUZZER_PIN, 200, 200);
            pixel.setPixelColor(0, pixel.Color(255, 0, 0));
        }
        pixel.show();
        delay(1000);
        pixel.setPixelColor(0, pixel.Color(0, 0, 0));
        pixel.show();

        currentQuestion = (currentQuestion + 1) % 3;
    }

    delay(100);
}

