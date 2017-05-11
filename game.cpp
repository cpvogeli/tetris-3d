#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "game.h"
#include "graphics.h"

piece cur;
std::clock_t timer;

std::list<std::pair<int, int>> pieces[20];

void genPiece(int n) {
    switch(rand() % 4) {
    case 0:
        cur = piece(rand() % 7 - 3, 4, rand() % 7 - 3, RED);
        break;
    case 1:
        cur = piece(rand() % 7 - 3, 4, rand() % 7 - 3, BLUE);
        break;
    case 2:
        cur = piece(rand() % 7 - 3, 4, rand() % 7 - 3, GREEN);
        break;
    case 3:
        cur = piece(rand() % 7 - 3, 4, rand() % 7 - 3, YELLOW);
        break;
    }

    cur += cube(0, 0, 0);

    for(auto p : pieces[n]) {
        cur += cube(p.first, 0, p.second);
    }
}

void gameInit() {
    // I'm sorry
    pieces[0].push_back(std::pair<int, int>(-1, 0));
    pieces[0].push_back(std::pair<int, int>(1, 0));

    pieces[1].push_back(std::pair<int, int>(-1, 0));
    pieces[1].push_back(std::pair<int, int>(1, 0));

    pieces[2].push_back(std::pair<int, int>(0, -1));
    pieces[2].push_back(std::pair<int, int>(0, 1));

    pieces[3].push_back(std::pair<int, int>(0, -1));
    pieces[3].push_back(std::pair<int, int>(0, 1));

    pieces[4].push_back(std::pair<int, int>(0, 1));
    pieces[4].push_back(std::pair<int, int>(1, 1));
    pieces[4].push_back(std::pair<int, int>(1, 0));

    pieces[5].push_back(std::pair<int, int>(0, -1));
    pieces[5].push_back(std::pair<int, int>(1, -1));
    pieces[5].push_back(std::pair<int, int>(1, 0));

    pieces[6].push_back(std::pair<int, int>(0, -1));
    pieces[6].push_back(std::pair<int, int>(-1, -1));
    pieces[6].push_back(std::pair<int, int>(-1, 0));

    pieces[7].push_back(std::pair<int, int>(0, 1));
    pieces[7].push_back(std::pair<int, int>(-1, 1));
    pieces[7].push_back(std::pair<int, int>(-1, 0));

    pieces[8].push_back(std::pair<int, int>(-1, 0));
    pieces[8].push_back(std::pair<int, int>(0, 1));
    pieces[8].push_back(std::pair<int, int>(1, 0));

    pieces[9].push_back(std::pair<int, int>(-1, 0));
    pieces[9].push_back(std::pair<int, int>(0, -1));
    pieces[9].push_back(std::pair<int, int>(1, 0));

    pieces[10].push_back(std::pair<int, int>(0, -1));
    pieces[10].push_back(std::pair<int, int>(1, 0));
    pieces[10].push_back(std::pair<int, int>(0, 1));

    pieces[11].push_back(std::pair<int, int>(0, -1));
    pieces[11].push_back(std::pair<int, int>(-1, 0));
    pieces[11].push_back(std::pair<int, int>(0, 1));

    pieces[12].push_back(std::pair<int, int>(-1, 0));
    pieces[12].push_back(std::pair<int, int>(1, 1));
    pieces[12].push_back(std::pair<int, int>(1, 0));

    pieces[13].push_back(std::pair<int, int>(-1, 0));
    pieces[13].push_back(std::pair<int, int>(1, -1));
    pieces[13].push_back(std::pair<int, int>(1, 0));

    pieces[14].push_back(std::pair<int, int>(-1, 0));
    pieces[14].push_back(std::pair<int, int>(-1, -1));
    pieces[14].push_back(std::pair<int, int>(1, 0));

    pieces[15].push_back(std::pair<int, int>(0, -1));
    pieces[15].push_back(std::pair<int, int>(-1, 1));
    pieces[15].push_back(std::pair<int, int>(0, 1));

    pieces[16].push_back(std::pair<int, int>(0, -1));
    pieces[16].push_back(std::pair<int, int>(1, 1));
    pieces[16].push_back(std::pair<int, int>(0, 1));

    pieces[17].push_back(std::pair<int, int>(0, -1));
    pieces[17].push_back(std::pair<int, int>(1, -1));
    pieces[17].push_back(std::pair<int, int>(0, 1));

    pieces[18].push_back(std::pair<int, int>(0, -1));
    pieces[18].push_back(std::pair<int, int>(-1, -1));
    pieces[18].push_back(std::pair<int, int>(0, 1));

    pieces[19].push_back(std::pair<int, int>(0, -1));
    pieces[19].push_back(std::pair<int, int>(-1, 1));
    pieces[19].push_back(std::pair<int, int>(0, 1));

    std::srand(std::time(NULL));

    genPiece(rand() % 20);

	timer = std::clock();
}


void nextPiece() {
    pile.push_back(cur);
    genPiece(rand() % 20);
}

void gameLoop() {
    if((std::clock() - timer) >= TIMER_MAX) {
        timer = std::clock();
        cur.fall();
    }
}
