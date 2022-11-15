#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief Nesse módulo de cabeçalho é declarado os métodos para os membros da classe CutVoxel.
 * 
 * @return Vai receber o fluxo de uma estrutura voxel.
 */
class CutVoxel : public FiguraGeometrica{

private:
    
    int x, y, z;

public:

    /**
     * @brief Construtor com argumentos da classe CutVoxel.
     * @param x valor de x.
     * @param y valor de y.
     * @param z valor de z.
     */
    CutVoxel(int x, int y, int z);

     /**
     * @brief Destrutor da classe CutVoxel.
     */
    ~CutVoxel();

    /**
     * @brief Função membro virtual para o desenho da figura.
     * @param t recebe por referência uma instância para a classe Sculptor.
     */
    void draw(Sculptor &t); //é necessário definir (virtual)

};

#endif //CUTVOXEL_H