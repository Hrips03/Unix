//bacum enq file, mejy ban enq grum u chenq pakum, kanchum enq exec, bacum vimy u tesnum et filey hasanelia vimin te che

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("example.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    fprintf(file, "Hello, World!\n"); 

	int ret = execl("/usr/bin/vim", "vim", NULL);
	if (ret == -1) {
		perror("execl");
	}

	return 0;
}