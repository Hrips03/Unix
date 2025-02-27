#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Listing files in the current directory:\n");
    system("ls -l");  // Create a new directory

    printf("Procceses: \n");
    system("top");  // Change directory and list contents

    return 0;
}
