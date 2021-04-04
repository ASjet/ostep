#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
////////////////////////////////////////////////////////////////////////////////
int main(void)
{
    int status = open("./p2.txt",O_WRONLY || O_APPEND);
    if (status < 0)
    {
        fprintf(stderr,"open failed\n");
        exit(1);
    }
    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr,"fork failed\n");
        exit(1);
    }
    else if(rc == 0)
    {
        write(status,"this is child saying\n",21);
        printf("child writed\n");
    }
    else
    {
        write(status,"this is parent saying\n",22);
        printf("parent writed\n");
    }
    write(status,"close\n",6);
    printf("all writed\n");
    close(status);
    return 0;
}