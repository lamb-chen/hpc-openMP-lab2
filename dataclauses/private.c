#include <stdio.h>
#include <omp.h>

int main(void) {

  int x = -1;
  int N = 10;
  printf("before: x=%d\n", x);
  #pragma omp parallel for lastprivate(x) 
  for (int i = 0; i < N; ++i) {
    printf("Thread %d setting x=%d to %d\n", omp_get_thread_num(), x, i);
    x = i;
  }
  printf("after: x=%d\n", x);

  return 0;
}

