#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "sculptor.h"


/**
 * @brief Nesse módulo de cabeçalho é declarado os métodos para os membros da classe FiguraGeometrica.
 * 
 * @return é uma classe abstrata.
 */
class FiguraGeometrica{

public:

    /**
     * @brief Função membro virtual, todas as classes definiram essa membro virtual. com argumentos da classe CutVoxel.
     * @param t recebe por referência uma instância para a classe Sculptor.
     */
    virtual void draw(Sculptor &t)=0; //método de desenho da classe abstrata

};

#endif //FIGURAGEOMETRICA_H