#ifndef SCULPTOR_H
#define SCULPTOR_H
#include "voxel.h"
#include <fstream>

/**
 * @brief Nesse módulo de cabeçalho é declarado os métodos para os membros da classe Sculptor.
 */

class Sculptor{

private:

    Voxel ***v; //matriz 3d;

    int nx,ny,nz; //dimensões;

    float r,g,b,a; //Cor de pintura atual do voxel;

public:

    /**
     * @brief Construtor de argumentos da classe Sculptor.
     * @param _nx largura da matriz em x.
     * @param _ny comprimento da matriz em y.
     * @param _nz altura da matriz em z.
     * 
     */
    Sculptor(int _nx, int _ny, int _nz); //

    /**
     * @brief Destrutor da classe Sculptor.
     */
    ~Sculptor(); //destrutor da classe;

    /**
     * @brief Configura a cor e transparência do voxel.
     * 
     * @param r cor vermelho.
     * @param g cor verde.
     * @param b cor azul.
     * @param a transparência.
     */
    void setColor(float r, float g, float b, float a); //define a cor atual do desenho;

    /**
     * @brief Ativa o voxel na posição (x,y,z) e atribui, ao mesmo, a cor atual de desenho.
     * 
     * @param x posição na x da matriz.
     * @param y posição na y da matriz.
     * @param z posição na z da matriz.
     */
    void putVoxel(int x, int y, int z); //Ativa o voxel na posição (x,y,z) (fazendo isOn = true) e atribui ao mesmo a cor atual de desenho;

    /**
     * @brief Desativa o voxel na posição (x,y,z).
     * 
     * @param x posição x da matriz.
     * @param y posição y da matriz.
     * @param z posição z da matriz.
     */
    void cutVoxel(int x, int y, int z); //Desativa o voxel na posição (x,y,z) (fazendo isOn = false);

    /**
     * @brief Ativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1] e atribui, aos mesmos, a cor atual do desenho.
     * 
     * @param x0 x inicial.
     * @param x1 x final.
     * @param y0 y inicial.
     * @param y1 y final.
     * @param z0 z inicial.
     * @param z1 z final.
     */
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1); //Ativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1] e atribui aos mesmos a cor atual de desenho;

    /**
     * @brief Desativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1] e atribui os voxels selecionados a cor atual do desenho.
     * 
     * @param x0 x inicial.
     * @param x1 x final.
     * @param y0 y inicial.
     * @param y1 y final.
     * @param z0 z inicial.
     * @param z1 z final.
     */
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1); //Desativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1] e atribui aos mesmos a cor atual do desenho;

    /**
     * @brief Ativa todos os voxels que satisfazem a equação da esfera e atribui, aos mesmos, a cor atual do desenho (r,g,b,a).
     * 
     * @param xcenter posição do centro da esfera em x.
     * @param ycenter posição do centro da esfera em y.
     * @param zcenter posição do centro da esfera em z.
     * @param radius raio da esfera.
     */
    void putSphere(int xcenter, int ycenter, int zcenter, int radius); //Ativa todos os voxels que satisfazem a equação da esfera e atribui aos mesmos a cor atual de desenho (r,g,b,a);

    /**
     * @brief Desativa todos os voxels que satisfazem a equação da esfera.
     * 
     * @param xcenter posição do centro da efera em x.
     * @param ycenter posição do centro da esfera em y.
     * @param zcenter posição do centro da esfera em z.
     * @param radius raio da esfera.
     */
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius); //Desativa todos os voxels que satisfazem a equação da esfera;

    /**
     * @brief Ativa todos os voxels que satisfazem a equação do elipsoide e atribui, aos mesmos, a cor atual de desenho.
     * 
     * @param xcenter posição do centro do elipsoide em x.
     * @param ycenter posição do centro do elipsoide em y.
     * @param zcenter posição do centro do elipdoide em z.
     * @param rx raio do elipsoide em x.
     * @param ry raio do elipsoide em y.
     * @param rz raio do elipsoide em z.
     */
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz); //Ativa todos os voxels que satisfazem a equação do elipsoide e atribui aos mesmos a cor atual de desenho;

    /**
     * @brief Desativa todos os voxels que satisfazem a equação do elipsoide.
     * 
     * @param xcenter posição do centro do elipsoide em x.
     * @param ycenter posição do centro do elipsoide em y.
     * @param zcenter posição do centro do elipdoide em z.
     * @param rx raio do elipsoide em x.
     * @param ry raio do elipsoide em y.
     * @param rz raio do elipsoide em z.
     */
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz); //Desativa todos os voxels que satisfazem a equação do elipsoide;

    /**
     * @brief Grava a escultura no formato (.off) no arquivo filename.
     * 
     * @param filename ponteiro para char que aponta para o endereço do nome do arquivo (.off). 
     */
    void writeOFF(const char* filename); //Grava a escultura no formato OFF no arquivo filename;

};

#endif // SCULPTOR_H