#include <list>

#ifndef __PIECE__
#define __PIECE__

class cube {
public:
    int rx, ry, rz;

    cube();
    cube(int, int, int);
    void draw(int, int, int, float, float, float);
    bool canFall(int, int, int);
    bool canShift(int, int, int, int, int);
};

class piece : public std::list<cube> {
public:
    int x, y, z;
    float red, green, blue;

    piece();
    piece(int, int, int, float, float, float);
    void draw();
    void fall();
    void shift(int, int);
    void operator+=(cube);
};

#endif
