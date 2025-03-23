#include "Process.hpp"

Process::Process(size_t arrival, size_t burst, size_t dline, size_t id)
    : arrival_time(arrival), burst_time(burst), deadline(dline), pid(id), remaining_time(burst) {}

bool Process::operator>(const Process &other) const
{
    return deadline > other.deadline;
}

size_t Process::getpid() const
{
    return pid;
}

size_t Process::get_arrival_time() const
{
    return arrival_time;
}

size_t Process::get_deadline() const
{
    return deadline;
}

size_t Process::get_burst_time() const
{
    return burst_time;
}

size_t Process::get_remaining_time() const
{
    return remaining_time;
}

void Process::reduce_remaining_time(size_t time)
{
    remaining_time -= time;
}
