// Copiar este archivo en el directorio donde tengan xv6

#include "types.h"
#include "user.h"
#include "date.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{
  //int a = 1, b = 0;
  //printf(1, "%d\n", a/b);
  int fd;
  fd = open("test.txt", O_CREATE|O_RDWR);
  write(fd, "a", 1);
  exit();
}
