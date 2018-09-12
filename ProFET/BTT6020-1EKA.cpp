/* Infineon BTT6020-1EKA Interface Library

Developed using the Datasheet at
https://www.infineon.com/dgdl/Infineon-BTT6020-1EKA-DS-v01_01-EN.pdf?fileId=5546d4625a888733015aa390dd8a0fdc

*/
#include "Arduino.h"
#include "BTT6020-1EKA.h"

// Constants
const unsigned char PS_32 = (1 << ADPS2) | (1 << ADPS0);
const unsigned char PS_128 = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

BTT6020_1EKA::BTT6020_1EKA(byte inputChannelPin, byte diagnosticEnablePin, byte sensePin)  : BTT60X0_XEKA(diagnosticEnablePin)
{
    this.inChanPin = inputChannelPin;
    this.isPin = sensePin;
    pinMode(this.inChanPin, OUTPUT);
    pinMode(this.diagPin, OUTPUT);
    pinMode(this.isPin, INPUT);
    this.initADC();
}

BTT6020_1EKA::~BTT6020_1EKA()
{
    // turn off outputs
    digitalWrite(this.inChanPin, LOW);
    digitalWrite(this.diagPin, LOW);
}

int BTT6020_1EKA::getRawSenseValue()
{
    return analogRead(this.isPin);
}

void BTT6020_1EKA::setInputChannelState(ChannelState ctrl)
{
    int ch = ctrl == off ? LOW : HIGH;
    digitalWrite(this.inChanPin, ch);
}
