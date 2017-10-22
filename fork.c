#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void tabs(int n) {
    for (int i = 0; i < n; i++)
        printf("    ");
}

int main() {
    printf("\n");
    printf("dad: %d\n", getpid());
    int dad = getpid();
    if (fork() == 0) {
        tabs(1);
        printf("son: %d from dad: %d\n", getpid(), dad);
        dad = getpid();
        if (fork() == 0) {
            tabs(2);
            printf("son: %d from dad: %d\n", getpid(), dad);
            dad = getpid();
            if (fork() == 0) {
                tabs(3);
                printf("son: %d from dad: %d\n", getpid(), dad);
                dad = getpid();
                if (fork() == 0) {
                    tabs(4);
                    printf("son: %d from dad: %d\n", getpid(), dad);
                    dad = getpid();
                    if (fork() == 0) {
                        tabs(5);
                        printf("son: %d from dad: %d\n", getpid(), dad);
                        dad = getpid();
                        if (fork() == 0) {
                            tabs(6);
                            printf("son: %d from dad: %d\n", getpid(), dad);
                            exit(0);
                        }
                        if (fork() == 0) {
                            tabs(6);
                            printf("son: %d from dad: %d\n", getpid(), dad);
                            exit(0);
                        }
                        exit(0);
                    }
                    exit(0);
                }
                exit(0);
            }
            /*        if (fork() == 0) {

                        exit(0);
                    }
                    if (fork() == 0) {

                        exit(0);
                    }*/
            exit(0);
        }
        exit(0);
    }

    exit(0);
}
