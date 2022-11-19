
<p align="center">
    <img width="75" height="75" src = "src/assets/readme/rubik.png">
    
</p>
    <h1 align="center"> Projeto Escultor 3D </h1>


---

![Badge em Desenvolvimento](http://img.shields.io/static/v1?label=STATUS&message=EM%20DESENVOLVIMENTO&color=GREEN&style=for-the-badge)  ![GitHub repo size](https://img.shields.io/github/repo-size/franssoares/Projeto-Escultor-3D?style=for-the-badge)    ![GitHub](https://img.shields.io/github/license/Franssoares/Projeto-Escultor-3D?style=for-the-badge)

# Índice 

* [Indrodução](#introdução)
* [Parte 1](#parte-1)
* [Parte 2](#parte-2)
* [Documentação](#documentação)
* [Atribuições](#atribuições)
* [Licença](#licença)


### Progresso

- :white_check_mark: Parte 1
- :white_check_mark: Parte 2

### Introdução
A idéia desse projeto é criar uma ferramenta, na linguagem C++, capaz de fazer esculturas 3D apartir de matrizes digitais. O projeto consiste em dois módulos: uma classe em C++ destinada à interpretação de um arquivo em formato de texto simples e geração das matrizes tridimensionais; e uma ferramenta visual para desenho, algo equivalente a um Paint 3D.

### Parte 1
Nessa primeira parte foram desenvolvidas ferramentas capazes de fazer esculturas 3D levando em consideração o estudo das classes em C++ e da alocação dinâmica de memória. 

A criação da classe `Sculptor`, da estrutura `struct`, assim como a implementação do arquivo `.off`, podem ser acessados [aqui](https://github.com/franssoares/Projeto-Escultor-3D/tree/main/parte1). O objeto de referência que vamos esculpir, nesse primeira etapa, será o troféu da copa do mundo da FIFA.


<br>

<p align="center">
    <b>Troféu da Copa do Mundo FIFA</b>
</p>

<p align="center">
    <img 
    width="280" 
    height="380"
    src="src\assets\readme\trofeu.png">
</p>

<p align="center">
    <a  
        href="https://www.r7.com/B1nQ" 
        tittle= "Troféu da copa do mundo FIFA">link da imagem 
        </a>
    por Edu Garcia/R7.
</p>

<br>


**Conhecimentos necessários:**
- Alocação dinâmica de memória.
- Programação modular.
- Criação de `struct`.
- Criação de `class`.
- Manipulação de dados em arquivo `.off`.


<br>

<p align="center">
    <b>Escultura 3D (PNG)</b>
</p>
<p align="center">
    <img 
    width="500" 
    height="340" 
    src = "src/assets/readme/snapshot02.png">
</p>

<br>

<p align="center">
    <b>Escultura 3D (GIF)</b>
</p>
<p align="center">
    <img 
    width="470" 
    height="300" 
    src = "src/assets/readme/imagem.gif">
</p>

<br>


Para visualizar a utilização dos membros da classe `Sculptor` e da estrutura `Voxel`, acesse a documentação [aqui](#documentação).

### Parte 2

A segunda parte do projeto deverá ser capaz de tratar classes abstratas para manipulação de figuras geométricas simples, realizando operações de desenho em uma matriz de pontos.

Para isso, a estrutura criada para a classe `Sculptor` deverá ser repensada e uma nova classe chamada `FiguraGeometrica` entrará como participante do processo de desenho.

Não serão criados objetos dessa nova classe, mas ela agora será a base para várias outras classes concretas, que proverão funcionalidades semelhantes àquelas providas pela classe `Sculptor` do projeto anterior. A implementação da parte 2 pode ser visualizada [aqui](https://github.com/franssoares/Projeto-Escultor-3D/tree/main/parte2).

A classe `Interpretador` irá ler um arquivo de texto `entrada.txt` e retornar um
fluxo de literais e números para a análise das respectivas classes de `FiguraGeometrica`.


**Arquivo de texto:**

``` txt
dim 100 100 100
putbox 0 99 0 99 0 0 0 0.5 0 1
putbox 43 57 43 57 1 40 0.4 0.2 0 1
cutbox 33 56 44 56 1 39
putellipsoid 50 50 41 6 6 1 1 1 0 1
putellipsoid 50 50 42 6 6 1 1 1 0 1
putellipsoid 50 50 43 6 6 2 0 0.4 0 1
putellipsoid 50 50 45 5 5 1 1 1 0 1
putellipsoid 50 50 46 5 5 1 0 0.4 0 1
putbox 48 52 48 52 47 62 1 1 0 0.8
putellipsoid 50 50 55 4 5 9 1 1 0 0.8
putellipsoid 50 50 55 5 4 9 1 1 0 0.8
putsphere 50 50 62 6 1 1 0 0.8
cutellipsoid 50 50 64 4 9 6
cutellipsoid 50 50 64 9 4 6
putsphere 50 50 63 5 1 1 0 0.8
putsphere 1 1 1 1 1 1 1 1
cutsphere 1 1 1 1
cutvoxel 0 0 0
putvoxel 0 0 0 0 0.5 0 1
putvoxel 1 1 0 0 0.5 0 1
```

A classe `interpretador` irá lançar no final do procedimento de conversão um arquivo de saida, `saida.off`. Esse mesmo arquivo `.off`, ao abrir no MeshLab, mostra a escultura do troféu da copa do mundo da FIFA.

### Documentação

* **Documentação da Parte 1** ([aqui](https://franssoares.github.io/parte1/))
* **Documentação da Parte 2** ([aqui](https://franssoares.github.io/parte2/))

### Atribuições
* **Logo:** <a href="https://www.flaticon.com/free-icons/rubik" title="rubik icons">Rubik icons created by Freepik - Flaticon</a>
* **Site:** O projeto escultor 3D se encontra em <a href="https://agostinhobritojr.github.io/curso/progav-dca1202/escultor.html" title="site do professor">agostinho.github.io</a>.

---
### Licença

Projeto Escultor 3D é [Creative Commons Zero v1.0 Universal](https://github.com/Franssoares/Projeto-Escultor-3D/blob/main/license).