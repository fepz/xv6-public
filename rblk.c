#include "types.h"
#include "user.h"

int
main(int argc, char *argv[])
{
    char buf[512];
    int d, b, n , i;

    if (argc != 4) {
        printf(2, "Use: %s device block count\n", argv[0]);
        exit();
    }

    d = atoi(argv[1]);
    b = atoi(argv[2]);
    n = atoi(argv[3]);

    if (n > 512) {
        printf(2, "Error: count must be less than or equal than 512.\n");
        exit();
    }

    rblk(d, b, buf);

    for (i = 0; i < n; i++) {
        printf(1, "%d\n", buf[i]);
    }

    exit();
}
