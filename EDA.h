/*
   EDA.h - for reading and detecting spikes in Bitalino EDA sensor
   2016 Noura Howell
   https://github.com/Noura/simple-spike-detection
   */

#ifndef EDA_h
#define EDA_h

#include <Arduino.h>

// the number of previous filtered EDA readings to store
#define EDA_H_N 100

// the sample rate of taking EDA readings in Hz
#define EDA_H_SAMPLERATE 20

// You should think about the sample rate and N carefully.
// For example if the sample rate is 20 and N is 100, then we are storing
// the previous 100 / 20 = 5 seconds worth of data. This is the time scale 
// over which we will take the average and standard deviation, which are used
// for spike detection.

class filter
{
    public:
        filter()
        {
            v[0]=0.0;
        }
    private:
        float v[2];
    public:
        float step(float x) //class II 
        {
            v[0] = v[1];
            v[1] = (5.919070381841e-2 * x)
                + (  0.8816185924 * v[0]);
            return (v[0] + v[1]);
        }
};

class EDA
{
    public:
        EDA(void);
        void init(int);
        void update(int);
        bool hasPeak(void);

    private:
        // the pin the EDA sensor is plugged into
        filter myFilter;
        int sensorRaw;
        int sensorFilteredNew;
        int sensorFiltered[EDA_H_N];
        int samplePeriod;
};

#endif

