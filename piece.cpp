#include <Windows.h>
#include <GL/glut.h>
#include <list>
#include <cmath>

#include "graphics.h"
#include "game.h"

std::list<piece> pile;

cube::cube() {
    this->rx = 0;
    this->ry = 0;
    this->rz = 0;
}

cube::cube(int rx, int ry, int rz) {
    this->rx = rx;
    this->ry = ry;
    this->rz = rz;
}

void cube::draw(int x, int y, int z, float red, float green, float blue) {
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glColor3f(red, green, blue);
    glTranslatef(x + rx, y + ry, z + rz);
    glutSolidCube(1.0f);

    /* Uncomment these lines to create clack border around pieces */
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    //glColor3f(BLACK);
    //glutWireCube(1.0f);

    glTranslatef(-(x + rx), -(y + ry), -(z + rz));
}

bool cube::canFall(int x, int y, int z) {
    for (auto p : pile) {
        for (auto c : p) {
            if(x + rx == c.rx + p.x && y + ry - 1 == c.ry + p.y && z + rz == c.rz + p.z)
                return false;
        }
    }
    return y + ry != -4;
}

bool cube::canShift(int x, int y, int z, int sx, int sz) {
    for (auto p : pile) {
        for (auto c : p) {
            if(x + rx + sx == c.rx + p.x && y + ry == c.ry /*<---*/ + p.y && z + rz + sz == c.rz + p.z)
                return false;
        }
    }
    return std::abs(x + rx + sx) <= 4 && std::abs(z + rz + sz) <= 4;
}

piece::piece() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
    this->red = 0;
    this->green = 0;
    this->blue = 0;
}

piece::piece(int x, int y, int z, float red, float green, float blue) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->red = red;
    this->green = green;
    this->blue = blue;
}

void piece::draw() {
    for(auto c : *this) {
        c.draw(x, y, z, red, green, blue);
    }
}

void piece::fall() {
    bool canFall = true;
    for(auto c : *this) {
        canFall = canFall && c.canFall(x, y, z);
    }
    if(canFall) {
        y--;
    } else {
        nextPiece();
    }
}

void piece::shift(int sx, int sz) {
    bool canShift = true;
    for(auto c : *this) {
        canShift = canShift && c.canShift(x, y, z, sx, sz);
    }
    if(canShift) {
        x += sx;
        z += sz;
    }
}

void piece::operator+=(cube add) {
        this->push_back(add);
}
