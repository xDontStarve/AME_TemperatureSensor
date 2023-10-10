#include "mbed.h"
#include "ThisThread.h"

#define ADCRES 65535.0
#define R 100000.0
#define BETA 4250
#define K 273.15
#define T0 298.15

// main() runs in its own thread in the OS

AnalogIn temp_sensor (A0);

float readTemperature(){
    float thermR=NULL;
    float rawTemp=NULL;
    float tempK=NULL;

    rawTemp = temp_sensor.read_u16();
    printf ("Raw temp = %f\n", rawTemp);

    thermR = R*((ADCRES/rawTemp)-1);
    printf ("Thermistor Resistance = %f\n", thermR);

    tempK = 1/(log(thermR/R)/BETA+(1.0/T0));
    printf("Temperature in kelvin: %f\n, tempK");
    
    return (tempK - K);

}

int main()
{
    while(true){
        printf("Temperature in Celcius: %f\n\n",readTemperature());
        ThisThread::sleep_for(1000ms);
    }
}