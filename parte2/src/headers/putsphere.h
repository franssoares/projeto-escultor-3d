#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief Nesse módulo de cabeçalho é declarado os métodos para os membros da classe PutSphere.
 * 
 * @return Vai receber o fluxo de uma estrutura esfera.
 */
class PutSphere : public FiguraGeometrica{

private:

    int x0, y0, z0;
    float raio, r, g, b, a;

public:

    //Construtore e destrutor da classe PutSphere
    /**
     * @brief Construtor da classe PutSphere.
     * @param x0 centro em x.
     * @param y0 centro em y.
     * @param z0 centro em z.
     * @param raio raio da esfera.
     * @param r cor vermelha.
     * @param g cor verde.
     * @param b cor azul.
     * @param a transparência.
     */
    PutSphere(int x0, int y0, int z0, float raio, float r, float g, float b, float a);

    /**
     * @brief Destrutor da classe PutSphere.
     */
    ~PutSphere();

    /**
     * @brief Função membro virtual para o desenho da figura.
     * @param t recebe por referência uma instância para a classe Sculptor.
     */
    void draw(Sculptor &t);

};

#endif //PUTSPHERE_H