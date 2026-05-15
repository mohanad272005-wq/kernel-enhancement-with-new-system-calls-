#include "kernel/types.h"
#include "user/user.h"

int
main(void)
{
    int fd[2];
    int pid;
    char buf[32];

    if (pipe(fd) < 0) {
        fprintf(2, "pipe failed\n");
        exit(1);
    }

    pid = fork();
    if (pid < 0) {
        fprintf(2, "fork failed\n");
        exit(1);
    }

    if (pid == 0) {
        close(fd[1]);
        read(fd[0], buf, sizeof(buf));
        printf("Child received: %s\n", buf);
        close(fd[0]);
    } else {
        close(fd[0]);
        write(fd[1], "hello", 6);
        close(fd[1]);
        wait(0);
    }

    exit(0);
}
