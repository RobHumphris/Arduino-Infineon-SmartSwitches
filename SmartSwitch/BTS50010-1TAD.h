#ifndef BTS50010_1TAD
#define BTS50010_1TAD

#include "Arduino.h"

class BTS50010_1TAD 
{
    public:
        BTS50010_1TAD(byte inputChannelPin, byte sensePin);
        ~BTS50010_1TAD();

        int getRawSenseValue();
        void setInputChannelState(ChannelState ctrl);
    private:
        int inChanPin;
        byte isPin;
};

#endif //BTS50010_1TAD