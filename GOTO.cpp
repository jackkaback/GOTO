#include <stdio.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#define NROWS 20
#define NCOLS 20
using namespace std;

/* Fills the matrix with random numbers between [0-500] */

void randomMatrixNums(int A[NROWS][NCOLS]) {
  srand(time(NULL));
  int i = 0, j = 0;
  loopA:
  A[i][j] = rand() % 501;
  j++;

  if (j < NROWS) {
    goto loopA;
  }

  j = 0;
  i++;

  if (i < NCOLS) {
    goto loopA;
  }
}

/* Goes through the matrix and finds the prime numbers.
 * Adds the prime numbers to a vector
 */

void addPrimesToList(int A[NROWS][NCOLS], vector<int> &prime) {
  int h = 1, i = 0, j = 0, cnt = 0;
  loopB:
  if (h <= A[i][j]) {
    if (A[i][j] % h == 0) {
      cnt++;
    }
    h++;
    goto loopB;
  }
  if (cnt == 2) {
    prime.push_back(A[i][j]);
  }

  cnt = 0;
  h = 1;
  j++;

  if (j < NROWS) {
    goto loopB;
  }

  j = 0;
  i++;

  if (i < NCOLS) {
    goto loopB;
  }
}

/* Sorts the prime number vector using selection sort */

void sortPrimeList(vector<int> &prime) {
  int i = 0, j = 0, minIndex, tmp, n;
  n = prime.size();

  loopSort1:
  j = i + 1;
  minIndex = i;

  loopSort2:
  if (prime[j] < prime[minIndex]) {
    minIndex = j;
  }
  j++;
  if (j < n) {
    goto loopSort2;
  }
  tmp = prime[minIndex];
  prime[minIndex] = prime[i];
  prime[i] = tmp;

  i++;

  if (i < n - 1) {
    goto loopSort1;
  }
}

/* Goes through the sorted prime number vector and finds unique numbers.
 * Adds the unique primes to another vector
 */

void addUniquePrimesToList(vector<int> &prime, vector<int> &uniPrimes) {
  int i = 1, lPrime;
  lPrime = prime[0];
  uniPrimes.push_back(prime[0]);

  loopUnique:

  if (prime[i] != lPrime) {
    uniPrimes.push_back(prime[i]);
  }

  lPrime = prime[i];
  i++;

  if(i < prime.size()) {
    goto loopUnique;
  }
}

/* Prints the original primes and the unique primes with 10 per row */

void printPrimes(vector<int> &prime, vector<int> &uniPrimes) {
  int i;
  cout << "Original prime numbers:" << endl;
  i = 0;
  outputOPrimes:
  printf("%3d ", prime[i]);
  i++;
  if (i % 10 == 0) {
    cout << endl;
  }
  if (i < prime.size()) {
    goto outputOPrimes;
  }
  cout << endl;


  cout << "Unique prime numbers:" << endl;
  i = 0;
  outputUPrimes:
  printf("%3d ", uniPrimes[i]);
  i++;
  if (i % 10 == 0) {
    cout << endl;
  }
  if (i < uniPrimes.size()) {
    goto outputUPrimes;
  }
  cout << endl;
}

int main() {
  int A[NROWS][NCOLS];
  vector<int> prime;
  vector<int> uniPrimes;

  randomMatrixNums(A);
  addPrimesToList(A, prime);
  sortPrimeList(prime);
  addUniquePrimesToList(prime, uniPrimes);
  printPrimes(prime, uniPrimes);

exit(0);
}
