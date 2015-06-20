/*
 * HashMap header file
 */
#include <X11/Xlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#ifndef HASHMAP
#define HASHMAP

#define MAX_LENGTH 10000

typedef struct _HashMap {
  Window *bucket_values[MAX_LENGTH];
  char *bucket_keys[MAX_LENGTH];
  int n;
} HashMap;

HashMap newHashMap();
void put(HashMap *self, char *k, Window *v);
Window *get(HashMap *self, char *k);
Window *get_with_index(HashMap *self, char *k, int *i);

#endif
