/* Infineon BTT6020-1EKA Interface Library

Developed using the Datasheet at
https://www.infineon.com/dgdl/Infineon-BTT6020-1EKA-DS-v01_01-EN.pdf?fileId=5546d4625a888733015aa390dd8a0fdc

Author: Rob Humphris
Version: 0.1
*/

#ifndef BTT6020_1EKA
#define BTT6020_1EKA

#include "Arduino.h"
#include "BTT60x0-xEKA.h"

class BTT6020_1EKA : public BTT60X0_XEKA
{
    public:
        BTT6020_1EKA(byte inputChannelPin, byte diagnosticEnablePin, byte sensePin);
        ~BTT6020_1EKA();

        int getRawSenseValue();

        void setInputChannelState(ChannelState ctrl);

    private: 
        int lastSenseADCRaw = -1;
        byte inChanPin;
        byte diagPin;
        byte isPin;
};


#endif