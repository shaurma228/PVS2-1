#include <omp.h>
#include <stdlib.h>
#include <stdio.h>

double START;
double END;

int main(int argc, char* argv[]) {
    const int N = atoi(argv[1]);
    const int LOOPS = atoi(argv[2]);
    int data[N];
    double totalTime = 0.0;

    for (int iteration = 0; iteration < LOOPS; ++iteration) {
        START = omp_get_wtime();
        long long sum = 0;

        for (int i = 0; i < N; ++i) {
            data[i] = 1;
            sum += data[i];
        }

        END = omp_get_wtime();
        totalTime += (END - START);
    }

    printf("Time taken: %f seconds\n", totalTime / (LOOPS*1.0));
}