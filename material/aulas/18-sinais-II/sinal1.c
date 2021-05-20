#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>


volatile int flag = 0;

void sig_handler(int num) {
    printf("Chamou Ctrl+C\n");
    flag ++;
    if (flag>2){
        struct sigaction s;
        s.sa_handler = sig_handler; // aqui vai a função a ser executada
        sigemptyset(&s.sa_mask);
        s.sa_flags = 0;

        sigaction(SIGINT, &s, NULL);
    }
}

int sigaction(int signum, const struct sigaction*act, struct sigaction *oldact);

/*struct sigaction{
    void (*sig_handler)(int);
    void (*sig_handler)(int,siginfo_t*, void *);
    sigset_t   sa_mask;
    int sa_flags;
    void(*sa_restorer)(void);
};*/

int main() {
    int cont = 0;

    struct sigaction s;
    s.sa_handler = sig_handler; // aqui vai a função a ser executada
    sigemptyset(&s.sa_mask);
    s.sa_flags = 0;

    sigaction(SIGINT, &s, NULL);

    printf("Meu pid: %d\n", getpid());

    while(1) {
        sleep(1);
    }
    return 0;
}
