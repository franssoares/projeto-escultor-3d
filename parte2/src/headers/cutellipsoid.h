#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief Nesse módulo de cabeçalho é declarado os métodos para os membros da classe CutEllipsoid.
 * 
 * @return Vai receber o fluxo de uma estrutura elipsoide
 */
class CutEllipsoid : public FiguraGeometrica{

private:

    int x0, y0, z0;
    float raiox, raioy, raioz;

public:

    /**
     * @brief Construtor com argumentos da classe CutEllipsoid.
     * @param x0 centro em x.
     * @param y0 centro em y.
     * @param z0 centro em z.
     * @param raiox raio em x.
     * @param raioy raio em y.
     * @param raioz raui em z.
     */
    CutEllipsoid(int x0, int y0, int z0, float raiox,float raioy,float raioz);

    /**
     * @brief Destrutor da classe CutEllipsoid.
     */
    ~CutEllipsoid();

    /**
     * @brief Função membro virtual para o desenho da figura.
     * @param t recebe por referência uma instância para a classe Sculptor.
     */
    void draw(Sculptor &t);

};

#endif //CUTELLIPSOID_H