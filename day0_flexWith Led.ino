// Define the pin connected to the flex sensor (ADC-capable pin on ESP32)
const int flexPin = 34;   // GPIO 34 is input-only and supports analogRead

// Define the pin connected to the LED
const int ledPin = 23;    // GPIO 23 is a general-purpose output pin

void setup() {
  // Initialize serial communication for debugging (use 115200 for ESP32)
  Serial.begin(115200);

  // Set the LED pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read the analog value from the flex sensor
  int flexValue = analogRead(flexPin);

  // Print the sensor value to the Serial Monitor
  Serial.print("sensor: ");
  Serial.println(flexValue);

  // If the flex sensor value is greater than 3600, turn on the LED
  if (flexValue > 3600) {
    digitalWrite(ledPin, HIGH);  // Turn LED ON
  } else {
    digitalWrite(ledPin, LOW);   // Turn LED OFF
  }

  // Small delay to avoid flooding the serial monitor
  delay(20);
}







//for 2 led


// Flex sensor 1 (connected to ADC-capable pin)
const int flexPin1 = 34;   // GPIO 34 - input only
// Flex sensor 2
const int flexPin2 = 35;   // GPIO 35 - input only

// LEDs
const int ledPin1 = 23;    // GPIO 23 - output
const int ledPin2 = 22;    // GPIO 22 - output

// Thresholds (can be calibrated)
const int flexThreshold1 = 3600;
const int flexThreshold2 = 3600;

void setup() {
  Serial.begin(115200);

  // Set LED pins as output
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  // Read both flex sensors
  int flexValue1 = analogRead(flexPin1);
  int flexValue2 = analogRead(flexPin2);

  // Print values to serial monitor
  Serial.print("Flex1: ");
  Serial.print(flexValue1);
  Serial.print(" | Flex2: ");
  Serial.println(flexValue2);

  // Control LED1
  if (flexValue1 > flexThreshold1) {
    digitalWrite(ledPin1, HIGH);
  } else {
    digitalWrite(ledPin1, LOW);
  }

  // Control LED2
  if (flexValue2 > flexThreshold2) {
    digitalWrite(ledPin2, HIGH);
  } else {
    digitalWrite(ledPin2, LOW);
  }

  delay(20);  // Small delay
}









const int flexPin = A0; 
const int ledPin = 23; 

void setup() { 
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
} 

void loop(){ 
  int flexValue;
  flexValue = analogRead(flexPin);
  Serial.print("sensor: ");
  Serial.println(flexValue);
 
  if(flexValue>3600)
     digitalWrite(ledPin,HIGH);
  else
    digitalWrite(ledPin,LOW);
 
  delay(20);
} 
