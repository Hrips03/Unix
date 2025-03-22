#include <malloc.h>

int main()
{
    size_t len = 21;
    size_t size;
    char *buf;
    buf = malloc(len);
    if (!buf)
    {
        perror("malloc");
        return -1;
    }
    size = malloc_usable_size(buf);
    printf("size = %li\n", size);
    size = malloc_trim(4);
    printf("size = %li\n", size);
}