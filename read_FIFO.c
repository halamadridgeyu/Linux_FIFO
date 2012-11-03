#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define myFIFO "./tmpFIFO"

int main()
{
    int num, fifo, status;
    char temp[32];

    if ((status = mkfifo(myFIFO, 0666)) < 0) {
        printf("\n %s \n", strerror(errno));
        return 0;
    }

    if ((fifo = open(myFIFO, O_RDONLY)) < 0) {
        printf("\n %s \n", strerror(errno));
        return 0;
    }

    if ((num= read(fifo, temp, sizeof(temp))) < 0) {
        printf("\n %s \n", strerror(errno));
        return 0;
    }

    printf("In FIFO is %s \n", temp);
}
