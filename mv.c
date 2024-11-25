#include <stdio.h>
#include <stdlib.h>

int main(int argc , char *argv[]){
    if(argc!=3){
        perror("usgae");
        exit(EXIT_FAILURE);
    }

    if(rename(argv[1],argv[2])==-1){
        perror("mv");
        exit ;
    }

    print("moved files successfully!");
    return 0 ;
}