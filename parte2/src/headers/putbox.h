#ifndef PUTBOX_H
#define PUTBOX_H
#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief Nesse módulo de cabeçalho é declarado os métodos para os membros da classe PutBox.
 * 
 * @return Vai receber o fluxo de uma estrutura caixa.
 */
class PutBox : public FiguraGeometrica{

private:

    int x0, x1, y0, y1, z0, z1;
    float r, g, b, a;

public:

    /**
     * @brief Construtore da classe PutBox.
     * @param x0 valor inicial em x.
     * @param x1 valor final em x.
     * @param y0 valor inicial dem y.
     * @param y1 valor final em y.
     * @param z0 valor inicial em z.
     * @param z1 valor final em z.
     * @param r cor vermelha.
     * @param g cor verde.
     * @param b cor azul.
     * @param a transparência.
     */
    PutBox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g, float b, float a);
    
    /**
     * @brief Destrutor da classe PutBox.
     */
    ~PutBox();

   /**
     * @brief Função membro virtual para o desenho da figura.
     * @param t recebe por referência uma instância para a classe Sculptor.
     */
    void draw(Sculptor &t);

};

#endif //PUTBOX_H