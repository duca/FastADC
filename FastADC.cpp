/*
  FastADC.cpp - Library for Fast ADC converts (currently only supporting msp430 with DTC).
  Created by Eduardo M. Lopes, February 28, 2014.
  Released into the public domain.
*/
#include "FastADC.h"

#if defined(__MSP430_HAS_ADC10__) && !defined(ADC10ENC)
#define ADC10ENC ENC 
#endif
#if defined(__MSP430_HAS_ADC10__)
#define ADCxMEM0 ADC10MEM 
#endif
#if defined(__MSP430_HAS_ADC10_A__)
#define ADCxMEM0 ADC10MEM 
#endif
#if defined(__MSP430_HAS_ADC10_B__)
#define REFV_MASK 0x70
#define REF_MASK 0x31
#define ADCxMEM0 ADC10MEM0 
#endif
#if defined(__MSP430_HAS_ADC12_PLUS__)
#define REFV_MASK 0x0070
#define REF_MASK 0xB1
#define ADCxMEM0 ADC12MEM0 
#endif


FastADC::FastADC(const int pin,const unsigned int div){

  ADC10CTL0 &= ~ADC10ENC;            // DISABLE ADC

  ADC10CTL0 = ADC10SHT_0;  // 4 SAMPLES
  ADC10CTL0 &=~ADC10IE;              // no need for Interrupt
  ADC10CTL0 &=~ADC10SR;                // up to 200ksps
  ADC10CTL0 |= SREF_0 + MSC + REFON;
  ADC10CTL1 = ADC10SSEL_0;           // ADC10OSC as ADC10CLK (~5MHz)
  ADC10CTL1 |= (pin << 12);        // select channel
  ADC10CTL1 |= (div << 5);           // select divider
  ADC10CTL1 |= CONSEQ_2;             // Repeated single channel mode  
  ADC10DTC1 = 0x001;                 // 1 CONVERSION
  ADC10DTC0 &=~ADC10TB;              // 1 transfer block  
  ADC10DTC0 |=ADC10CT;              // 1 transfer block

  ADC10AE0 = (1 << pin);           // Disable input/output buffer 


}

FastADC::~FastADC(){
  stop();
}


void FastADC::setBuffer(uint16_t &pBuffer){
  ADC10SA = (unsigned int)&pBuffer;
  
}
void FastADC::stop(){
     ADC10CTL0 &= ~ADC10ENC;            // DISABLE ADC
     ADC10CTL0 &=~ENC;
     ADC10CTL0 &=~ADC10SC;             // Stop sampling
}

void FastADC::start(){
     ADC10CTL0 |= ENC + ADC10ON;             
     ADC10CTL0 |= ADC10ENC + ADC10SC;            // DISABLE ADC

}

