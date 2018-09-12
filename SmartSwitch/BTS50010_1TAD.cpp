#include "Arduino.h"
#include "BTS50010_1TAD.h"

const unsigned char PS_32 = (1 << ADPS2) | (1 << ADPS0);
const unsigned char PS_128 = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

BTS50010_1TAD::BTS50010_1TAD(byte inputChannelPin, byte sensePin)
{
    this.inChanPin = inputChannelPin;
    this.isPin = sensePin;
    pinMode(this.inChanPin, OUTPUT);
    pinMode(this.isPin, INPUT);
    // set up the ADC for higherspeed conversion
    ADCSRA &= ~PS_128;
    ADCSRA |= PS_32;
}

BTS50010_1TAD::~BTS50010_1TAD()
{
    // turn off output
    digitalWrite(this.inChanPin, LOW);
}

int BTS50010_1TAD::getRawSenseValue()
{
    return analogRead(this.isPin);
}

void BTS50010_1TAD::setInputChannelState(ChannelState ctrl)
{
    int ch = ctrl == off ? LOW : HIGH;
    digitalWrite(this.inChanPin, ch);
}
