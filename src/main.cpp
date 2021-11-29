#include <Arduino.h>
#define CARRIAGE_RETURN 0x0D
char gs3Data[25];

#define HW_UART_TX D1
#define HW_UART_RX D0

HardwareSerial SerialAT(HW_UART_RX, HW_UART_TX);

void readGS3() {

  while (SerialAT.available() == 0) {} // wait for sensor to provide data

  char value = SerialAT.read();
  int index = 0;
  Serial.print(value);
  // while (value != CARRIAGE_RETURN) { // bail out as we now have all our data since <CR> has been detected
  //   gs3Data[index] = value;
  //   Serial.print(value);

  //   index++;
  //   while (SerialAT.available() == 0) {}; // wait for more data to come in from the sensor until <CR> is detected
  //   value = SerialAT.read();
  // }
  // Serial.println("");
}

void setup() {
  // put your setup code here, to run once:
  SerialAT.begin(1200);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println("test");
  readGS3();
  delay(3000);
}