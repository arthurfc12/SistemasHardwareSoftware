#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

int main() {
    pid_t filho;

    filho = fork();
    
    
    if (filho == 0) {
        printf("meu pid %d \n", getpid());
        while (1);
        //int i = 1/0;
        //printf("Divisão por zero! %d \n", i);
    }

    int ws;
    wait(&ws);
    printf("EXITED %d \n"
            "SIGNALED %d \n"
            "TERMSIG %d \n"
            "Error: %s",
            WIFEXITED(ws),
            WIFSIGNALED(ws),
            WTERMSIG(ws),
            strsignal(WTERMSIG(ws)));
    
    


    return 0;
}
