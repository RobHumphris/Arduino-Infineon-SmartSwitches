/* Infineon BTT6020-1EKA Interface Library

Developed using the Datasheet at:
https://www.infineon.com/dgdl/Infineon-BTT6030-2EKA-DS-v01_01-EN.pdf?fileId=5546d4625a888733015aa387a48c0fd8

Author: Rob Humphris
Version: 0.1
*/

#ifndef BTT6030_1EKA
#define BTT6030_2EKA

#include "Arduino.h"

class BTT6030_2EKA
{
    public:
        BTT6030_2EKA(byte input0ChannelPin, byte input1ChannelPin, byte diagnosticEnablePin, byte dignosticSelectPin, byte sensePin);
        ~BTT6030_2EKA();

        int getInput0ChannleSenseValue();
        int getInput1ChannleSenseValue();

        void setInput0ChannelState(ChannelState ctrl);
        void setInput1ChannelState(ChannelState ctrl);

    private: 
        int lastSenseADCRaw = -1;
        byte inChan0Pin;
        byte inChan1Pin;
        
        byte diagSelPin;
        byte isPin;
};

#endif