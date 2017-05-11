#ifndef __GRAPHICS__
#define __GRAPHICS__

#define WHITE 1.0f, 1.0f, 1.0f
#define BLACK 0.0f, 0.0f, 0.0f
#define RED 1.0f, 0.0f, 0.0f
#define GREEN 0.0f, 1.0f, 0.0f
#define BLUE 0.0f, 0.0f, 1.0f
#define YELLOW 1.0f, 1.0f, 0.0f

void processNormalKeys(unsigned char, int, int);
void processSpecialKeys(int, int, int);

void changeSize(int, int);
void renderScene(void);

#endif
