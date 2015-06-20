/*
 * This file contains a custom HashMap implementation.
 * I would like to make this more general,
 * but right now it is pretty specific to Fly WM.
 */
#include "hashmap.h"

// constructor:
HashMap newHashMap() {
  HashMap hm;
  hm.n = 0;

  return hm;
}

// private:
int index_of(char *xs[], char *x, int len) {
  int i;
  for (i = 0; i < len; i++) {
    fprintf(stderr, "%s == %s at %d\n", xs[i], x, i);
    if (xs[i] == NULL) return -1;
    if (strcmp(xs[i], x) == 0) {
      return i;
    }
  }
  return -1;
}

// public:
void put(HashMap *self, char *k, Window *v) {
  self->n++;
  self->bucket_keys[self->n] = k;
  fprintf(stderr, "%s at %d\n", k, self->n);
  self->bucket_values[self->n] = v;
}

Window *get(HashMap *self, char *k) {
  int idx = 0;
  return get_with_index(self, k, &idx);
}

Window *get_with_index(HashMap *self, char *k, int *i) {
  int idx = index_of(self->bucket_keys, k, self->n);
  assert(idx != -1);
  i = &idx;
  return self->bucket_values[idx];
}
