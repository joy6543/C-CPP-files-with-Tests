#ifndef FILTER_H
#define FILTER_H

#include <iostream>
#include <elma/elma.h>
#include "random_process.h"

using namespace std;
using namespace elma;

/*Class Filter: reads from the link channel, and keeps a running average (presumably in a private variable)
of the last 10 numbers sent to it (if 10 numbers have not yet been received, the running average should be
of the numbers received so far). Initialize the running average to 0.*/
class Filter : public Process {
  private:
    vector<double> buffer; //variable for storing last 10 values
    double running_avg; //variable for storing running average of last 10 values
    int count; //variable for storing current count of values

  public:
    Filter(string name) : Process(name), buffer(10, 0), running_avg(0), count(0) {}

    void init() {}
    void start() {}
    void update() {
        double value = channel("link").latest(); //reads latest value from channel
        if(value==0) return; 
        buffer[9 - (count % 10)] = value; //adds value to the buffer
        count++;
        int n = min(count, 10); //number of values for calculating running average
        running_avg = accumulate(buffer.end() - n, buffer.end(), 0.0) / n; //running average calculation
    }
    void stop() {}

    /*Function value: Returns the current running average*/
    double value() {
        return running_avg; 
    }
};

#endif