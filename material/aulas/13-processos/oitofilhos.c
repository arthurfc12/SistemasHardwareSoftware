#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    pid_t pai, filho1;
    int var = 0;

    for(var; var < 8; var ++){
    filho1 = fork();
    if (filho1 == 0){
        printf("Filho %d\n", var);
        return 0;
    }else{
        printf("Pai %d\n", var);
    }
    }

    return 0;
}