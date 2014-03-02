FastADC 
========
is a library to be used with Energia IDE. It purposes is to achieve the fastest analog to digital sampling speed.


Functionality
-------------

A chosen channel is continuously sampled and the result is automatically transfered to an user defined buffer (pBuffer) by means of the DTC without generating an interrupt.

The process can be started and stoped at will, but will be halted if pBuffer is written into (see your device's family document).


Installation:
-------------

Copy the FastADC folder inside energia/hardware/msp430/libraries and restart the IDE. 


Usage:
------

The API consists of the initialization parameters and three methods:

- FastADC( channel, divisor ) // where channel follows Energia convention and divisor is a number between 0 and 8

- setBuffer( uint16_t &pBuffer ) // is the buffer where the ADC data will be automatically transfered to


- start() // start the AD


- stop() // stop the AD

