#include "TempSensor.h"
#include "mbed.h"

TempSensor::TempSensor(PinName pin) : _pin(pin){
    _pin = 0;
}

void TempSensor::readTemperature(){
    float thermR=NULL;
            float rawTemp=NULL;
            float tempK=NULL;

            rawTemp = temp_sensor.read_u16();
            printf ("Raw temp = %f\n", rawTemp);

            thermR = R*((ADCRES/rawTemp)-1);
            printf ("Thermistor Resistance = %f\n", thermR);

            tempK = 1/(log(thermR/R)/BETA+(1.0/T0));
            printf("Temperature in kelvin: %f\n, tempK");
            
            printf("Temperature in Celcius: %f\n\n",(tempK - K));
}