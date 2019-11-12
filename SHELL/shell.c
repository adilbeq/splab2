// your code here
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAXC 100

int main() { 
    
    char list[MAXC]; 
    int i = 0;
    int finished = 0;

    while (1) {

        printf("$ Enter your command: ");
        fgets(list, MAXC, stdin);
        finished = 0;
        i = 0;
        char *args[MAXC];
        args[i] = strtok(list, " \n");


        if (strcmp(list, "exit") == 0) {
            break;
        }

        while (args[i] != NULL) {
            if (strcmp(args[i], "&")) {
                i++;
                args[i] = strtok(NULL, " \n");
                wait(0);
            } else {
                finished = 1;
                args[i] = NULL;
            }
        }

        pid_t pid; 
        pid = fork(); 
        
        if(pid < 0) { 
            printf("Fork error");
        }
        if (pid == 0) {
            execvp(args[0],args); 
            
            if (execvp(args[0],args) < 0) {     
                printf("Invalid command\n");
                break;
            }
        }
        if (finished==1) {
            wait(0);
            wait(0);
            wait(0);
            wait(0);    
        }
    }
  
    return 0; 
} 
