#include "kernel/types.h"
#include "user/user.h"
#include "kernel/syscall.h"

int main() {
     printf("Os Project Demo \n");
     char buf[5];
     read(0,buf,0);
     read(0,buf,0);

     printf("Testing counts: \n");

     int write_count= getsyscount(SYS_write);
     int read_count= getsyscount(SYS_read);

     printf("\nwrite() called %d times\n", write_count);
     printf("read() called %d times\n", read_count);

     exit(0);
}

