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
    FastADC(const int& pin,const uint16_t& div);
    FastADC(const int& nPins,  const unsigned int& div);
    void initDefault();
    ~FastADC();
    void setBuffer(uint16_t &pBuffer);
    void stop();
    void start();
};

#endif // FAST_ADC_H
