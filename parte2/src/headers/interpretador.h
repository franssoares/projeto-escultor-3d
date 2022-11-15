#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H
#include <iostream>
#include <fstream>
#include <sstream>
#include "sculptor.h"
#include "figurageometrica.h"

/**
 * @brief Nesse módulo de cabeçalho é declarado os métodos para os membros da Classe da ferramenta interpretador.
 * 
 * @return Vai receber o fluxo de uma estrutura esfera.
 */
class interpretador{

private:

    std::string entrada;
    const char* saida;

public:

    /**
     * @brief Construtor com argumentos da classe Interpretador.
     * @param fin literal de entrada.
     * @param fout caractere de saida.
     */
    interpretador(const char* fin,const char* fout);

    /**
     * @brief Destrutor da classe Interpretador.
     */
    ~interpretador(); //mudar depois

    /**
     * @brief Função membro que faz a conversão dos dados que entram em .off.
     */
    //Funções membros
    void conversor();

};

#endif //INTERPRETADOR_H