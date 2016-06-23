/*
   Test.h - Test library for Wiring - implementation
   Copyright (c) 2006 John Doe.  All right reserved.
   */

#include "EDA.h"
#include "HardwareSerial.h"

EDA::EDA(void)
{
    samplePeriod = 1000 / EDA_H_SAMPLERATE;
}

void EDA::update(int _sensorRaw)
{
    int N = EDA_H_N;
    sensorRaw = _sensorRaw;
    sensorRaw = min(sensorRaw, 1023);
    sensorRaw = max(sensorRaw, 0);
    sensorFilteredNew = myFilter.step(sensorRaw);
    // index 0 holds the most recent value
    // index N-1 holds the oldest value
    for (int i = N - 1; i >= 1; i--) {
        sensorFiltered[i] = sensorFiltered[i-1];
    }
    sensorFiltered[0] = sensorFilteredNew;

    // wait this much time to make sure we regularly sample the EDA sensor
    // (depends on our filter)
    delay(samplePeriod);
}

bool EDA::hasPeak(void)
{
    int N = EDA_H_N;

    // ignore initial peak due to initialization
    if ( millis() < 1000 ) {
        return false;
    }    

    // calculate the average
    float avg = 0;
    for (int i = 0; i < N; i++) {
        avg += sensorFiltered[i];
    }
    avg /= N;

    // calculate the standard deviation
    float std = 0;
    for (int i = 0; i < N; i++) {
        std += pow(sensorFiltered[i] - avg, 2);
    }
    std = sqrt(std / N);

    // if the current value is more than a standard deviation above the mean,
    // then that counts as a peak. also make sure that the current value is
    // more than 25 above the mean, in case there is just some noise in a
    // pretty flat signal
    if (sensorFiltered[0] - avg > std
            &&
            sensorFiltered[0] - avg > 50 ) {
        return true;
    } else {
        return false;
    }
}
