#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int min = 50, max = 100;
    int secret;
    
    srand((unsigned) time(NULL));

    // BUG
    secret = rand() % max;
    printf("SECRET: %d\n", secret);


    return 0;
}