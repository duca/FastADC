FastADC is an Energia IDE library intended to sample a single ad channel as fast as the MSP430G2xxx family can. 

In the future it will support the other chips supported by Energia.

===
Installation:
===

Copy the FastADC folder inside energia/hardware/msp430/libraries and restart the IDE. 


===
Usage:
===

The API consists of the initialization parameters and three methods:

FastADC( channel, divisor ) // where channel follows Energia convention and divisor is a number between 0 and 8)

setBuffer( uint16_t &pBuffer ) // is the buffer where the ADC data will be automatically transfered to
start() // start the AD
stop() // stop the AD

