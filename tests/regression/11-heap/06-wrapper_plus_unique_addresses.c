// PARAM: --set ana.malloc.wrappers "['myalloc2']" --set ana.malloc.unique_address_count 2


// Copied from 02/21. Here, only the inner wrapper function is specified. This should tests
// the combination of uniqueness analysis and malloc wrapper analysis.

#include <stdlib.h>
#include <assert.h>

void *myalloc(size_t n) {
  return malloc(n);
}

void *myalloc2(size_t n) {
  return myalloc(n);
}

int main() {
  int *x = myalloc2(sizeof(int));
  int *y = myalloc2(sizeof(int));
  int *p;

  *x = 0;
  *y = 1;

  assert(*x == 0);
  assert(*y == 1);

  p = x; x = y; y = p;
  assert(*x == 1);
  assert(*y == 0);

  return 0;
}