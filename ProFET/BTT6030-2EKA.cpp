#include "BTT6030-2EKA.h"

BTT6030_2EKA::BTT6030_2EKA(byte input0ChannelPin, byte input1ChannelPin, byte diagnosticEnablePin, byte dignosticSelectPin, byte sensePin)
{
    this.inChan0Pin = input0ChannelPin;
    this.inChan1Pin = input1ChannelPin;
    this.diagPin = diagnosticEnablePin;
    this.diagSelPin = dignosticSelectPin;
    this.isPin = sensePin;
    pinMode(this.inChan0Pin, OUTPUT);
    pinMode(this.inChan1Pin, OUTPUT);
    pinMode(this.diagPin, OUTPUT);
    pinMode(this.diagSelPin, OUTPUT);
    pinMode(this.isPin, INPUT);
}

BTT6030_2EKA::~BTT6030_2EKA()
{
    // turn off all the 
    digitalWrite(this.inChan0Pin, LOW);
    digitalWrite(this.inChan1Pin, LOW);
    digitalWrite(this.diagPin, LOW);
}

int BTT6030_2EKA::getRawSenseValue()
{

}

int BTT6030_2EKA::getInput0ChannleSenseValue()
{

}

int BTT6030_2EKA::getInput1ChannleSenseValue()
{

}

void BTT6030_2EKA::setInput0ChannelState(ChannelState ctrl)
{

}

void BTT6030_2EKA::setInput1ChannelState(ChannelState ctrl)
{

}
