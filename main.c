#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int isPrime(int n, int *primes, int length) {
  // This function only works if <primes> is either an empty list or the complete list of primes smaller than n
  if ((n & 1) == 0) {
    return 0;
  }
  if (length) {
    int prime;
    for (int i=0; i < length; i++) {
      prime = primes[i];
      if (n % prime == 0) {
        return 0;
      }
      if (n < prime*prime) {
        return 1;
      }
    }
  }
  else {
    double sqr = sqrt(n);
    for (int i=3; i <= sqr + 1; i+=2) {
      if (n % i == 0) {
        return 0;
      }
    }
  }
  return 1;
}

float timeTest(int len) {
  clock_t start, end;
  start = clock();
  int *primes = malloc(sizeof(int));
  primes[0] = 2;
  int index = 1;

  for (int n = 3; n < len; n += 2) {
    if (isPrime(n, primes, index)) {
      primes = realloc(primes, (index + 1) * sizeof(int));
      primes[index] = n;
      index++;
    }
  }
  free(primes);
  end = clock();
  return (float) (end - start) / CLOCKS_PER_SEC;
}

int main() {
  printf("%f\n", timeTest(10000000));
  return 0;
}

