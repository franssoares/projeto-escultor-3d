#include <iostream>
#include "headers/interpretador.h"

/**
 * @brief Na função principal (código fonte) é definido os nomes do arquivo originário e do arquivo convertido em .off.
 * 
 * @return Procedimento 
 */

int main(void){

    interpretador arquivo("assets/entrada.txt", "assets/saida.off");

    arquivo.conversor();
    
}