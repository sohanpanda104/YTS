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
