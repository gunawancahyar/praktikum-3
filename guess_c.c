#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int min, max;
    int level;
    int secret, guess, attempts = 0;

    printf("Pilih level:\n");
    printf("1. Easy (1-10)\n");
    printf("2. Medium (1-100)\n");
    printf("3. Hard (1-1000)\n");
    printf("Masukkan pilihan: ");
    scanf("%d", &level);

    if (level == 1) { min = 1; max = 10; }
    else if (level == 2) { min = 1; max = 100; }
    else if (level == 3) { min = 1; max = 1000; }
    else {
        printf("Level tidak valid, default medium\n");
        min = 1; max = 100;
    }

    srand((unsigned) time(NULL));


    // BENAR
    secret = rand() % (max - min + 1) + min;

    printf("\nTebak angka antara %d sampai %d!\n", min, max);

    time_t start = time(NULL);

    while (1) {
        printf("Masukkan tebakan: ");

        if (scanf("%d", &guess) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            printf("Input tidak valid!\n");
            continue;
        }

        attempts++;

        if (guess < secret) {
            printf("Terlalu kecil\n");
        } else if (guess > secret) {
            printf("Terlalu besar\n");
        } else {
            printf("Benar! %d percobaan\n", attempts);
            break;
        }
    }

    time_t end = time(NULL);
    printf("Waktu: %ld detik\n", end - start);

    FILE *fp = fopen("best_score.txt", "r");
    int best = 0;

    if (fp != NULL) {
        fscanf(fp, "%d", &best);
        fclose(fp);
    }

    if (best == 0 || attempts < best) {
        printf("Best score baru!\n");
        fp = fopen("best_score.txt", "w");
        fprintf(fp, "%d", attempts);
        fclose(fp);
    } else {
        printf("Best score saat ini: %d\n", best);
    }

    return 0;
}
