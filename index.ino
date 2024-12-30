#include <Keyboard.h>

const int buttonPin = 16;
const int osButtonPin = 6;

int buttonState = LOW;
int lastButtonState = LOW;
int osButtonState = LOW;

void funcWindows() {
  Serial.println("Button pressed for WIN!");
}

void funcMac() {
  Keyboard.begin();

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('c');
  delay(100);
  Keyboard.releaseAll();

  delay(500);

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(' ');
  delay(100);
  Keyboard.releaseAll();

  delay(500);

  Keyboard.print("Chrome");
  delay(500);

  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();

  delay(1000);

  Keyboard.print("https://chatgpt.com");
  delay(500);
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();

  delay(2000);

  Keyboard.print("Explain: ");
  delay(500);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('v');
  delay(100);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();

  Keyboard.end();
}

void setup() {
  Serial.begin(9600);

  pinMode(buttonPin, INPUT);
  pinMode(osButtonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  osButtonState = digitalRead(osButtonPin);

  if (lastButtonState == HIGH && buttonState == LOW) {

    if(osButtonState == HIGH) {
      funcMac();
    } else {
      funcWindows();
    }

    delay(300);
  }

  lastButtonState = buttonState;
}

