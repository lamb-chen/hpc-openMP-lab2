#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <omp.h>

void init(double *p, double v, int N);
void vadd(double *A, double *B, double *C, int N);
int check(double *C, double r, int N);

int main(int argc, char *argv[]) {

  int N = 1024 * 1024;
  // Check for CLI argument giving length of array
  if (argc == 2) {
    N = atoi(argv[1]);
  }

  printf("Vector addition\n\n");
  printf("Array length: %d elements\n", N);

  double * A = malloc(sizeof(double)*N);
  double * B = malloc(sizeof(double)*N);
  double * C = malloc(sizeof(double)*N);


  init(A, 1.0, N);
  init(B, 2.0, N);
  init(C, 0.0, N);

#pragma omp parallel
{
  vadd(A, B, C, N);
}

  int correct = check(C, 1.0 + 2.0, N);
  if (correct) {
    printf("Correct!\n");
    return EXIT_SUCCESS;
  }
  return EXIT_FAILURE;
}


void init(double *p, double v, int N) {
  for (int i = 0; i < N; ++i) {
    p[i] = v;
  }
}

void vadd(double *A, double *B, double *C, int N) {
  int tid = omp_get_thread_num();
  int nthreads = omp_get_num_threads();
  printf("%d", tid);
  int i;
  for (int i = tid*N/nthreads; i < (tid+1)*N/nthreads; ++i) {
    C[i] = A[i] + B[i];
  }
}

int check(double *C, double r, int N) {
  for (int i = 0; i < N; ++i) {
    if (fabs(C[i] - r) > 1.0E-12) {
      return 0;
    }
  }
  return 1;
}

