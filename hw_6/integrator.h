#ifndef INTEGRATOR_H
#define INTEGRATOR_H

#include <iostream>
#include "elma/elma.h"

using namespace std;
using namespace elma;

/*Class Integrator: A process that numerically integrates whatever values it reads from a channel called link. 
The integrator should have an initial value equal to zero. When it reads a value v from the link channel, 
it should add delta() * v to the integrated value (presumably a private variable).*/
class Integrator : public Process {
public:
    Integrator(std::string name) : Process(name), integral(0), count(0) {}

    void init() {}
    void start() {}
    void update() {
        for (double v : channel("link").latest()) {
            integral += delta() * v; //integral calculation
            count++;
        }
    }
    void stop() {}

    double value() const { return integral; } //returns the current integral
    double delta() const { return 0.01; } //returns the delta

private:
    double integral;
    int count;
};

/*Class Source: A process to generate a constant value*/
class Source : public Process {
public:
    Source(std::string name, double value) : Process(name), _value(value) {}

    void init() {}
    void start() {}
    void update() {
        channel("link").send(_value); //send the value to channel
    }
    void stop() {}

    double value() const { return _value; } //returns the constant integral

private:
    double _value;
};
#endif