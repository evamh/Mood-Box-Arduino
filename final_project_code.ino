#include "DFRobotDFPlayerMini.h"
#include <Adafruit_NeoPixel.h>
#include <arduino-timer.h>

// Neopixel values
#define PIXEL_PIN 5
#define NUMPIXELS 32 
#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

DFRobotDFPlayerMini myDFPlayer;
Adafruit_NeoPixel pixels(NUMPIXELS, PIXEL_PIN, NEO_GRB + NEO_KHZ800);
auto timer = timer_create_default();

// pins + constants
const int button1Pin = 2; //use digital pins
const int button2Pin = 3;
const int button3Pin = 4;

const int atom1Pin = 7;
const int atom2Pin = 8;
const int atom3Pin = 9;

const int potentiometerPin = A0;
const int maxRGBValue = 255;

// values
int button1 = 0;
int button2 = 0;
int button3 = 0;
int potentiometerVal = 0;

// for colors 
int mappedRed = 0;
int mappedGreen = 0;
int mappedBlue = 0;

// keep track of current state (i.e. sleep, focus, boost)
int previousPotentiometerVal = 0;
int currentState = 0;

// for song choices
int songNumber = 1;
int sleepSongs[] = {1, 2, 3};
int focusSongs[] = {4, 5, 6};
int boostSongs[] = {7, 8, 9};

void setup()
{

  // for testing
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);

  // Serial
  Serial.begin(115200);
  Serial1.begin(9600);

  Serial.println("setup()");
  
  // DFPlayerMini setup - from DFPlayerMini example
  Serial.println(F("DFRobot DFPlayer Mini"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));

  //Use softwareSerial to communicate with board
  if (!myDFPlayer.begin(Serial1)) {  

    digitalWrite(13, HIGH);

    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
  }
 
  Serial.println(F("DFPlayer Mini online."));
  myDFPlayer.volume(0);

  // Neopixel
  pixels.begin();

  // Set up pin modes - Input 
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(button3Pin, INPUT_PULLUP);

  pinMode(potentiometerPin, INPUT);

  // Output
  pinMode(atom1Pin, OUTPUT);
  pinMode(atom2Pin, OUTPUT);
  pinMode(atom3Pin, OUTPUT);

  // Initially turn off atomizers
  digitalWrite(atom1Pin, HIGH);
  digitalWrite(atom2Pin, HIGH);
  digitalWrite(atom3Pin, HIGH);

  // Set up timer function
  timer.every(1000, run_logic);

}

void loop() {

  // From DFPlayerMini example - get status
  if (myDFPlayer.available()) {
    printDetail(myDFPlayer.readType(), myDFPlayer.read()); 
  }

  // From timer example - timer tick
  timer.tick();

}

// Function with main logic
void run_logic() {
  
  // From Adafruit pixel example
  pixels.clear();

  // get status of which button was pressed
  button1 = digitalRead(button1Pin);
  button2 = digitalRead(button2Pin);
  button3 = digitalRead(button3Pin);

  // Potentiometer value
  potentiometerVal = analogRead(potentiometerPin);
  myDFPlayer.volume(20);

  // Change the pixel shade if the potentiometer was rotated (threshold of 30)
  if(abs(potentiometerVal - previousPotentiometerVal) > 30) {
    
    // Map colors
    mapPixelAndSetColor(currentState);

    // Update previous potentiometer value
    previousPotentiometerVal = potentiometerVal;
  }

  // Option 1 - SLEEP
  if(button1 == LOW) {
    Serial.println("button 1 pressed");

    // Play music
    myDFPlayer.stop();
    songNumber = getSongNumber(1);
    myDFPlayer.play(songNumber);

    // Turn first atomizer on
    setAtomizers(LOW, HIGH, HIGH);

    // Set neopixel colour
    mapPixelAndSetColor(1);

    // Set current state to 1
    currentState = 1;

  } // Option 2 - FOCUS
  else if(button2 == LOW) {
    Serial.println("button 2 pressed");
    
    // Play music
    myDFPlayer.stop();
    songNumber = getSongNumber(2);
    myDFPlayer.play(songNumber);

    // Set second atomizer on
    setAtomizers(HIGH, LOW, HIGH);

    // Set neopixel colour
    mapPixelAndSetColor(2);
    
    // Set current state to 2
    currentState = 2;

  } // Option 3 - BOOST
  else if(button3 == LOW) {
    Serial.println("button 3 pressed");

    // Play music
    myDFPlayer.stop();
    songNumber = getSongNumber(3);
    myDFPlayer.play(songNumber);

    // Set third atomizer on
    setAtomizers(HIGH, HIGH, LOW);

    // Set neopixel colour
    mapPixelAndSetColor(3);

    // Set current state to 3
    currentState = 3;
  }

  return true;

}

