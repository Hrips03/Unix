#include <stdio.h>
#include <stdlib.h> // Required for system()

int main()
{
    printf("Listing files in the current directory:\n");

    // Execute the 'ls' command on Linux/macOS or 'dir' on Windows
#ifdef _WIN32
    system("dir");
#else
    system("ls -l");
#endif

    return 0;
}
