#include <unistd.h>
#include <stdio.h>

int main() {
	int ret = execl("/usr/bin/vim", "vim", NULL);
	if (ret == -1) {
		perror("execl");
	}
	printf("After exec\n");
	return 0;
}
