#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include "Process.hpp"
#include <unistd.h>

class Scheduler
{
public:
    void Schedule(const std::vector<Process> &all_processes);
};