#include <SoftwareSerial.h>  //Allows bluetooth connectivity
#include <Servo.h>           //Allows to control servo motors

Servo frontLeftServo_1;  // Creates servo object to control a servo. After prototyping do this for the other 11 servos
Servo frontRightServo_1;
Servo frontRightServo_2;
Servo frontRightServo_3;
Servo frontLeftServo_2;
Servo frontLeftServo_3;
Servo rearLeftServo_1;
Servo rearLeftServo_2;
Servo rearLeftServo_3;
Servo rearRightServo_1;
Servo rearRightServo_2;
Servo rearRightServo_3;

char input;

const byte rxPin = 2;  // The pin on which to receive serial data
const byte txPin = 3;  // The pin on which to transmit serial data

// Set up a new SoftwareSerial object
SoftwareSerial BTSerial(rxPin, txPin);  // RX TX

void setup() {
  // Defines the modes for TX & RX
  pinMode(rxPin, INPUT);   // Recieving data
  pinMode(txPin, OUTPUT);  // Transmitting data

  frontRightServo_1.attach(4);  // Attaches a servo to a pin. After prototyping do this for the other 11 servos
  frontRightServo_2.attach(5);
  frontRightServo_3.attach(6);
  frontLeftServo_1.attach(7);
  frontLeftServo_2.attach(8);
  frontLeftServo_3.attach(9);
  rearLeftServo_1.attach(10);
  rearLeftServo_2.attach(11);
  rearLeftServo_3.attach(12);
  rearRightServo_1.attach(A0);
  rearRightServo_2.attach(A1);
  rearRightServo_3.attach(A2);


  BTSerial.begin(9600);  // Start bluetooth serial at 9600 bps
  Serial.begin(9600);    // Start serial monitor at 9600 bps

  Serial.println("Setup Completed");  // Confirm setup completion
}

void loop() {
  if (BTSerial.available() > 0) {  // Checks if data is being recieved
    input = BTSerial.read();       // Reads the data being transmitted
    Serial.println(input);
  }

  switch (input) {
    case 'F':  // Foward
      // Move the second servo to 55 degrees
      frontRightServo_2.write(55);
      delay(100);

      // Move the third servo to 115 degrees
      frontRightServo_3.write(145);
      delay(100);

      // Move the first servo to 135 degrees
      frontRightServo_1.write(135);
      delay(100);

      // Set the second and third servos back to 90 degrees
      frontRightServo_3.write(90);
      frontRightServo_2.write(90);
      delay(100);

      // Move the first servo to 35 degrees
      frontRightServo_1.write(35);
      delay(100);


      // Move the second servo to 55 degrees
      rearLeftServo_2.write(55);
      delay(100);

      // Move the third servo to 115 degrees
      rearLeftServo_3.write(115);
      delay(100);

      // Move the first servo to 135 degrees
      rearLeftServo_1.write(15);
      delay(100);

      // Set the second and third servos back to 90 degrees
      rearLeftServo_3.write(90);
      rearLeftServo_2.write(90);
      delay(100);

      // Move the first servo to default
      rearLeftServo_1.write(90);
      delay(100);


      // Move the second servo to 55 degrees
      frontLeftServo_2.write(55);
      delay(100);

      // Move the third servo to 115 degrees
      frontLeftServo_3.write(145);
      delay(100);

      // Move the first servo to 135 degrees
      frontLeftServo_1.write(45);
      delay(100);

      // Set the second and third servos back to 90 degrees
      frontLeftServo_3.write(90);
      frontLeftServo_2.write(90);
      delay(100);

      // Move the first servo to default
      frontLeftServo_1.write(145);
      delay(100);


        // Move the second servo to 55 degrees
        rearRightServo_2.write(55);
        delay(100);

        // Move the third servo to 115 degrees
        rearRightServo_3.write(115);
        delay(100);

        // Move the first servo to 135 degrees
        rearRightServo_1.write(165);
        delay(100);

        // Set the second and third servos back to 90 degrees
        rearRightServo_2.write(90);
        rearRightServo_3.write(90);
        delay(100);

        // Move the first servo to default
      rearRightServo_1.write(90);
        delay(100);

    default:  // If there is no input return default position
      frontRightServo_1.write(90);
      frontRightServo_2.write(90);
      frontRightServo_3.write(90);
      frontLeftServo_1.write(90);
      frontLeftServo_2.write(90);
      frontLeftServo_3.write(90);
      rearLeftServo_1.write(90);
      rearLeftServo_2.write(90);
      rearLeftServo_3.write(90);
      rearRightServo_1.write(90);
      rearRightServo_2.write(90);
      rearRightServo_3.write(90);
  }
}