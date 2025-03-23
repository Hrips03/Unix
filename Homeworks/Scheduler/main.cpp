#include "Scheduler.hpp"

int main()
{
    std::vector<Process> all_processes;

    all_processes.push_back(Process(1, 3, 7, 1)); 
    all_processes.push_back(Process(2, 2, 4, 2)); 
    all_processes.push_back(Process(3, 1, 5, 3)); 

    Scheduler EDF_Scheduler;
    EDF_Scheduler.Schedule(all_processes);

    return 0;
}