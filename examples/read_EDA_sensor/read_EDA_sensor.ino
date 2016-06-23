#include <EDA.h>

// Reading EDA Sensor
// 2016 Noura Howell <http://nourahowell.com>

// Demostrates how to read sensor values and detect spikes

// the pin the EDA sensor is plugged into
#define edaSensorPin A7

EDA myEDA;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int edaVal = analogRead(edaSensorPin);
  myEDA.update(edaVal);
  // NOTE: myEDA.update already includes a delay which is calculated to be
  // the correct duration for the sample period for the filter it uses
  // interally. so, don't include other calls to delay() when using EDA,
  // or the EDA filter may not work properly
  
  Serial.print(edaVal);Serial.print(",");
  if ( myEDA.hasPeak() ) {
    Serial.print("MARK");Serial.print(","); 
  }
}

