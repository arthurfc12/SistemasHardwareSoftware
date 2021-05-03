#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    //size_t sizearray = sizeof(argv)/sizeof(argv[0]);
    if(argc < 3){
        printf("ERRO\n");
        return -1;
    }
    double num1 = atof(argv[1]);
    double num2 = atof(argv[2]);
    double num3 = num1 + num2;
    printf("%lf\n", num3);
    return 0;
}