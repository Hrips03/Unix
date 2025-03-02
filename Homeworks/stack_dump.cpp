#include <iostream>
#include <execinfo.h>
#include <cxxabi.h>
#include <cstring>

std::string demangle(char *string)
{
    std::string mangledName = "";
    size_t len = 0;
    bool capture = false;
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == '(')
        {
            capture = true;
            continue;
        }
        if (string[i] == '+')
            break;

        if (capture)
            mangledName += string[i];
    }

    int status;
    char *demangled = abi::__cxa_demangle(mangledName.c_str(), nullptr, nullptr, &status);

    if (status == 0)
    {
        std::string result = demangled;
        free(demangled);
        return result;
    }

    return mangledName;
}

void myfunc(std::ostream &out)
{
    int j, nptrs;
    #define SIZE 100
    void *buffer[100];
    char **strings;

    nptrs = backtrace(buffer, SIZE);
    out << "backtrace() returned " << nptrs << " addresses\n\n";

    strings = backtrace_symbols(buffer, nptrs);
    if (strings == NULL)
    {
        perror("backtrace_symbols");
        exit(EXIT_FAILURE);
    }
    std::string res = "";
    for (j = 0; j < nptrs; j++)
    {
        if ((res = demangle(strings[j])) != "main")
            out << res << "\n";
        else
        {
            out << "main(int argc, char *argv[])" << "\n";
            break;
        }
    }

    free(strings);
}

void stack_dump(int depth, std::ostream &)
{
    if (depth > 1)
        stack_dump(depth - 1, std::cout);
    else
        myfunc(std::cout);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << argv[0] << " num-calls\n";
        exit(EXIT_FAILURE);
    }

    stack_dump(atoi(argv[1]), std::cout);
    exit(EXIT_SUCCESS);
}