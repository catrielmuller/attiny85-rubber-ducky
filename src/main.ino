#include "DigiKeyboard.h"
#define buttonPin 0

boolean buttonState = false;
boolean runMain = true;

void setup() {
  pinMode(buttonPin, INPUT);
}

void loop() {
  DigiKeyboard.sendKeyStroke(0);
  buttonState = digitalRead(buttonPin);
  if(buttonState) {
   runMain = !runMain;
  }

  if (runMain) {
    DigiKeyboard.delay(2000);
    DigiKeyboard.sendKeyStroke(KEY_F2 , MOD_ALT_LEFT);
    DigiKeyboard.delay(300);
    DigiKeyboard.print("gnome-terminal");
    DigiKeyboard.delay(300);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(1000);
    DigiKeyboard.print("wget -O /tmp/bg.jpg \"https://fanart.tv/api/download.php?type=download&image=74758&section=2\"");
    DigiKeyboard.delay(500);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(5000);
    DigiKeyboard.print("gsettings set org.gnome.desktop.background picture-uri file:////tmp/bg.jpg");
    DigiKeyboard.delay(500);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);
    DigiKeyboard.sendKeyStroke(KEY_F4 , MOD_ALT_LEFT);
    runMain = false;
  }
  DigiKeyboard.delay(5000);
}
