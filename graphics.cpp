#include <Windows.h>
#include <GL/glut.h>
#include <cmath>

#include "game.h"
#include "piece.h"
#include "graphics.h"

float azim = 0.0f, incl = 0.0f, rad = 19.0f;
float incr = .075f;

// Read WASD to rotate camera
void processNormalKeys(unsigned char key, int x, int y) {
	switch(key) {
    case 97:
        azim += incr;
        break;
    case 100:
        azim -= incr;
        break;
    case 119:
        incl += incl + incr > .375f ? 0.0f : incr;
        break;
    case 115:
        incl -= incl - incr < -.375f ? 0.0f : incr;
        break;
	}
}

// Read arrow keys to move pieces
void processSpecialKeys(int key, int x, int y) {
	switch(key) {
    case GLUT_KEY_UP:
        cur.shift(-std::round(std::cos(azim)), -std::round(std::sin(azim)));
        break;
    case GLUT_KEY_DOWN:
        cur.shift(std::round(std::cos(azim)), std::round(std::sin(azim)));
        break;
    case GLUT_KEY_RIGHT:
        cur.shift(std::round(std::sin(azim)), -std::round(std::cos(azim)));
        break;
    case GLUT_KEY_LEFT:
        cur.shift(-std::round(std::sin(azim)), std::round(std::cos(azim)));
        break;
	}
}

// Consult the following link for questions http://www.lighthouse3d.com/tutorials/glut-tutorial/preparing-the-window-for-a-reshape/
void changeSize(int width, int height) {
	if (height == 0)
		height = 1;
	float ratio =  width * 1.0 / height;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, width, height);
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}

void renderScene(void) {
    // Run game logic
    gameLoop();

    // Set background color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glClearColor(WHITE, 1.0f);
	glLoadIdentity();
	glLoadIdentity();

	// Just accept it
	gluLookAt((rad - std::cos(incl)) * std::cos(azim), rad * std::sin(incl), (rad - std::cos(incl))* std::sin(azim), 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	// Draw pieces
	cur.draw();
	for(auto p : pile) {
        p.draw();
	}

	// Draw boundary cube wireframe
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(BLACK);
    glTranslatef(0.0f, 0.0f, 0.0f);
    glutWireCube(9.0f);

    // Make graphics buttery
	glutSwapBuffers();
}
