#include "kernel/types.h"
#include "kernel/procinfo.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
  if(argc < 2){
    printf("Usage: procinfo <pid>\n");
    exit(1);
  }

  int pid = atoi(argv[1]);
  struct procinfo info;

  if(getprocinfo(pid, &info) < 0){
    printf("procinfo: no such process\n");
    exit(1);
  }

  char *states[] = {"UNUSED","USED","SLEEPING","RUNNABLE","RUNNING","ZOMBIE"};

  printf("PID: %d\n",        info.pid);
  printf("Name: %s\n",       info.name);
  printf("State: %s\n",      states[info.state]);
  printf("Memory: %d\n",     (int)info.sz);
  printf("Parent PID: %d\n", info.ppid);

  exit(0);
}
