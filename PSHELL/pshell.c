// your code here
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {

	char input[1000];
	char* list[100];

	list[0] = "/bin/bash";
	list[1] = "-c";
	list[3] = NULL;

	do {
		printf("$ Enter your command: ");
		fgets(input, 1000, stdin);
		char *pch = strtok(input, "\n");
		list[2] = input;

		if(strcmp(pch, "exit") == 0) {
			break;
		}

		if(strcmp(pch, "showjobs") == 0) {
			list[2] = "ps | awk '$4 != \"pshell\" && $4 != \"bash\" && $4 != \"awk\" && $4 != \"ps\" && $4 != \"CMD\"' | awk '{print NR\".\", \"[\"$1\"]\"}'";
		}		

		pid_t p = fork();

		if (p == 0) {
			execvp(list[0], list);
		}

		waitpid(p, NULL, 0);

	} while(1);

	return 0;
}
