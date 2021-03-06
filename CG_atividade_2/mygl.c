#include "mygl.h"

unsigned char* fb_ptr = NULL;

void InitMyGl(void)
{
    fb_ptr = (unsigned char *)malloc(IMAGE_WIDTH * IMAGE_HEIGHT * 4 * sizeof(char));	

    for (int i = 0; i < IMAGE_WIDTH * IMAGE_HEIGHT; ++i)
    {
        fb_ptr[i * 4] = 0;
        fb_ptr[i * 4 + 1] = 0;
        fb_ptr[i * 4 + 2] = 0;
        fb_ptr[i * 4 + 3] = 255;
    }    
}

unsigned char* GetFBMemPtr(void)
{
	return fb_ptr;
}

void CloseMyGl(void)
{
    if (!fb_ptr)
        free(fb_ptr);
}

double raiz(double numero)
{
	double r = numero;
	for(int i = 0; i < 10; ++i)
		r = r/2 + numero/(2*r);
	return(r);
}


void PutPixel(PIXEL p)
{

	// O inteiro 'a' servirá para encontrar a localização do ponto no array fb_ptr[n], não como uma matriz, mas como um conjunto de números que vai do ponto 0x0 = PrimeiroPíxel até o ponto IMAGE_WIDTHxIMAGE_HEIGHT = UltimoPíxel, contando com o fato que cada píxel tem 4 endereços no array determinando sua cor

	int a;
	a = (IMAGE_WIDTH * p.y + p.x) * 4; 
	
	// Nesta parte eu modifico a cor do píxel

	fb_ptr[a+0]  = p.r;
	fb_ptr[a+1]  = p.g;
	fb_ptr[a+2]  = p.b;
	fb_ptr[a+3]  = p.a;
}

void DrawLine(PIXEL p1, PIXEL p2)
{

	int d = 0, s = 0; // s: Inclinação da reta; d: Variável a ser utilizada no algoritmo de Bresenham
	PIXEL p;          // p: Píxel que percorrerá a reta que liga os pontos
	STEP step;        // step: Vai indicar a quantidade que cada cor deve variar por ponto
	
	int dx = p2.x - p1.x;		      // dx: Variação no eixo X
	int dy = p2.y - p1.y;		      // dy: Variação no eixo Y
	double h = sqrt (dx * dx + dy * dy); // h: Distância entre os pontos
	
	// Calculando a quantidade da variação de cada cor
	step.r = (p2.r - p1.r) / h;
	step.g = (p2.g - p1.g) / h;
	step.b = (p2.b - p1.b) / h;
	step.a = (p2.a - p1.a) / h;
	
	// Se X1>X2, invertemos os pontos
	if(dx < 0)
	{
		DrawLine(p2, p1);
		return;
	}
	
	// Se Y1>Y2, a inclinação da reta é negativa
	if(dy < 0)
		s = -1;
		
	// Se Y1<Y2, a inclinação da reta é negativa
	else
		s = 1;
	
	// p1 será onde o p iniciará a percorrer a reta
	p = p1;
	PutPixel(p);
	
	// Agora utilizo o algorítmo de Bresenham, determinando quando o píxel sobe ou desce, para formar a reta, e fazendo uma ligação gradiente entre os pontos com a interpolação linear das cores
	
	// Se o coeficiente de inclinação da reta for <= 0
	if(dx >= s * dy)
	{
		if(dy < 0)
		{
			d = 2 * dy + dx;
			while(p.x < p2.x)
			{
				if(d < 0)
				{
					d+= 2 * (dy + dx);
					p.y--;
				}else
					d+= 2 * dy;
				p.x++;
				p.r+= step.r;
				p.g+= step.g;
				p.b+= step.b;
				p.a+= step.a;
				PutPixel(p);
			}
		}else
		{
			d = 2 * dy - dx;
			while(p.x < p2.x)
			{
				if(d < 0)
					d+= 2 * dy;
				else
				{
					d+= 2 * (dy - dx);
					p.y++;
				}
				p.x++;
				p.r+= step.r;
				p.g+= step.g;
				p.b+= step.b;
				p.a+= step.a;
				PutPixel(p);
			}
		}	
	}
	// Se o coeficiente de inclinação da reta for >= 0
	else
	{
		if(dy < 0)
		{
			d = dy + 2 * dx;
			while(p.y > p2.y)
			{
				if(d < 0)
					d+= 2 * dx;
				else
				{
					d+= 2 * (dy + dx);
					p.x++; 
				}
				p.y--;
				p.r+= step.r;
				p.g+= step.g;
				p.b+= step.b;
				p.a+= step.a;
				PutPixel(p);
			}
		}else{
			d = dy - 2 * dx;
			while(p.y < p2.y)
			{
				if(d < 0)
				{
					d+= 2 * (dy - dx);
					p.x++;
				}else
					d+= -2 * dx;
				p.y++;
				p.r+= step.r;
				p.g+= step.g;
				p.b+= step.b;
				p.a+= step.a;
				PutPixel(p);
			}
		}
	}
	
	// Último píxel
	p.r+= step.r;
	p.g+= step.g;
	p.b+= step.b;
	p.a+= step.a;
	PutPixel(p2);
}

