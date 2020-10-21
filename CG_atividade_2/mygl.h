#ifndef MYGL_H
#define MYGL_H

#include <stdlib.h>
#include <string.h>

#include "core.h"

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

void InitMyGl(void); // Inicializa o frame buffer 
unsigned char* GetFBMemPtr(void); // Retorna o ponteiro do framebuffer buffer
void CloseMyGl(void); // Desaloca a memória do framebuffer
void MyGlDraw(void); // Declaração da função que chamará as funções implementadas
void PutPixel(PIXEL p); // Modifica um píxel
void DrawLine(PIXEL p1, PIXEL p2); // Faz uma linha conectando dois píxels
void DrawTriangle(PIXEL p1, PIXEL p2, PIXEL p3); // Faz um triângulo conectando três píxels
// Adicionais
double raiz(double numero); // Calcula a raiz quadrada
void GradienteVertical(PIXEL p1, PIXEL p2, int e); // Faz um gradiente de cores na Vertical
void GradienteHorizontal(PIXEL p1, PIXEL p2, int e);	// Faz um gradiente de cores na Horizontal
void GradienteCruzado(PIXEL p1, PIXEL p2, PIXEL p3, PIXEL p4, int e); // Faz um gradiente cruzado de quatro cores

#endif  // MYGL_H
