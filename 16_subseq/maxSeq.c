#include <stdlib.h>
#include <stdio.h>

size_t maxSeq(int * array, size_t n) {
  if (n == 0) {
    return 0;
  }
  int max = 1;
  int current = 1;
  for (int i=1; i < n; ++i) {
    if (array[i] > array[i-1]) {
      current += 1;
    } else {
      current = 1;
    }
    if (current > max) {
      max = current;
    }
  }

  return max;
}
