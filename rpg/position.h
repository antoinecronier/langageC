#ifndef POSITION_H_INCLUDED
#define POSITION_H_INCLUDED

typedef struct position{
    int x;
    int y;
}position;

position* position_ctor(int x, int y);

#endif // POSITION_H_INCLUDED
