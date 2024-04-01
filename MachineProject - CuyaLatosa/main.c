#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Declare the external assembly function
extern void daxpy_asm(int n, double a, double* x, double* y, double* z);

void daxpy_c(int n, double a, double* x, double* y, double* z) {
    for (int i = 0; i < n; i++) {
        z[i] = a * x[i] + y[i];
    }
}

void print_array(double* arr, int n) {
    for (int i = 0; i < n && i < 10; i++) { // Only print the first 10 elements
        printf("%f \n", arr[i]);
    }
    printf("\n");
}

// Example usage
int main() {

    int sizes[] = { 20, 24, 28 }; // Sizes: 2^20, 2^24, 2^28

    double a = 2.0;
    double* x, * y, * z;
    double* x_asm, * y_asm, * z_asm; // Separate arrays for assembly version
    clock_t start, end;
    double total_time_c, total_time_asm;

    srand((unsigned int)time(NULL)); // Seed the random number generator

    for (int i = 0; i < sizeof(sizes) / sizeof(sizes[0]); i++) {
        int n = 1 << sizes[i]; // Calculate vector size

        // Allocate memory for vectors
        x = (double*)malloc(n * sizeof(double));
        y = (double*)malloc(n * sizeof(double));
        z = (double*)malloc(n * sizeof(double));
        x_asm = (double*)malloc(n * sizeof(double)); // Separate array for assembly version
        y_asm = (double*)malloc(n * sizeof(double)); // Separate array for assembly version
        z_asm = (double*)malloc(n * sizeof(double)); // Separate array for assembly version

        // Check for successful memory allocation
        if (x == NULL || y == NULL || z == NULL || x_asm == NULL || y_asm == NULL || z_asm == NULL) {
            printf("Memory allocation failed!\n");
            return 1; // Exit program with error code
        }
        // Initialize vectors with random values
        for (int j = 0; j < n; j++) {
            x[j] = ((double)rand() / RAND_MAX) * 100.0; // Random values between 0 and 100
            y[j] = ((double)rand() / RAND_MAX) * 100.0; // Random values between 0 and 100
            x_asm[j] = x[j]; // Copy values to separate array for assembly version
            y_asm[j] = y[j]; // Copy values to separate array for assembly version
        }

        total_time_c = 0;
        total_time_asm = 0;
        int iterations = 30;

        int cnt = 0;

        for (int j = 0; j < iterations; j++) {
            start = clock();

            // Call the C version of daxpy
            daxpy_c(n, a, x, y, z);

            end = clock();
            total_time_c += (double)(end - start) / CLOCKS_PER_SEC;

            start = clock();
            // Call the assembly version of daxpy 
            daxpy_asm(n, a, x_asm, y_asm, z_asm); // Use separate arrays for assembly version

            end = clock();
            total_time_asm += (double)(end - start) / CLOCKS_PER_SEC;
        }

        // Calculate average execution time
        double avg_time_c = total_time_c / iterations;
        double avg_time_asm = total_time_asm / iterations;

        // Print result for C version
        printf("[FOR C] \nVector size: 2^%d, Average execution time: %f seconds\n", sizes[i], avg_time_c);
        printf("First ten elements of vector Z (C version):\n");
        print_array(z, n);
        printf("\n");

        // Print result for assembly version
        printf("[FOR Assembly] \nVector size: 2^%d, Average execution time: %f seconds\n", sizes[i], avg_time_asm);
        printf("First ten elements of vector Z (Assembly version):\n");
        print_array(z_asm, n); // Use separate array for assembly version
        printf("\n");

        // Free allocated memory
        free(x);
        free(y);
        free(z);
        free(x_asm); // Free separate array for assembly version
        free(y_asm); // Free separate array for assembly version
        free(z_asm); // Free separate array for assembly version
    }
    return 0;
}