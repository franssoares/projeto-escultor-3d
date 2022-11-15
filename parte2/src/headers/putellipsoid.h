#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief Nesse módulo de cabeçalho é declarado os métodos para os membros da classe PutEllipsoid.
 * 
 * @return Vai receber o fluxo de uma estrutura celipsoid.
 */
class PutEllipsoid : public FiguraGeometrica{

private:

    int x0, y0, z0;
    float raiox, raioy, raioz, r, g, b, a;

public:

    /**
     * @brief Construtor da classe PutEllipsoid.
     * @param x0 centro em x.
     * @param y0 centro em y.
     * @param z0 centro em z.
     * @param raiox raio em x.
     * @param raioy raio em y.
     * @param raioz raio em z.
     * @param r cor vermelha.
     * @param g cor verde.
     * @param b cor azul.
     * @param a transparência.
     */
    PutEllipsoid(int x0, int y0, int z0, float raiox,float raioy,float raioz, float r, float g, float b, float a);

    /**
     * @brief Destrutor da classe PutEllipsoid.
     */
    ~PutEllipsoid();

    /**
     * @brief Função membro virtual para o desenho da figura.
     * @param t recebe por referência uma instância para a classe Sculptor.
     */
    void draw(Sculptor &t);

};

#endif //PUTELLIPSOID_H