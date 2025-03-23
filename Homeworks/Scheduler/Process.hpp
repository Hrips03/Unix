#pragma once
#include <iostream>


class Process
{
public:
    Process(size_t arrival, size_t burst, size_t dline, size_t id);
    bool operator>(const Process &other) const;
    size_t getpid() const;
    size_t get_arrival_time() const;
    size_t get_deadline() const;
    size_t get_burst_time() const;
    size_t get_remaining_time() const;
    void reduce_remaining_time(size_t time);
private:
    size_t arrival_time;
    size_t burst_time;
    size_t deadline;
    size_t pid;
    size_t remaining_time; 
};
