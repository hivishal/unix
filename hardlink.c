#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc , char *argv[]){
    char *filename = argv[1] ;
    struct stat file_stat ;

    if(link(filename,"hard_link")==-1){
        perror("cannot create hard link ");
        exit(EXIT_FAILURE);
    }

    
    if(symlink(filename,"sym_link")==-1){
        perror("cannot create sym link ");
        exit(EXIT_FAILURE);
    }

    if(stat(filename,&file_stat)==-1){
            perror("ee");
            exit(EXIT_FAILURE);

    }

    printf("information about file types\n");
    printf("number of links %ld\n",file_stat.st_nlink);


    if(lstat("sym_link",&file_stat)==-1){
        perror("rror");
        exit(EXIT_FAILURE);

    }
    printf("information about symlink");
    printf("nubmer of links %ld\n",file_stat.st_nlink);
}