// your code here
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
		printf("child1: %d+%d=%d\n", a, b, a + b);
		exit(0);
	}

	pid_t p2 = fork();
	if(p2 == 0) {
		printf("child2: %d*%d=%d\n", a, b, a * b);
		exit(0);
	}

	pid_t p3 = fork();
	if(p3 == 0) {
		printf("child3: %d-%d=%d\n", a, b, a - b);
		exit(0);
	}

	pid_t p4 = fork();
	if(p4 == 0) {
		printf("child4: %d/%d=%d\n", a, b, a / b);
		exit(0);
	}

	wait(NULL);
	wait(NULL);
	wait(NULL);
	wait(NULL);
	// waitpid(p1);
	// waitpid(p2);
	// waitpid(p3);
	// waitpid(p4);

	printf("parent: done.\n");

	return 0; // exit main process
}
