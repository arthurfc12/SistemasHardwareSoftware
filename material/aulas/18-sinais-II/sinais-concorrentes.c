#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int status = 0;

void operacao_lenta() {
    sleep(10);
}


void sigint_handler(int num) {
    status += 1;
    printf("Chamou Ctrl+C; status=%d\n", status);
    operacao_lenta();
    printf("SIGINT: Vou usar status agora! status=%d\n", status);
}

void sigterm_handler(int num) {
    status += 1;
    printf("Recebi SIGTERM; status=%d\n", status);
    operacao_lenta();
    printf("SIGTERM: Vou usar status agora! status=%d\n", status);
}

int sigaction(int signum, const struct sigaction*act, struct sigaction *oldact);

int main() {
    /* TODO: registar SIGINT aqui. */

    struct sigaction s;
    s.sa_handler = sigint_handler;
    sigemptyset(&s.sa_mask);
    s.sa_flags = 0;

    sigaction(SIGINT, &s, NULL);
    //adicionar sinais que bloqueiam sigterm
    sigaddset(&s.sa_mask, status);

    operacao_lenta();

    /* TODO: registar SIGTERM aqui. */

    struct sigaction sigterm;
    sigterm.sa_handler = sigterm_handler;
    sigemptyset(&sigterm.sa_mask);
    sigterm.sa_flags = 0;

    sigaction(SIGTERM, &sigterm, NULL);

    printf("Meu pid: %d\n", getpid());

    while(1) {
        sleep(1);
    }
    return 0;
}
