#include <list>
#include <ctime>

#include "piece.h"

#ifndef __GAME__
#define __GAME__

#define TIMER_MAX 750

extern std::list<piece> pile;
extern piece cur;
extern std::clock_t timer;

void gameInit();
void gameLoop();
void nextPiece();

#endif
