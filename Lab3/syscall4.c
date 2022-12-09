#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


void sort(int array[], int size) {

    for (int i = 1; i < size; i++) {
        int item = array[i];
        int j = i - 1;
        while (j >= 0 && item < array[j]) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = item;
    }
    printf("The sorted Array: \n");
    for (int i = size-1; i >= 0; i--) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void oddEven(int array[], int size) {

    for (int i = 0; i < size; i++) {
   
        if (array[i] % 2 == 0) {
            printf("%d - Even\n", array[i]);
        } else {
            printf("%d - Odd\n", array[i]);
        }
    }
}


int main(int argc, char *argv[]) {

    int size = argc - 1;
    int array[argc];

    
    for (int i = 1; i < argc; i++) {
        array[i - 1] = atoi(argv[i]);
    }

    pid_t pid = fork();

    if (pid == 0) {
        sort(array, size);
    } else {
        wait(NULL);
        oddEven(array, size);
    }

    return 0;
}

