#include "Process.hpp"
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

std::vector<Process> readingProcesses(const std::string& filename)
{
    std::vector<Process> all_processes;
    std::ifstream input_file(filename);
    if (!input_file.is_open())
    {
        std::cerr << "Error opening input file!" << std::endl;
        throw std::runtime_error("File not found: " + filename); 
    }

    std::string line;
    while (std::getline(input_file, line))
    {
        if (line.find("Process:") != std::string::npos)
        {
            size_t id, arrival, burst, deadline;

            size_t at_pos = line.find("arrival time = ");
            size_t bt_pos = line.find("burst_time = ");
            size_t dl_pos = line.find("deadline = ");
            size_t id_pos = line.find("id = ");

            if (at_pos != std::string::npos && bt_pos != std::string::npos &&
                dl_pos != std::string::npos && id_pos != std::string::npos)
            {

                arrival = std::stoi(line.substr(at_pos + 15));
                burst = std::stoi(line.substr(bt_pos + 13));
                deadline = std::stoi(line.substr(dl_pos + 11));
                id = std::stoi(line.substr(id_pos + 5));

                all_processes.push_back(Process(arrival, burst, deadline, id));
            }
        }
    }

    input_file.close();
    return all_processes;
}