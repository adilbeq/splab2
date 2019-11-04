#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char *argv[])
{
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);

	pid_t p1 = fork();
	if(p1 == 0) {
		//printf("python: %d+%d=%d\n", a, b, a + b);
		execlp("python", "0", "add.py", argv[1], argv[2], NULL);

		exit(0);
	}

	pid_t p2 = fork();
	if(p2 == 0) {
		//printf("python: %d+%d=%d\n", a, b, a + b);
		execlp("java", "0", "addJava", argv[1], argv[2], NULL);

		exit(0);
	}

	pid_t p3 = fork();
	if(p3 == 0) {
		//printf("python: %d+%d=%d\n", a, b, a + b);
		execlp("node", "0", "addNode", argv[1], argv[2], NULL);

		exit(0);
	}

	pid_t p4 = fork();
	if(p4 == 0) {
		//printf("python: %d+%d=%d\n", a, b, a + b);
		execlp("bash", "0", "addBash.sh", argv[1], argv[2], NULL);

		exit(0);
	}

	wait(NULL);
	wait(NULL);
	wait(NULL);
	wait(NULL);

	printf("parent: done.\n");

	return 0; // exit main process
}
