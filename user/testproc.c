#include "kernel/types.h"
#include "user/user.h"

int main() {
  printf("Number of Processes: %d\n", getnproc());
  printf("Max PID: %d\n", getmaxpid());
  exit(0);
}
