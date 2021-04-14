// Copiar este archivo en el directorio donde tengan xv6

#include "types.h"
#include "user.h"
#include "date.h"

int main(int argc, char *argv[])
{
  printf(1, "%d\n", pscnt());
  int pid = fork();
  if (pid == 0) {
    printf(1, "%d\n", pscnt());
  } else {
      wait();
  }
  exit();
}
