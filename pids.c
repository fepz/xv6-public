#include "types.h"
#include "user.h"
#include "date.h"

int main(int argc, char *argv[])
{
  printf(1, "PID: %d\n", getpid());
  printf(1, "PPID: %d\n", getppid());
  exit();
}
