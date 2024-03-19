#include <stdio.h>
#include <math.h>
#include <time.h>

int isPrime(int n) {
  if (n == 2) {
    return 0;
  }
  if (n % 2 == 0) {
    return 0;
  }
  for (int i=3; i < sqrt(n) + 1; i+=2) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}

float timeTest(int len) {
  clock_t start, end;
  start = clock();
  for (int n = 2; n < len; n++) {
    isPrime(n);
  }
  end = clock();
  return (float) (end - start) / CLOCKS_PER_SEC;
}

int main() {
  printf("%f\n", timeTest(10000000));
  return 0;
}

