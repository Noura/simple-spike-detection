This is designed to make it simple to detect spikes in a Bitalino EDA Sensor.
2016 Noura Howell

Usage Notes
--------------------------------------------------------------------------------
Do not use any calls to delay() when using this library. This library uses a filter internally and relies on getting updates at regular intervals, so every time it is updated it calls delay internally. Additional calls to delay() may cause the filter to become inaccurate. I know this is very finicky of a library and would welcome any suggestions to fix this. 

Installation
--------------------------------------------------------------------------------

To install this library, just place this entire folder as a subfolder in the directory where your Arduino sketches are stored by default. Probably something like ~/Documents/Arduino/libraries 

When installed, this library should look like:

libraries/EDA              (this library's folder)
libraries/EDA/EDA.cpp      (the library implementation file)
libraries/EDA/EDA.h        (the library description file)
libraries/EDA/examples     (the examples in the "open" menu)
libraries/EDA/readme.txt   (this file)

Building
--------------------------------------------------------------------------------

After this library is installed, you just have to start the Arduino application.
You may see a few warning messages as it's built.

To use this library in a sketch, go to the Sketch | Import Library menu and
select EDA.  This will add a corresponding line to the top of your sketch:
#include <EDA.h>

To stop using this library, delete that line from your sketch.

