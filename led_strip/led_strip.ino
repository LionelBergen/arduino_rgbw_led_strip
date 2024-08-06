const int GREEN_LED_PIN = A3;
const int RED_LED_PIN = 9;
const int BLUE_LED_PIN = 10;
const int WHITE_LED_PIN = 11;

const int COLOURS[] = { 
  RED_LED_PIN,
  BLUE_LED_PIN,
  GREEN_LED_PIN
};

const int array_size = 3; //sizeof(COLOURS) / sizeof(COLOURS[0]);
const int FADE_DELAY = 5;

void turnOffOtherColours(int otherColour) {
  for (int i=0; i<array_size; i++) {
    if (COLOURS[i] != otherColour) {
      analogWrite(COLOURS[i], 0);
    }
  }
}

void fadeColourRight(int colour) {
  for (int i = 0; i < 256; i++) {
    analogWrite(colour, i);
    delay(FADE_DELAY);
  }
}

void fadeColourLeft(int colour) {
  for (int i = 255; i > 0; i--) {
    analogWrite(colour, i);
    delay(FADE_DELAY);
  }
}

void setup() {
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
  pinMode(WHITE_LED_PIN, OUTPUT);

  turnOffOtherColours(WHITE_LED_PIN);
  analogWrite(WHITE_LED_PIN, 255);
}

void loop() {
  // fade from blue to violet
  fadeColourRight(RED_LED_PIN);

  // fade from violet to red
  fadeColourLeft(BLUE_LED_PIN);

  // fade from red to yellow
  fadeColourRight(GREEN_LED_PIN);

  // fade from yellow to green
  fadeColourLeft(RED_LED_PIN);
  
  // fade from green to teal
  fadeColourRight(BLUE_LED_PIN);
  
  // fade from teal to blue
  fadeColourLeft(GREEN_LED_PIN);
}
