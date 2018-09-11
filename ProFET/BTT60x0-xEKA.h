#ifndef BTT60X0_XEKA
#define BTT60X0_XEKA

#include "Arduino.h"

class BTT60X0_XEKA 
{
    public:
        enum ChannelState { off, on };
        BTT60X0_XEKA(byte diagnosticEnablePin);
        ~BTT60X0_XEKA();

        void enableDiagnostic();
        void disableDiagnostic();

    protected:
        void initADC();
        byte diagPin;
};

#endif