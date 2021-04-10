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
    char * path = "/bin/ls";
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        char * arg[3];
        arg[0] = strdup("ls");
        arg[1] = NULL;
        // Note that the last arg should be NULL/0/\0 by Stackoverflow
        switch(6)
        {
            case 0:
                // with l in exec mean that all args should be declared
                printf("run /bin/ls with execl()\n");
                execl(path,arg[0],arg[1],NULL);
                break;
            case 1:
                // with e in exec mean that environment pointers(3th param envp) could be passed
                printf("run /bin/ls with execle()\n");
                execle(path,arg[0],arg[1],NULL,NULL);
                break;
            case 2:
                // with p in exec mean that the process will search PATH
                printf("run /bin/ls with execlp()\n");
                execlp(path,arg[0],arg[1],NULL);
                break;
            case 3:
                // with v in exec mean that the arg should be passed as vector (argv)
                printf("run /bin/ls with execv()\n");
                execv(path,arg);
                break;
            case 4:
                printf("run /bin/ls with execvp()\n");
                execvp(path,arg);
                break;
            case 5:
                printf("run /bin/ls with execvpe()\n");
                execvpe(path,arg,NULL);
            default:
                printf("run nothing\n");
                break;
        }
    } else {
        // parent goes down this path (original process)
        wait(NULL);
        printf("child terminated\n");
    }
    return 0;
}