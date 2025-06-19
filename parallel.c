#include <omp.h>
#include <stdlib.h>
#include <stdio.h>

double START;
double END;

int main(int argc, char* argv[]) {
    const int N = atoi(argv[1]);
    const int LOOPS = atoi(argv[2]);
    const int THREADS = atoi(argv[3]);
    double totalTime = 0.0;

    int *data = (int *) malloc(N * sizeof(int));

    for (int j = 0; j < LOOPS; ++j) {
        START = omp_get_wtime();
        long long sum = 0;

        #pragma omp parallel for num_threads(THREADS) reduction(+:sum)
        for (int i = 0; i < N; ++i) {
            data[i] = 1;
            sum += data[i];
        }

        END = omp_get_wtime();
        totalTime += (END - START);
    }

    printf("Time taken: %f seconds\n", totalTime / (LOOPS*1.0));
}