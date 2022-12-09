#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t f1, f2;

    f1 = fork();

    if (f1 == 0) {
        f2 = fork();
        if (f2 == 0) {
            printf("I am Grandchild\n");
        } else {
            wait(NULL);
            printf("I am Child\n");
        }
    } else {
        wait(NULL);
        printf("I am Parent\n");
    }
    return 0;
}
