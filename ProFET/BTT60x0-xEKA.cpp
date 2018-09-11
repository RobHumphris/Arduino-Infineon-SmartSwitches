#include "BTT60x0-xEKA.h"

BTT60X0_XEKA::BTT60X0_XEKA(byte diagnosticEnablePin)
{
    this.diagPin = diagnosticEnablePin;
}

BTT60X0_XEKA::BTT60X0_XEKA()
{

}

void BTT60X0_XEKA::initADC()
{
    // set up the ADC for higherspeed conversion
    ADCSRA &= ~PS_128;
    ADCSRA |= PS_32;
}

void BTT60X0_XEKA::enableDiagnostic()
{
    digitalWrite(this.diagPin, HIGH);
}

void BTT60X0_XEKA::disableDiagnostic()
{
    digitalWrite(this.diagPin, LOW);
}