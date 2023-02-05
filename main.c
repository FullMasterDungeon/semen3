#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int factorial(int n) {
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(int argc, char *argv[]) {
    int a = atoi(argv[1]);
    pid_t pid = fork();
    if (pid == 0) {
        printf("Factorial %d equals %d\n", a, factorial(a));
        exit(0);
    } else {
        wait(NULL);
        printf("Fibonacci %d equals %d\n", a, fibonacci(a));
    }
    return 0;
}
