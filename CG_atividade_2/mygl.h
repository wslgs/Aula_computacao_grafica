#ifndef MYGL_H
#define MYGL_H

#include <string.h>
#include <math.h>
#include "core.h"
#include "frame_buffer.h"

// Struct contendo características dos pixels.

typedef struct pixel
{
	int x;
	int y;
	double r;
	double g;
	double b;
	double a;
}PIXEL;

// Struct contendo a quantidade da variação da cor do píxel por ponto.

typedef struct step
{
	double r;
	double g;
	double b;
	double a;
}STEP;

void MyGlDraw(void);
void PutPixel(PIXEL p);
void DrawLine(PIXEL p1, PIXEL p2);
void DrawTriangle(PIXEL p1, PIXEL p2, PIXEL p3);

#endif  // MYGL_H
