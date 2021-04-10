#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
////////////////////////////////////////////////////////////////////////////////
#define BUFFER_SIZE 100
////////////////////////////////////////////////////////////////////////////////
int main(void)
{
    int pipeline[2];
    int rc1, rc2;
    char send_buffer[BUFFER_SIZE] = "0123456789ABCDEF\n";
    char rece_buffer[BUFFER_SIZE] = {0};
    if (pipe(pipeline) == -1)
    {
        fprintf(stderr, "pipe create failed\n");
        exit(1);
    }
    rc1 = fork();
    if (rc1 < 0)
    {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc1 == 0)
    {
        // child (new process)
        printf("hello, I am sender (pid:%d)\n", (int)getpid());
        printf("I have sent a message:");
        fgets(send_buffer, BUFFER_SIZE, stdin);
        dup2(pipeline[1],STDOUT_FILENO);
        puts(send_buffer);
    }
    else
    {
        // parent goes down this path (original process)
        wait(NULL);
        rc2 = fork();
        if (rc2 < 0)
        {
            // fork failed; exit
            fprintf(stderr, "fork failed\n");
            exit(1);
        }
        else if (rc2 == 0)
        {
            // child (new process)
            printf("hello, I am receiver (pid:%d)\n", (int)getpid());
            dup2(pipeline[0],STDIN_FILENO); //
            fgets(rece_buffer, BUFFER_SIZE, stdin);
            printf("I have received message:%s\n",rece_buffer);
        }
        else
        {
            // parent goes down this path (original process)
            wait(NULL);
            printf("hello, I am parent of %d and %d (pid:%d)\n", rc1, rc2, (int)getpid());
        }
    }
    return 0;
}