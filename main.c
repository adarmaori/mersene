#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int isPrime(int n, int *primes, int length) {
  // This function only works if <primes> is either an empty list or the complete list of primes smaller than n
  if (n == 2) {
    return 0;
  }
  if (n % 2 == 0) {
    return 0;
  }
  int t = 1;
  if (length) {
    for (int i=0; i < length; i++) {
      if (n % primes[i] == 0) {
        return 0;
      }
      if (n < primes[i]*primes[i]) {
        return 1;
      }
    }
  }
  else {
    for (int i=3; i < sqrt(n) + 1; i+=2) {
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
  end = clock();
  return (float) (end - start) / CLOCKS_PER_SEC;
}

int main() {
  printf("%f\n", timeTest(10000000));
  return 0;
}

