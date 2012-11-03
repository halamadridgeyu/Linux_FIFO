#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    int result;

    if (argc != 2) {
        fprintf(stderr, "Usage: ./a.out fifoname\n");
        exit (1);
    }

    result = mkfifo(argv[1], S_IRUSR| S_IWUSR);
    if (result < 0) {
        perror ("mkfifo");
        exit (2);
    }
}
