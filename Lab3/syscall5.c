#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t child = fork();

    if (child == 0) {
        printf("2.Child process ID: %d\n", getpid());

        pid_t grandc1, grandc2, grandc3;
        grandc1 = fork();

        if (grandc1 != 0) {
            printf("3.Grand child process ID: %d\n", grandc1);
            grandc2 = fork();

            if (grandc2 != 0) {

                printf("4.Grand child process ID: %d\n", grandc2);
                grandc3 = fork();
                if (grandc3 != 0) {

                    printf("5.Grand child process ID: %d\n", grandc3);
                }
            }
        }
    } else {
        printf("1.Parent Process ID: %d\n", getpid());
    }

    wait(NULL);
    return 0;
}
