#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int c = 1;
void runner(void *arg) {
    int thrdno = *(int *)arg;
    for (int i = 0; i < 5; i++, c++) {
        printf("Thread %d prints %i\n", thrdno, c);
    }
    pthread_exit(0);
}

int main() {

    for (int i = 1; i <= 5; i++) {
        pthread_t t;
        pthread_create(&t, NULL, (void *)&runner, &i);
        pthread_join(t, NULL);
    }

    return 0;
}

