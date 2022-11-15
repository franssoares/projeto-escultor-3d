#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief Nesse módulo de cabeçalho é declarado os métodos para os membros da classe CutSphere.
 * 
 * @return Vai receber o fluxo de uma estrutura esfera.
 */
class CutSphere : public FiguraGeometrica{

private:
    
    int x0, y0, z0;
    float raio;

public:

    /**
     * @brief Construtor com argumentos da classe CutSphere.
     * @param x0 centro em x.
     * @param y0 centro em y.
     * @param z0 centro em z.
     * @param raio raio da esfera
     */
    CutSphere(int x0, int y0, int z0, float raio);

     /**
     * @brief Destrutor da classe CutSphere.
     */
    ~CutSphere();

    /**
     * @brief Função membro virtual para o desenho da figura.
     * @param t recebe por referência uma instância para a classe Sculptor.
     */
    void draw(Sculptor &t); //é necessário definir

};

#endif //CUTSPHERE_H