#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>
#include <fcntl.h>


void flock(int fd){
    struct flock fl ;
    fl.l_type = F_WRLCK ;
    fl.l_len = 0 ;
    fl.l_start = 0 ;
    fl.l_whence = SEEK_SET ;


    if(fcntl(fd,F_SETLKW,&fl)==-1)
    {
        perror("fcntl");
        exit(EXIT_FAILURE);
    }
    printf("file locked successfully1");

}

void funlock(int fd){
    struct flock fl ;
    fl.l_type = F_UNLCK ;
    fl.l_whence = SEEK_SET ;
    fl.l_len = 0 ;
    fl.l_start = 0 ;


    if(fcntl(fd,F_SETLK,&fl)==-1)
    {
        perror("fcntl");
        exit(EXIT_FAILURE);
    }
    printf("file unlocked successfully1");

}



int main(){
    char *file = "testfile.txt";
    int fd ;
    if(fd = open(file,O_RDWR|O_CREAT,0666) == -1){
        perror("open");
        exit(EXIT_FAILURE);
    }

    if(write(fd,"Hello, World!\n",14)!=14){
        perror("write");
        exit(EXIT_FAILURE);
    }

    flock(fd);

    if(write(fd,"writing to locked file\n",23)!=23){
        perror("write");
        printf("cannot write to locked file\n");
    }
    funlock(fd);

    if(write(fd,"unlock testing\n",15)!=15){
        perror("write");
        exit(EXIT_FAILURE);
    }
    close(fd);
    return 0 ;
}