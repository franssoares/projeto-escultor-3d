#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "headers/interpretador.h"
#include "headers/figurageometrica.h"
#include "headers/sculptor.h"
#include "headers/putbox.h"
#include "headers/cutbox.h"
#include "headers/putvoxel.h"
#include "headers/cutvoxel.h"
#include "headers/putsphere.h"
#include "headers/cutsphere.h"
#include "headers/putellipsoid.h"
#include "headers/cutellipsoid.h"

//Construtor da classe interpretador
interpretador::interpretador(const char* in, const char* out){

    //nome do diretório
    entrada = in;
    saida = out;

    std::cout << std::endl << "Nomes dos arquivos recebido com sucesso! (" << entrada << " e " << saida << ")"<< std::endl << std::endl;

}

//Destrutor
interpretador::~interpretador(){std::cout << std::endl << "Arquivo .off gerado com sucesso!" << std::endl << "Abra assets/saida.txt para visualizar.";}

//Função para converter literais em chamadas de funções de classe
void interpretador::conversor(){
    
    int x, y, z;
    int x0, x1, y0, y1, z0, z1;
    float raio;
    float raiox, raioy, raioz;
    float r, g, b, a;
    
    std::ifstream fin;
    std::ofstream fout;

    //abrir fluxo
    fin.open(entrada);

    //condição que verifica o diretório do arquivo
    if(!fin.is_open()){

        std::cout << "erro: nao eh possivel acessar o caminho do arquivo." << std::endl;
        exit(1);

    }

    //campo de vetor
    std::vector <FiguraGeometrica *> fig;
    std::vector <FiguraGeometrica *>::iterator i;
    Sculptor *desenho;
    std::string passe;

    //copiar arquivo
    while(fin.good()){

        fin >> passe;
        std::cout << passe << std::endl;

        if(!fin.good()){

            break;

        } 

        if(passe.compare("dim") == 0){

            fin >> x >> y >> z;
            std::cout << x << " " << y << " " << z << std::endl;
            desenho = new Sculptor(x,y,z);

        }

        //PutVoxel
        if(passe.compare("putvoxel") == 0){
            
            fin >> x >> y >> z >> r >> g >> b >> a;  
            std::cout << x << " " << y << " " << z << " " << r << " " << g << " " << b << " " << a << std::endl;
            fig.push_back(new PutVoxel(x,y,z,r,g,b,a));

        }

        //cutVoxel
        if(passe.compare("cutvoxel") == 0){

            fin >> x >> y >> z;
            std::cout << x << " " << y << " " << z << std::endl;
            fig.push_back(new CutVoxel(x,y,z));

        }

        //PutBox
        if(passe.compare("putbox") == 0){

            fin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
            std::cout << x0 << " " << x1 << " " << y0 << " " << y1 << " " << z0 << " " << z1 << " " << r << " " << g << " " << b << " " << a << std::endl;
            fig.push_back(new PutBox(x0,x1,y0,y1,z0,z1,r,g,b,a));

        }

        //CutBox
        if(passe.compare("cutbox") == 0){

            fin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
            std::cout << x0 << " " << x1 << " " << y0 << " " << y1 << " " << z0 << " " << z1 << std::endl;
            fig.push_back(new CutBox(x0,x1,y0,y1,z0,z1));

        }

        //PutSphere
        if(passe.compare("putsphere") == 0){

            fin >> x0 >> y0 >> z0  >> raio >> r >> g >> b >> a;
            std::cout << x0 << " " << y0 << " " << z0 << " " << raio << " " << r << " " << g << " " << b << " " << a << std::endl;
            fig.push_back(new PutSphere(x0,y0,z0,raio,r,g,b,a));

        }

        //CutSphere
        if(passe.compare("cutsphere") == 0){

            fin >> x0 >> y0 >> z0  >> raio;
            std::cout << x0 << " " << y0 << " " << z0 << " " << raio << std::endl;
            fig.push_back(new CutSphere(x0,y0,z0,raio));

        }

        //PutEllipsoid
        if(passe.compare("putellipsoid") == 0){

            fin >> x0 >> y0 >> z0  >> raiox >> raioy >> raioz >> r >> g >> b >> a;
            std::cout << x0 << " " << y0 << " " << z0 << " " << raiox << " " << raioy << " " << raioz << " " << r << " " << g << " " << b << " " << a << std::endl;
            fig.push_back(new PutEllipsoid(x0,y0,z0,raiox,raioy,raioz,r,g,b,a));

        }
        //CutEllipsoid
        if(passe.compare("cutellipsoid") == 0){

            fin >> x0 >> y0 >> z0  >> raiox >> raioy >> raioz;
            std::cout << x0 << " " << y0 << " " << z0 << " " << raiox << " " << raioy << " " << raioz << std::endl;
            fig.push_back(new CutEllipsoid(x0,y0,z0,raiox,raioy,raioz));

        }

    }

    //fechar fluxo
    fin.close();

    //desenhar
    for(auto i : fig){

        i->draw(*desenho);

    }

    desenho->writeOFF(saida);

    //liberar memória alocada dinâmicamente no vetor estruturado
    for(i = fig.begin(); i != fig.end(); i++){

        delete[] *i;

    }

}