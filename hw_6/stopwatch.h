#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <iostream>
#include <chrono>
#include <condition_variable>
#include <mutex>

class Stopwatch {
private:
    std::chrono::steady_clock::time_point start_time_; //variable for storing the start time
    std::chrono::steady_clock::time_point end_time_;  //variable for storing the end time
    std::chrono::duration<double> elapsed_time_;  //variable for storing the elapsed time

/****************Function declarations & definitions***********************/
public:
    Stopwatch() : elapsed_time_(0) {}
    /*Function to start the timer*/
    void start() {
        start_time_ = std::chrono::steady_clock::now(); //setting the start time
    }
    /*Function to stop the timer*/
    void stop() {
        end_time_ = std::chrono::steady_clock::now(); //setting the end time
        elapsed_time_ += std::chrono::duration_cast<std::chrono::duration<double>>(end_time_ - start_time_); //elasped time calculation
    }
    /*Function to set stopwatch to zero*/
    void reset() {
        elapsed_time_ = std::chrono::duration<double>(0); //setting elapsed time to 0
    }
    /*Function to count number of minutes, as a double*/
    double get_minutes() {
        return (double)std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time_).count()/(1000.0*1000.0*1000.0*60.0);
    }
    /*Function to count number of seconds, as a double*/
    double get_seconds() {
        return (double)std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time_).count()/(1000.0*1000.0*1000.0);
    }
    /*Function to count number of milliseconds, as a double*/
    double get_milliseconds() {
        return (double)std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time_).count()/(1000.0*1000.0);
    }
    /*Function to count number of nanoseconds, as a double*/
    double get_nanoseconds() {
        return (double)std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time_).count();
    }
};

#endif