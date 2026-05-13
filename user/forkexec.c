#include "kernel/types.h"
#include "user/user.h"

int
main(void)
{
    int pid = fork();

    if(pid < 0){
        printf("fork failed\n");
        exit(1);
    }

    if(pid == 0){
        char *argv[] = { "ls", 0 };
        exec("ls", argv);
        printf("exec failed\n");
        exit(1);
    } else {
        wait(0);
        printf("Parent: child finished execution\n");
    }

    exit(0);
}	
