#ifndef CUTBOX_H
#define CUTBOX_H
#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief Classe que vai colocar Voxels dentro de um intervalor.   
 */
class CutBox : public FiguraGeometrica{

private:

    int x0, x1, y0, y1, z0, z1;

public:
    /**
     * @brief Construtore da classe PutBox.
     * @param x0 valor inicial em x.
     * @param x1 valor final em x.
     * @param y0 valor inicial dem y.
     * @param y1 valor final em y.
     * @param z0 valor inicial em z.
     * @param z1 valor final em z.
     */
    CutBox(int x0, int x1, int y0, int y1, int z0, int z1);

    /**
     * @brief Destrutor da classe PutBox.
     */
    ~CutBox();
    
    /**
     * @brief Função membro virtual para o desenho da figura.
     * @param t recebe por referência uma instância para a classe Sculptor.
     */
    void draw(Sculptor &t);

};

#endif //CUTBOX_H