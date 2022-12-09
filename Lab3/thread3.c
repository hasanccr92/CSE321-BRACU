#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void *ascii(void *arg) {

    char *s = (char *)arg;
    int *total = malloc(sizeof(int));
    *total = 0;

    for (int i = 0; i < strlen(s); i++) {
        *total += s[i];
    }

    free(arg);
    pthread_exit((void *)total);
}

int main() {

    int ret[3];
    pthread_t thread[3];

    for (int i = 0; i < 3; i++) {
    
        char *user = malloc(sizeof(char) * 100);
        scanf("%s", user);
        pthread_create(&thread[i], NULL, ascii, user);
    }

    for (int i = 0; i < 3; i++) {
        int *join;
        pthread_join(thread[i], (void *)&join);
        ret[i] = *join;
        free(join);
    }

    if (ret[0] == ret[1] && ret[0] == ret[2]) {
        printf("Youreka\n");
    } else if (ret[0] == ret[1] || ret[0] == ret[2] || ret[1] == ret[2]) {
        printf("Miracle\n");
    } else {
        printf("Hasta la vista\n");
    }

    return 0;
}

