/*
  FastADC.h - Library for Fast ADC converts (currently only supporting msp430 with DTC).
  Created by Eduardo M. Lopes, February 28, 2014.
  Released into the public domain.
*/
#ifndef FAST_ADC_H
#define FAST_ADC_H

#include "Energia.h"
#include "wiring_private.h"
#include "pins_energia.h"

class FastADC
{
  public:
    FastADC(const int pin,const unsigned int div);
    ~FastADC();
    void setBuffer(uint16_t &pBuffer);
    void stop();
    void start();
    void setAnalogReference(uint16_t reference);

 private:
  int m_pin, m_analogRef;

};

#endif // FAST_ADC_H