// From DFPlayer mini example
void printDetail(uint8_t type, int value){
  switch (type) {
    case TimeOut:
      Serial.println(F("Time Out!"));
      break;
    case WrongStack:
      Serial.println(F("Stack Wrong!"));
      break;
    case DFPlayerCardInserted:
      Serial.println(F("Card Inserted!"));
      break;
    case DFPlayerCardRemoved:
      Serial.println(F("Card Removed!"));
      break;
    case DFPlayerCardOnline:
      Serial.println(F("Card Online!"));
      break;
    case DFPlayerPlayFinished:
      Serial.print(F("Number:"));
      Serial.print(value);
      Serial.println(F(" Play Finished!"));
      break;
    case DFPlayerError:
      Serial.print(F("DFPlayerError:"));
      switch (value) {
        case Busy:
          Serial.println(F("Card not found"));
          break;
        case Sleeping:
          Serial.println(F("Sleeping"));
          break;
        case SerialWrongStack:
          Serial.println(F("Get Wrong Stack"));
          break;
        case CheckSumNotMatch:
          Serial.println(F("Check Sum Not Match"));
          break;
        case FileIndexOut:
          Serial.println(F("File Index Out of Bound"));
          break;
        case FileMismatch:
          Serial.println(F("Cannot Find File"));
          break;
        case Advertise:
          Serial.println(F("In Advertise"));
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }
}

// Helper function - set NeoPixel color to provided R, G, B values
void pixelSetColor(int R, int G, int B) {

  for(int i=0; i<NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(R, G, B));
    pixels.show();
  }
}

// Helper function - set atomizers to on and off
void setAtomizers(int atom1, int atom2, int atom3) {
  digitalWrite(atom1Pin, atom1);
  digitalWrite(atom2Pin, atom2);
  digitalWrite(atom3Pin, atom3);  
}

// Helper function - given a state, map the potentiometer value 
// to a set of specific R, G, B values and set the neopixel accordingly
void mapPixelAndSetColor(int state) {

  if(state == 0) {
    pixels.clear();
    return;
  }

  if(state == 1) {
    // SLEEP
    mappedRed = map(potentiometerVal, 0, 1024, 51, 138);
    mappedGreen = map(potentiometerVal, 0, 1024, 51, 0);
    mappedBlue = map(potentiometerVal, 0, 1024, maxRGBValue, 204);
  } else if (state == 2) {
    // FOCUS
    mappedRed = map(potentiometerVal, 0, 1024, 10, 0);
    mappedGreen = map(potentiometerVal, 0, 1024, 255, 153);
    mappedBlue = map(potentiometerVal, 0, 1024, 153, 51);
  } else if (state == 3) {
    // BOOST
    mappedRed = maxRGBValue;
    mappedGreen = map(potentiometerVal, 0, 1024, 133, 0);
    mappedBlue = map(potentiometerVal, 0, 1024, 51, 102);
  }

  pixelSetColor(mappedRed, mappedGreen, mappedBlue);

}

// Helper function - calculate a random number between 0 and 2
// and index into appropriate songs array given the state
// Return the song number 
int getSongNumber(int state) {

  int song = 0;
  int choice = rand() % 3; // get a random number between 0 and 2
  Serial.println("choice is "+ String(choice));
  if(state == 1) {
    // SLEEP
    song = sleepSongs[choice];
  } else if(state == 2) {
    // FOCUS
    song = focusSongs[choice];
  } else if(state == 3){
    // BOOST
    song = boostSongs[choice];
  }
  
  Serial.println("playing song: " + String(song));
  return song;

}




