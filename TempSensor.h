#ifndef MBED_TEMPSENSOR_H
#define MBED_TEMPSENSOR_H
#include "mbed.h"

class TempSensor{
    public:
        TempSensor(PinName pin);
        void readTemperature();
    private:
        AnalogIn _pin;
};

#endif