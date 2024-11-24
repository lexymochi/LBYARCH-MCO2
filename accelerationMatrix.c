/*	LBYARCH S17
	Arcega, Bea Alexis; Bautista, Cyrus Rylie
	Machine Project 2, accelerationMatrix.c
	
	A car's performance is usually measured using an acceleration test
	with a 1km distance. some cars are measured from a cold start (they
	start at 0km/h), some are tested from a hot start (the car is running
	at a stable speed and then accelerates).

	Impement a program that computes from the acceleration of multiple cars
	stored in a Y by 3 matrix, where Y is the number of cars. All inputs are
	in single floating point.

	The output acceleration for each will be converted into Integers.
	
	Each row will indicate Initial Velocity (in km/h), Final Velocity (in km/h),
	and Time (in Seconds).
*/

#include <stdio.h>
#include <stdlib.h>

extern void accelMatrix(int cars, float *matrix, int *resultAccel);

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

    accelMatrix(cars, matrix, resultAccel);

    for (i = 0; i < cars; i++) {
        printf("%.2f > %.2f at %.2fkm/h = %d\n", matrix[i*3 + 0], matrix[i*3 + 1], matrix[i*3 + 2], resultAccel[i]);
    }

    return 0;
}
