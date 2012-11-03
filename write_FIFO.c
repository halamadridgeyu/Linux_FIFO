#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define myFIFO "./tmpFIFO"

int main()
{
    int status, num, fifo;
    char string[] = "Testing...";

    if ((fifo = open(myFIFO, O_WRONLY)) < 0) {
        printf("\n %s \n", strerror(errno));
        return 0;
    }

    if ((num = write(fifo, string, strlen(string))) < 0) {
        printf("\n %s \n", strerror(errno));
        return 0;
    }
}
