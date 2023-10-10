#include "mbed.h"
#include "ThisThread.h"

#define ADCres 65535.0

// main() runs in its own thread in the OS

AnalogIn temp_sensor (A0);

int main()
{
    float thermR=NULL;
    float rawTemp=NULL;
    float tempK=NULL;
    float tempC=NULL;
    while(true){
        rawTemp = temp_sensor.read_u16();
        printf ("Raw temp = %f\n", rawTemp);

        thermR = 100000*((65535.0/rawTemp)-1);
        printf ("Thermistor Resistance = %f\n", thermR);

        tempK = 1/(log(thermR/100000.0)/4250+(1.0/298.15));
        
        tempC = tempK - 273.15;
        printf("Temperature in kelvin: %f\nTemperature in Celcius: %f\n\n", tempK, tempC);

        ThisThread::sleep_for(1000ms);
    }
    
}

