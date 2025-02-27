#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
    uid_t ruid, euid, suid;

    // Get initial IDs
    getresuid(&ruid, &euid, &suid);
    printf("Before setuid():\n");
    printf("Real UID: %d, Effective UID: %d, Saved UID: %d\n", ruid, euid, suid);

    // Attempt to change user ID to 1000 (example user)
    if (setuid(1000) == -1)
    {
        perror("setuid failed");
        exit(1);
    }

    // Get IDs after setuid()
    getresuid(&ruid, &euid, &suid);
    printf("\nAfter setuid(1000):\n");
    printf("Real UID: %d, Effective UID: %d, Saved UID: %d\n", ruid, euid, suid);

    return 0;
}
