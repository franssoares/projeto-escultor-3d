#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief Nesse módulo de cabeçalho é declarado os métodos para os membros da classe PutVoxel.
 * 
 * @return Vai receber o fluxo de uma estrutura voxel.
 */
class PutVoxel : public FiguraGeometrica{

private:

    int x, y, z;
    float r, g, b, a;

public:

    /**
     * @brief Construtor da classe PutVoxel.
     * @param x valor de x.
     * @param y valor de y.
     * @param z valor de z.
     * @param r cor vermelha.
     * @param g cor verde.
     * @param b cor azul.
     * @param a transparência.
     */
    PutVoxel(int x, int y, int z, float r, float g, float b, float a);

    /**
     * @brief Destrutor da classe PutVoxel.
     */
    ~PutVoxel();

    /**
     * @brief Função membro virtual para o desenho da figura.
     * @param t recebe por referência uma instância para a classe Sculptor.
     */
    void draw(Sculptor &t); //é necessário definir

};

#endif //PUTVOXEL_H