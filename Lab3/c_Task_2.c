#include <stdio.h>
#include <stdbool.h>

bool isPerfect(int n) {
    int sum = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;
        }}
    if (sum == n)
        return true;
    return false;
}

void findPerfect() {
    int j, k;
    printf("Enter lower bound: ");
    scanf("%d", &j);
    printf("Enter upper bound: ");
    scanf("%d", &k);

    for (int i = j; i <= k; i++) {
        if (isPerfect(i)) {
            printf("%d is a perfect number in the given range\n", i);
        }}}
int main() {

    findPerfect();
    return 0;
}

