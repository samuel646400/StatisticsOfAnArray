#include <stdio.h>
#include <stdlib.h>

int analyzuj_pole(const int *pole, int delka, int *min, int *max, double *prumer) {

    if (pole == NULL || delka <= 0 || min == NULL || max == NULL || prumer == NULL)
        return 0;

    *min = pole[0];
    *max = pole[0];
    *prumer = pole[0];

    for (int i = 1; i < delka; i++) {
        *prumer += pole[i];
        if (*min > pole[i]) {
            *min = pole[i];
        }
        if (*max < pole[i]) {
            *max = pole[i];
        }
    }

    *prumer /= delka;

    return 1;
}

int main(void) {

    int delka, min, max;
    double prumer;

    printf("Zadejte pocet prvku:\n");
    int nacteni = scanf("%d", &delka);
    if (nacteni != 1 || delka <= 0) {
        printf("Nespravny vstup.\n");
        return 1;
    }

    int *pole = (int *)malloc(sizeof(int) * delka);
    if (pole == NULL) {
        printf("Nespravny vstup.\n");
        return 1;
    }

    printf("Zadejte prvky:\n");
    for (int i = 0; i < delka; i++) {
        nacteni = scanf("%d", &pole[i]);
        if (nacteni != 1) {
            printf("Nespravny vstup.\n");
            free(pole);
            pole = NULL;
            return 1;
        }
    }

    if (analyzuj_pole(pole, delka, &min, &max, &prumer)) {
        printf("Min: %d, Max: %d, Prumer: %.2lf\n", min, max, prumer);
    }
    else {
        printf("Nespravny vstup.\n");
        free(pole);
        pole = NULL;
        return 1;
    }

    free(pole);
    pole = NULL;

    return 0;
}