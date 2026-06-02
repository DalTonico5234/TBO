#ifndef Item_h
#define Item_h

#include "String.h"

typedef String* Item;

#define less(A, B) (compare(A, B) < 0)
#define less_from(A, B, d) (compare_from(A, B, d) < 0)
#define exch(A, B) { Item t = A; A = B; B = t; }

#endif