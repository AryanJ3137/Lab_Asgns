#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];
    pid_t pid;
    char message[] = "Hello from parent!";
    char buffer[100];


    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }


    pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid > 0) {

        close(pipefd[0]);  


        write(pipefd[1], message, strlen(message) + 1);

        close(pipefd[1]);  
        wait(NULL);        
    }
    else {

        close(pipefd[1]);  


        read(pipefd[0], buffer, sizeof(buffer));

        printf("Child received: %s\n", buffer);

        close(pipefd[0]);  
    }

    return 0;
}
