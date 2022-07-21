#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "primelist.h"
#include "rabinmiller.h"
// number of iteration of rabin miller
#define RM_ITER 3

bool isPrime(long long n, int iter) {
  /* Sieve of Eratosthenes */
  for (int i = 0; i < N_PRIMES; i++) {
    if (n % PRIMES[i] == 0 && n != PRIMES[i]) {
      return false;
    }
  }
  return Miller(n, iter);
}

long getLargePrimeNumber() {
  srand(time(NULL));
  srand(rand());
  while (1) {
    long num = rand();
    if (isPrime(num, RM_ITER))
      return num;
  }
}

void GeneratePublicPrivateKey(char **publickey, char **privatekey) {
  long p = getLargePrimeNumber();
  long q = getLargePrimeNumber();

  long pub = p * q;

  long phi = (p - 1) * (q - 1);

  char *e = malloc(sizeof(char) * 32);
  char *d = malloc(sizeof(char) * 32);

  sprintf(e , "%032lx", pub);
  sprintf(d , "%032lx", phi);

  *publickey = e;
  *privatekey = d;
}
