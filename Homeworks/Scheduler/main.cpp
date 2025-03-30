#include "Scheduler.hpp"
#include "readingFromFile.hpp"
#include <fstream>  
#include <vector>   
#include <string>  
#include <sstream>  

int main() {  
    std::vector<Process> all_processes;
    try
    {
        all_processes = readingProcesses("processes.txt");
    }
    catch(std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
      
    Scheduler EDF_Scheduler;  
    EDF_Scheduler.Schedule(all_processes);  

    return 0;  
}  