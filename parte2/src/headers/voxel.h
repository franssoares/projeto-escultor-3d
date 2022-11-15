#ifndef VOXEL_H
#define VOXEL_H

/**
    * @brief Nesse módulo de cabeçalho é decladado as propriedades da matriz_objeto.
    * @details As propriedades são: RGB, transparência alpha e o isOn.
*/

struct Voxel{

    /**
     * @brief valor real da propriedade vermelho.
     */
    float r; 
    
    /**
     * @brief valor real da propriedade verde.
     */
    float g;
    
    /**
     * @brief valor real da propriedade azul.
     */
    float b;
    
    /**
     * @brief valor real da propriedade de tranparência.
     */
    float a;
    
    /**
     * @brief booleano que recebe a propriedade de voxel ligado/desligado.
     */
    bool isOn; //1 = true, 0 = false;

};

#endif //VOXEL_H
