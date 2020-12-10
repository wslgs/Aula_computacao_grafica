# Computação gráfica
## Atividade 3
#### Teste de programa:
![](https://cdnb.artstation.com/p/assets/images/images/032/823/153/large/weslley-gomes-dantas-foto-1.jpg?1607568074)
#### Exercício 1 : Escalas
```
float model_array[16] = {((float)1/3), 0.0f, 0.0f, 0.0f, 
                          0.0f, ((float)3/2), 0.0f, 0.0f, 
                          0.0f, 0.0f, 1.0f, 0.0f, 
                          0.0f, 0.0f, 0.0f, 1.0f};
```
                   
![](https://cdnb.artstation.com/p/assets/images/images/032/823/155/large/weslley-gomes-dantas-foto-2.jpg?1607568078)
#### Exercício 2 : Translação
```
float model_array[16] = {1.0f, 0.0f, 0.0f, 0.0f, 
                         0.0f, 1.0f, 0.0f, 0.0f, 
                         0.0f, 0.0f, 1.0f, 0.0f, 
                         1.0f, 0.0f, 0.0f, 1.0f};
```
![](https://cdna.artstation.com/p/assets/images/images/032/823/158/large/weslley-gomes-dantas-foto-3.jpg?1607568081)
#### Exercício 3 : Projeção Perspectiva
```
float proj_array[16] = {1.0f, 0.0f, 0.0f, 0.0f, 
                        0.0f, 1.0f, 0.0f, 0.0f, 
                        0.0f, 0.0f, 1.0f, ((float)-8), 
                        0.0f, 0.0f, ((float)1/8), 0.0f};
```
![](https://cdnb.artstation.com/p/assets/images/images/032/823/159/large/weslley-gomes-dantas-foto-4.jpg?1607568086)
#### Exercício 4: Posição da Câmera
```
float bt_array[16] = { 1.1f,  0.01f,  -0.1f,   0.0f, 
                       0.0f,  1.22f,   0.1f,   0.0f, 
                       0.1f,  -0.11f,  1.1f,   0.0f, 
                       0.0f,  0.0f,    0.0f,   1.0f};
glm::mat4 bt_mat = glm::make_mat4(bt_array);
    
float t_array[16] = {1.0f,  0.0f,  0.0f, 0.0f, 
                     0.0f,  1.0f,  0.0f, 0.0f, 
                     0.0f,  0.0f,  1.0f, 0.0f, 
                     0.1f, -0.1f, -0.1f, 1.0f};
glm::mat4 t_mat = glm::make_mat4(t_array);

glm::mat4 view_mat = bt_mat * t_mat;
```
![](https://cdnb.artstation.com/p/assets/images/images/032/823/163/large/weslley-gomes-dantas-foto-5.jpg?1607568089)
#### Exercício 5: Transformações Livres
```
float model_array[16] = {2.0f, 0.0f, 0.0f, 0.0f, 
                         0.0f, ((float)1/4), 0.0f, 0.0f, 
                         0.0f, 0.0f, 2.0f, 0.0f, 
                         0.0f, 0.0f, 0.0f, 1.0f};
glm::mat4 model_mat = glm::make_mat4(model_array);

float view_array[16] = {2.0f, 0.0f, -1.0f, 0.0f, 
                        0.0f, 1.0f, 0.0f, 0.0f, 
                        0.0f, 0.0f, 2.0f, 0.0f, 
                        -1.0f, 0.0f, 0.0f, 1.0f};

glm::mat4 view_mat = glm::make_mat4(view_array);

float proj_array[16] = {1.0f, 0.0f, 0.0f, 0.0f, 
                        0.0f, 1.0f, 0.0f, 0.0f, 
                        0.0f, 0.0f, 1.0f, ((float)-6), 
                        0.0f, 0.0f, ((float)1/6), 1.0f};

glm::mat4 proj_mat = glm::make_mat4(proj_array);
```
![](https://cdna.artstation.com/p/assets/images/images/032/823/166/large/weslley-gomes-dantas-foto-6.jpg?1607568092)
