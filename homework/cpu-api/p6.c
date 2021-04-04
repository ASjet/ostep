#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <sys/types.h>
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
        printf("hello, I am child (pid:%d)\n", (int) getpid());
        int wc = waitpid(rc,NULL,0);
        printf("the return value of waitpid() is %d\n", wc);
    } else {
        // parent goes down this path (original process)
        int wc = waitpid(rc,NULL,0);
        printf("hello, I am parent of %d (pid:%d)\n", rc, (int) getpid());
        printf("the return value of waitpid() is %d\n", wc);
    }
    return 0;
}