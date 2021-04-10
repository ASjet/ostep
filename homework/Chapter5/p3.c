#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
int main(void)
{
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        // printf("hello, I am child (pid:%d)\n", (int) getpid());
        printf("hello\n");
    } else {
        // parent goes down this path (original process)
        // printf("hello, I am parent of %d (pid:%d)\n",
	    //    rc, (int) getpid());
        sleep(1);
        printf("goodbye\n");
    }
    return 0;
}