/*
  Tests for BTS500010-TAD 
*/
#define BAUD_RATE 115200
//#define LED1 SCL;
#define LED2 9
#define IN 6
#define S2 A0
#define IS A2
#define TP_5V A3
#define VBAT A5
#define TP_COMP 5

enum S2State { up, down };
enum CurrentSense { under, inbounds, over };
enum SwitchState { off, on };

// Constants
const unsigned char PS_32 = (1 << ADPS2) | (1 << ADPS0);
const unsigned char PS_128 = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

// variables:
unsigned int S2CalibrationZero = 0;   
unsigned int ISCalibrationZero = 0;         // the sensor value

unsigned int CurrentSenseHardMin = 0;
unsigned int CurrentSenseHardMax = 1024;
unsigned int CurrentSenseUserMin = 0;
unsigned int CurrentSenseUserMax = 255;

unsigned int TP5VCalibrationZero = 0;
unsigned int VBATCalibrationZero = 0;

void setupSerial() {
  Serial.begin(BAUD_RATE);
  Serial.println("Setup Complete.");
}

void setupOutputs() {
  pinMode(LED2, OUTPUT);
  pinMode(IN, OUTPUT);
}

void setupInputs() {
  // set up the ADC for higherspeed conversion
  ADCSRA &= ~PS_128;
  ADCSRA |= PS_32;

  // S2 is on an Analog input, so needs to be polled as it cannot fire an interrupt.
  pinMode(S2, INPUT);
  digitalWrite(S2, HIGH);
  
  pinMode(IS, INPUT);
  pinMode(TP_5V, INPUT);
  pinMode(VBAT, INPUT);
  pinMode(TP_COMP, INPUT);
}

void calibrateAnalogs() {
  unsigned int sampleCount = 0;
  unsigned int S2RawValue = 0;
  unsigned int ISRawValue = 0;
  unsigned int TP5VRawValue = 0;
  unsigned int VBATRawValue = 0;
  
  // calibrate analog inputs during the first five seconds
  while (millis() < 5000) {
    S2RawValue += analogRead(S2);
    ISRawValue += analogRead(IS);
    TP5VRawValue += analogRead(TP_5V);
    VBATRawValue += analogRead(VBAT);
    sampleCount++;
  }
  S2CalibrationZero = S2RawValue / sampleCount;
  ISCalibrationZero = ISRawValue / sampleCount;
  TP5VCalibrationZero = TP5VRawValue / sampleCount;
  VBATCalibrationZero = VBATRawValue / sampleCount;
}

S2State getS2State() {
  return digitalRead(S2) ? up : down;
}

void 

void setup() {
  setupOutputs();
  setupInputs();
  
  digitalWrite(LED2, HIGH);
  calibrateAnalogs();  
  digitalWrite(LED2, LOW);

  setupSerial();
}



void loop() {
  #if 1
  //char a = digitalRead(S2) ? 'u' : 'd';
  //Serial.write(a);
  
  Serial.write('0');
  Serial.write('=');
  Serial.print((unsigned int)ISCalibrationZero);
  Serial.write(':');
  Serial.print(digitalRead(S2));
  Serial.println();
  #endif
  
  /*
  // read the sensor:
  sensorValue = analogRead(sensorPin);

  // apply the calibration to the sensor reading
  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);

  // in case the sensor value is outside the range seen during calibration
  sensorValue = constrain(sensorValue, 0, 255);

  // fade the LED using the calibrated value:
  analogWrite(ledPin, sensorValue);
  */
}
