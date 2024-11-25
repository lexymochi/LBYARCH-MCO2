/*	LBYARCH S17
	Arcega, Bea Alexis; Bautista, Cyrus Rylie
	Machine Project 2, accelerationC.c
	
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

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void accelMatrix(int cars, float *matrix, int *resultAccel);

float randomFloat(int max) {
	return (float)rand() / RAND_MAX + (float)(rand() % max);
}

int main() {
	srand(time(NULL));
	int inputType = -1;
	printf("\nInput 0 for manual inputs, 1 for automatic inputs.\n");
	do {
		printf("Input type: ");
		scanf("%d", &inputType);
	}
	while (inputType != 0 && inputType != 1);
	
    int cars;
    float *matrix;
    int *resultAccel;
    int i;

	printf("Number of inputs: ");
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

	if (inputType == 0)
		for (i = 0; i < cars; i++) {
			scanf("%f %f %f", &matrix[i * 3], &matrix[i * 3 + 1], &matrix[i * 3 + 2]);
		}
	else {
		for (i = 0; i < cars; i++) {
			matrix[i*3 + 0] = randomFloat(10000);
			matrix[i*3 + 1] = randomFloat(10000);
			matrix[i*3 + 2] = randomFloat(100);
		}
	}
	printf("\n");


	// time function
	clock_t start, end;
	float timer;

    start = clock();

    for (i = 0; i < 30; i++) {
        accelMatrix(cars, matrix, resultAccel);
    }
    // stop timer
        end = clock();
        timer = (float)(end - start)/CLOCKS_PER_SEC;
        printf("Execution time after %d runs: %f ms\n", i, timer);
        printf("\n");

	int expected;
	int wrongs = 0;
	int wrongIndexes[1000];
	int n;
	for (i = 0; i < cars; i++) {
		expected = (int)( roundf((matrix[i*3 + 1]*0.277777791 - matrix[i*3 + 0]*0.277777791) / matrix[i*3 + 2]) );
		printf("%f %f %f \t%d (Expected: %d)", matrix[i*3 + 0], matrix[i*3 + 1], matrix[i*3 + 2], resultAccel[i], expected);
		if (expected != resultAccel[i]) {
			printf("Correctness check: Failed");
			wrongIndexes[wrongs] = i;
			wrongs++;
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
	printf("There are %d wrong answers.\n", wrongs);
	for (i = 0; i < wrongs; i++) {
		n = wrongIndexes[i];
		expected = (int)( roundf((matrix[n*3 + 1]*0.277777791 - matrix[n*3 + 0]*0.277777791) / matrix[n*3 + 2]) );
        printf("%f %f %f \t%d (Expected: %d)\n", matrix[n*3 + 0], matrix[n*3 + 1], matrix[n*3 + 2], resultAccel[i], expected);
	}

    return 0;
}