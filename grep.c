#include <stdio.h>
#include <string.h>
#define MAX 1024
int main(int argc , char*argv[]){
    char pattern[MAX];
    strcpy(pattern , argv[1]) ;
    char line[MAX];
    while(fgets(line,sizeof(line),stdin)!=NULL){
        if(strstr(line,pattern)!=NULL){
            printf("%s",line);
        }
    }
    return 0 ;
}