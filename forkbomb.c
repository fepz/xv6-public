#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
    int count = 0;
    int pid = 0;
    while (1) {
        pid = fork();
        if (pid == 0) {
            exit();
        } else if (pid > 0) {
            count = count + 1;
        } else {
            break;
        }
    }
    while ((pid = wait()) > 0)
        ;
    printf(1, "%d\n", count);
    exit();
}

