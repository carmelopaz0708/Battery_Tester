/**
 * SINGLE CELL BATTERY TESTER 5V VERSION 2
 * Note: DO NOT TEST BATTERIES HIGHER THAN 5V
 */

// Pin assignments
#define grnLED 2
#define yelLED 4
#define redLED 6

// Global Variables
float resultVoltage = 0;
float voltDisp = 0;

void setup() 
{
  Serial.begin(9600);
  Serial.print("Loading parameters:\n");
  pinMode(grnLED, OUTPUT);
  pinMode(yelLED, OUTPUT);
  pinMode(redLED, OUTPUT);
}

float voltageTest(int analogValue)
{
  float voltage = 0;
  analogValue = analogRead(0);
  voltage = 0.0048 * analogValue;
  
  // Display values to serial monitor
  Serial.print("analogValue: ");
  Serial.print(analogValue);
  Serial.print("\tVoltage: ");
  Serial.print(voltage);
  Serial.print("\n");  
  return voltage;
}

void ledIndicator(float levelLED)
{
  levelLED = voltDisp;
  if (levelLED >= 1.6)
  {
    digitalWrite(grnLED, HIGH);
    digitalWrite(yelLED, LOW);
    digitalWrite(redLED, LOW);
  }
  else if (levelLED < 1.6 && levelLED > 1.3)
  {
    digitalWrite(yelLED, HIGH);
    digitalWrite(grnLED, LOW);
    digitalWrite(redLED, LOW);
  }
  else if (levelLED <= 1.3)
  {
    digitalWrite(redLED, HIGH);
    digitalWrite(grnLED, LOW);
    digitalWrite(yelLED, LOW);
  }
}

void loop() 
{
  voltDisp = voltageTest(resultVoltage);
  ledIndicator(voltDisp);
}
