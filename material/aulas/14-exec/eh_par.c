#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    char prog[] = "eh_par";
    // a lista de argumentos sempre começa com o nome do
    // programa e termina com NULL
    char *args[] = {"eh_par", argv[1], NULL};
    long num1 = atol(args[1]);
    if(num1 < 0){
        printf("neg");
        return -1;
    }
    else if(num1 % 2 == 0){
        printf("par");
        return 1;
    }
    else if(num1 % 2 != 0 ){
        printf("impar");
        return 0;
    }
    
    execvp(prog,args);
    printf("crazy mothafocka");
}