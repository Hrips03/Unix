#include "Scheduler.hpp"

void Scheduler::Schedule(const std::vector<Process> &all_processes)
{
    std::cout << "EDF Execution Order:\n";

    size_t current_time = 0;
    std::priority_queue<Process, std::vector<Process>, std::greater<Process>> process_queue;

    size_t i = 0;
    std::unique_ptr<Process> current_process = nullptr;

    while (i < all_processes.size() || !process_queue.empty() || current_process)
    {
        while (i < all_processes.size() && all_processes[i].get_arrival_time() <= current_time)
        {
            Process arriving_process = all_processes[i];
            std::cout << "At time " << current_time << ": Process " << arriving_process.getpid() << " arrived with arrival_time = "
                      << arriving_process.get_arrival_time() << ", burst_time = " << arriving_process.get_burst_time()
                      << ", deadline = " << arriving_process.get_deadline() << "\n";
            process_queue.push(arriving_process);
            i++;
        }

        if (current_process)
        {
            if (!process_queue.empty() && process_queue.top().get_deadline() < current_process->get_deadline())
            {
                std::cout << "At time " << current_time << ": Process " << current_process->getpid() << " preempted by Process " << process_queue.top().getpid() << "\n";
                process_queue.push(*current_process);
                current_process = nullptr;
            }
        }

        if (!current_process && !process_queue.empty())
        {
            current_process = std::make_unique<Process>(process_queue.top());
            process_queue.pop();
            std::cout << "At time " << current_time << ": Process " << current_process->getpid() << " is being executed\n";
        }

        if (current_process)
        {
            size_t execution_time = 1;
            current_process->reduce_remaining_time(execution_time);
            current_time += execution_time;

            if (current_process->get_remaining_time() == 0)
            {
                std::cout << "At time " << current_time << ": Process " << current_process->getpid() << " finished execution\n";
                current_process = nullptr;
            }
        }

        if (!current_process && process_queue.empty())
            current_time++;

        usleep(1000000);
    }
    while (!process_queue.empty()) {
        process_queue.pop();
    }
    
}