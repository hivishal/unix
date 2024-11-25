#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main(){
   printf("clock ticks %ld\n",sysconf(_SC_CLK_TCK));
   printf("max child process %ld\n",sysconf(_SC_CHILD_MAX));
   printf("Max path length %ld\n",pathconf("/",_PC_PATH_MAX));
   printf("Max character %ld\n",pathconf("/",_PC_NAME_MAX));
   printf("max open process %ld\n",sysconf(_SC_OPEN_MAX));
   printf("system page size%ld\n",sysconf(_SC_PAGESIZE));
   char hostname[_SC_HOST_NAME_MAX] ; 
   if(gethostname(hostname,_SC_HOST_NAME_MAX)==0){
    printf("system hostname %s\n",hostname);
   }
   else{
    perror("gethostname");
   }
    char cwd[4096] ;
    if(getcwd(cwd,sizeof(cwd))!=NULL){
        printf("current working directory %s\n",cwd);

    }
    else{
        perror("getcwd");
    }
    return 0 ;

}