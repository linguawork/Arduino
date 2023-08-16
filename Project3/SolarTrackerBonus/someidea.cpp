#include <Servo.h>

int currA0 = A0;
int currA1 = A1;
int lightValLeft;
int lightValRight;

Servo myservo;
int pos = 90;

//bonus
int currA2 = A2;
int lightValUpper;
Servo bonusServo;
int bonusPos = 90;

const int numReadings = 5; // Number of readings to average
int readingsLeft[numReadings]; // Array to store readings for left
int readingsRight[numReadings]; // Array to store readings for right
int readingsUpper[numReadings]; // Array to store readings for upper
int readIndex = 0;         // Index for reading arrays
int totalLeft = 0;             // Running total of readings for left
int totalRight = 0;             // Running total of readings for right
int totalUpper = 0;             // Running total of readings for upper
int averageLeft = 0;           // Smoothed average reading for left
int averageRight = 0;           // Smoothed average reading for right
int averageUpper = 0;           // Smoothed average reading for upper

void setup()
{
  pinMode(currA0, INPUT);
  pinMode(currA1, INPUT);
  pinMode(currA2, INPUT);

  Serial.begin(9600);
  myservo.attach(9);
  bonusServo.attach(3);

  // Initialize reading arrays to 0
  for (int i = 0; i < numReadings; i++) {
    readingsLeft[i] = 0;
    readingsRight[i] = 0;
    readingsUpper[i] = 0;
  }
}

// Function to calculate smoothed average
int calculateSmoothedAverage(int* readingsArray, int &total) {
  total -= readingsArray[readIndex];
  readingsArray[readIndex] = analogRead(currA0);
  total += readingsArray[readIndex];
  readIndex = (readIndex + 1) % numReadings;
  return total / numReadings;
}

void loop()
{
  averageLeft = calculateSmoothedAverage(readingsLeft, totalLeft);
  averageRight = calculateSmoothedAverage(readingsRight, totalRight);
  averageUpper = calculateSmoothedAverage(readingsUpper, totalUpper);

  //  existing code for servo movement based on light values

  // bonus
  // the same filtering mechanism for the bonus light reading

  //  existing code for bonus servo movement based on light values
}
