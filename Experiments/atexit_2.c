#include <stdio.h>
#include <stdlib.h>

void first_cleanup(void) {
    printf("First cleanup function called.\n");
}

void second_cleanup(void) {
    printf("Second cleanup function called.\n");
}

void third_cleanup(void) {
    printf("Third cleanup function called.\n");
}

int main() {
    atexit(first_cleanup);
    atexit(second_cleanup);
    atexit(third_cleanup);

    printf("Main function is running...\n");

    return 0; 
}
