#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void runner(void *arg) {
    int i = *(int *)arg;
    printf("thread-%d running\n", i);
    free(arg);
    pthread_exit(0);
}
int main() {

    for (int i = 1; i <= 5; i++) {
        pthread_t t;
        int *thread = malloc(sizeof(int));
        *thread = i;
        pthread_create(&t, NULL, (void *)&runner, thread);
        pthread_join(t, NULL);
        printf("thread-%d closed\n", i);}

    return 0;
}

