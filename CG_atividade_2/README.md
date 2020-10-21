# Computação Gráfica
## Rasterização Linear
Nesta atividade colocamos em prática a implementação dos algoritmos de rasterização de pontos e linhas.  
Utilizando a linguagem C, os cabeçalhos do *openGL* e a *GLUT*.
> O *framework* foi fornecido pelo professor.  

Arquivos que fazem parte da estrutura do *framework*:
- **core.h**
- **main.c**
- **main.h**
- **Makefile**
- **mygl.c**
- **mygl.h**  

O objetivo da atividade foi implementar as funções **PutPixel(...)**, **DrawLine(...)** e **DrawTriangle(...)** no **mygl.c** e **mygl.h**. A rasterização das linhas foi feito pelo **algoritmo do ponto médio**, de *Bresenham*, e as linhas foram coloridas através da interpolação linear das cores *RGBA* dos vértices.  
Inicialmente criei o ``struct pixel`` que contém a coordenada X, coordenada Y, intensidade do vermelho, intensidade do verde, intensidade do azul e intensidade do alpha.
### PutPixel(...)
A função ``PutPixel(...)`` recebe um dado do tipo ***pixel*** com todas as informações dele. Para localizar esse píxel na tela eu transformei suas coordenadas em um número de identificação, esse número parte do píxel ``(0,0)`` e vai até o píxel ``(IMAGE_WIDTH,IMAGE_WEIGHT)``.  
Contando com o fato de que cada píxel tem quatro endereços no array do framebuffer ``fb_ptr[a]``, a fórmula para encontrar o número de identificação ``a`` de um ``struct pixel p`` com as coordenadas **p(x,y)** foi a seguinte:
```
a = (IMAGE_WIDTH * p.y + p.x) * 4; 
```  
Agora é possível acessar o píxel **p(x,y)** e alterar sua cor com o framebuffer. Na imagem a seguir exemplifiquei o uso da função ``void PutPixel(PIXEL p)``, gerando seis píxels:

![](https://cdnb.artstation.com/p/assets/images/images/031/304/973/large/weslley-gomes-dantas-foto-1.jpg?1603224832)
### DrawLine(...)
A função ``DrawLine(...)`` recebe dois parâmetros do tipo ***pixel***(p1 e p2) e fará uma ligação entre eles utilizando outros píxels em forma de reta.
O algoritmo de *Bresenham* funciona com retas cujo coeficiente de inclinação é positivo e que o ponto inicial é menor que o final. Utilizei funções que trabalharam simetricamente para que essa reta formada fosse tratada como uma reta padrão que se encaixasse no algoritmo. O ``s`` serviu para identificar a inclinação da reta e aplicar de forma adequada o *algoritmo do ponto médio*.  
Aqui um exemplo da aplicação do algoritmo em caso de uma reta negativa ``s < 0``:
```
if(d < 0)
{
  d+= 2 * (dy + dx);
  p.y--;
}else
	d+= 2 * dy;
p.x++;
```
Ele decide o píxel que vai em seguida dependendo da variável de decisão ``d``, incrementa o ``p.x`` e decrementa o ``p.y`` se o ``d < 0``.  

A cor *RGBA* foi tratada com a interpolação linear entre as cores dos vértices dos píxels **p1 e p2**. O crescimento de cada cor foi armazenado no ``struct step`` e ele foi calculado da seguinte forma:  Calculei a distância entre os pontos com o auxílio da função ``raiz()`` e usei o resultado para dividir a quantidade que as cores variam no total, recebendo o valor que cada cor varia a cada ponto. Exemplo da cor vermelha:
```
double h = raiz (dx * dx + dy * dy);
step.r = (p2.r - p1.r) / h;
```
Logo após aplico píxels na função ``void DrawLine(PIXEL p1, PIXEL p2)`` e consigo gerar retas aplicando os algoritmos nos parâmetros fornecidos.

![](https://cdna.artstation.com/p/assets/images/images/031/304/978/large/weslley-gomes-dantas-foto-2.jpg?1603224835)
### DrawTriangle(...)
Esta função recebe três píxels como parâmetro: ``void DrawTriangle(PIXEL p1, PIXEL p2, PIXEL p3)``. Para gerar o triângulo, apenas faço a ligação entre os pontos com a função ``DrawLine(...)`` e ela já aplica os algoritmos de rasterização. Ficando desta forma:

![](https://cdna.artstation.com/p/assets/images/images/031/304/980/large/weslley-gomes-dantas-foto-3.jpg?1603224838)
## Funções adicionais
Resolvi fazer três funções adicionais que utilizam a função ``Drawline()`` e obtive um resultado interessante fazendo um gradiente utilizando as cores dos píxels colocados como argumentos nas mesmas.  
São elas:
#### GradienteVertical(...)
``void GradienteVertical(PIXEL p1, PIXEL p2, int e)``, onde o ``int e`` é o distanciamento de píxels entre cada linha.  

![](https://cdna.artstation.com/p/assets/images/images/031/304/982/large/weslley-gomes-dantas-foto-4.jpg?1603224841)
#### GradienteHorizontal(...)
``void GradienteHorizontal(PIXEL p1, PIXEL p2, int e)``  

![](https://cdna.artstation.com/p/assets/images/images/031/304/984/large/weslley-gomes-dantas-foto-5.jpg?1603224845)
#### GradienteCruzado(...)
``void GradienteCruzado(PIXEL p1, PIXEL p2, PIXEL p3, PIXEL p4, int e)`` onde o ``e = 5``. 

![](https://cdna.artstation.com/p/assets/images/images/031/304/988/large/weslley-gomes-dantas-foto-6.jpg?1603224848)

Os píxels se sobrescrevem conforme a ordem que são colocados. Dessa maneira chamei a função ``void GradienteHorizontal(PIXEL p1, PIXEL p2, int e)`` e a função ``void DrawTriangle(PIXEL p1, PIXEL p2)``, consecutivamente, e obtive este resultado:  

![](https://cdnb.artstation.com/p/assets/images/images/031/304/989/large/weslley-gomes-dantas-foto-7.jpg?1603224851)  

Fiz o upload das fotos para a plataforma *ArtStation* para poder utilizar no README.md. Elas podem ser encontradas no seguinte link:  
[ArtStation - CG](https://www.artstation.com/artwork/ZGJ94G)  
> Ativididade feita com base nas aulas do Youtube, fornecidas pelo professor Christian Azambuja Pagot e conteúdos publicados na plataforma do SIGAA.
