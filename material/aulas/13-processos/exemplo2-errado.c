#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
    
//int rodando = 1;
pid_t filho;

filho = fork();

if (filho == 0) {
    printf("Acabei filho\n");
    //rodando = 0;
} else {
    //while (rodando) {
        printf("Esperando o filho acabar!\n");
        wait(NULL);
        printf("filho acabou");
        sleep(1);
    //}
}
return 0;
}
