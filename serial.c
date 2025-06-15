#include <omp.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    const int N = atoi(argv[1]);
    int data[N];

    const double START = omp_get_wtime();
    long long sum = 0;

    for (int i = 0; i < N; ++i) {
        data[i] = 1;
        sum += data[i];
    }

    const double END = omp_get_wtime();
    printf("Sum: %lld, Time taken: %f seconds\n", sum, END - START);
}