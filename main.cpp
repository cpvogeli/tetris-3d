#include <Windows.h>
#include <GL/glut.h>

#include "game.h"
#include "piece.h"
#include "graphics.h"

int main(int argc, char **argv) {
	//Initialize GLUT and window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(1200, 800);
	glutCreateWindow("Tetris 3D");

	gameInit();

	//Register functions
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);

	// Get the party started
	glutMainLoop();

	return 1;
}
