#include <stdio.h>
#include <stdlib.h>

extern void accelMatrix(float *matrix, int *resultAccel, int cars);

int main() {
    int cars;
    float *matrix;
    int *resultAccel;
    int i;

    scanf("%d", &cars);

    matrix = (float *)malloc(cars * 3 * sizeof(float));
    if (matrix == NULL) {
        printf("Allocating memory has failed.");
        return 1;
    }

    resultAccel = (int *)malloc(cars * 3 * sizeof(int));
    if (matrix == NULL) {
        printf("Allocating memory has failed.");
        free(matrix);
        return 1;
    }

    for (i = 0; i < cars; i++) {
        scanf("%f %f %f", &matrix[i * 3], &matrix[i * 3 + 1], &matrix[i * 3 + 2]);
    }

    accelMatrix(matrix, resultAccel, cars);

    for (i = 0; i < cars; i++) {
        printf("%d\n", resultAccel[i]);
    }

    return 0;
}
