#include "FastADC.h"

int Divisor = 0; // 0 to 8
FastADC A(TEMPSENSOR, Divisor);
uint16_t buf, bufout;
void setup()
{
  Serial.begin(9600);
    Serial.println("Starting");
  A.setBuffer(buf);
  // put your setup code here, to run once:
  A.start();
  Serial.println("Starting2");
}

void loop()
{
  // put your main code here, to run repeatedly:
  bufout = buf;
  Serial.println(bufout);


}