void DrawTriangle(PIXEL p1, PIXEL p2, PIXEL p3)
{

	// Aqui eu invoco a função DrawLine() para ligar os três pontos inseridos, com linhas
	DrawLine(p1, p2);
	DrawLine(p2, p3);
	DrawLine(p3, p1);
}

// GradienteHorizontal() pega a cor do pixel p1 e faz um gradiente horizontal até a cor do pixel p2, com um espaçamento 'e' entre as linhas
void GradienteHorizontal(PIXEL p1, PIXEL p2, int e)
{
	PIXEL pl, pr;
	
	pl.x = 0;
	pl.y = 0;
	pl.r = p1.r;
	pl.g = p1.g;
	pl.b = p1.b;
	pl.a = p1.a;
	
	pr.x = 511;
	pr.y = 0;
	pr.r = p2.r;
	pr.g = p2.g;
	pr.b = p2.b;
	pr.a = p2.a;
	
	for(int i = 0; i < IMAGE_HEIGHT; i++)
	{
		DrawLine(pl,pr);
		if(pl.y+e<=IMAGE_HEIGHT)
		{
			pl.y+= e;
			pr.y+= e;
		}
	}
}

// GradienteVertical() pega a cor do pixel p1 e faz um gradiente vertical até a cor do pixel p2, com um espaçamento 'e' entre as linhas
void GradienteVertical(PIXEL p1, PIXEL p2, int e)
{
	PIXEL pl, ph;
	
	pl.x = 0;
	pl.y = 0;
	pl.r = p1.r;
	pl.g = p1.g;
	pl.b = p1.b;
	pl.a = p1.a;
	
	ph.x = 0;
	ph.y = 511;
	ph.r = p2.r;
	ph.g = p2.g;
	ph.b = p2.b;
	ph.a = p2.a;
	
	for(int i = 0; i < IMAGE_WIDTH; i++)
	{
		DrawLine(pl,ph);
		if(pl.x+e<=IMAGE_WIDTH)
		{
			pl.x+= e;
			ph.x+= e;
		}
	}
}

void GradienteCruzado(PIXEL p1, PIXEL p2, PIXEL p3, PIXEL p4, int e)
{
	// Cruzamento dos gradientes vertical e horizontal com um espaçamento 'e'
	GradienteVertical(p1, p2, e);
	GradienteHorizontal(p3, p4, e);
}

void MyGlDraw(void)
{
    PIXEL pixel1, pixel2, pixel3, pixel4, pixel5;

	// Pixel 1	
	pixel1.x = 100;
	pixel1.y = 400;
	pixel1.r = 0;
	pixel1.g = 255;
	pixel1.b = 255;
	pixel1.a = 155;

	// Pixel 2	
	pixel2.x = 400;
	pixel2.y = 100;
	pixel2.r = 255;
	pixel2.g = 100;
	pixel2.b = 255;
	pixel2.a = 155;
	
	// Pixel 3
	pixel3.x = 20;
	pixel3.y = 349;
	pixel3.r = 255;
	pixel3.g = 204;
	pixel3.b = 124;
	pixel3.a = 255;
	
	// Pixel 4
	pixel4.x = 290;
	pixel4.y = 450;
	pixel4.r = 124;
	pixel4.g = 255;
	pixel4.b = 180;
	pixel4.a = 0;
	
	// Pixel 5	
	pixel5.x = 400;
	pixel5.y = 100;
	pixel5.r = 255;
	pixel5.g = 200;
	pixel5.b = 255;
	pixel5.a = 155;
	
	
	GradienteHorizontal(pixel1, pixel2, 1);
	DrawTriangle(pixel3, pixel4, pixel5);
}
