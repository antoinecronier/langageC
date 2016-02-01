#include <stdio.h>
#include <stdlib.h>
#include "position.h"

position* position_ctor(int x, int y) {
  position* p = malloc(sizeof(position));
  p->x = x;
  p->y = y;
  return p;
}
