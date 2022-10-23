#include <iostream>
#include "sculptor.h"

/**
 * @brief Na função principal (código fonte) é chamado os valores da dimensão da matriz e as chamadas dos membros da classe Sculptor.
 * 
 * @return Procedimento 
 */
int main(){

    //implementação final, aqui se pede o tamanho da matriz_objeto;
    //std::cout << "Informe o tamanho do espaço tridimensional:" << std::endl;
    //std::cin >> tamx >> tamy >> tamz;

    float ft = 1; //FATOR ESPACIAL
    int tamx = ft*100, tamy = ft*100, tamz = ft*100;
    Sculptor matriz_objeto(tamx, tamy, tamz); //construtor de argumentos
    std::cout << "Calculando..." << std::endl;
    
    /*
        plano xy
    */    
    matriz_objeto.setColor(0,0.5,0,1);
    matriz_objeto.putBox(ft*0,ft*99,ft*0,ft*99,ft*0,ft*0); //plano(z,y,z)
   
    /*
        Mesa
    */    
    matriz_objeto.setColor(0.4,0.2,0,1); //cor cinza
    matriz_objeto.putBox(43,57,43,57,1,40); //caixa(x0,x,y0,y,z0,z)
    matriz_objeto.cutBox(44,56,44,56,1,39); //cortar_caixa(x0,x,y0,y,z0,z)

    /*
        Taça da copa do mundo
    */    
    //base 1
    matriz_objeto.setColor(1,1,0,1); //cor amarela
    matriz_objeto.putEllipsoid(ft*50,ft*50,ft*41,ft*6,ft*6,ft*1); //elipsoide(x,y,z,rx,ry,rz)
    matriz_objeto.putEllipsoid(ft*50,ft*50,ft*42,ft*6,ft*6,ft*1); //elipsoide(x,y,z,rx,ry,rz)
   
    //base 2
    matriz_objeto.setColor(0,0.4,0,1); //cor verde
    matriz_objeto.putEllipsoid(ft*50,ft*50,ft*43,ft*6,ft*6,ft*2); //elipsoide(x,y,z,rx,ry,rz)
     
    //base 3
    matriz_objeto.setColor(1,1,0,1); //cor amarela
    matriz_objeto.putEllipsoid(ft*50,ft*50,ft*45,ft*5,ft*5,ft*1); //elipsoide(x,y,z,rx,ry,rz)
    
    //base 4
    matriz_objeto.setColor(0,0.4,0,1); //cor verde
    matriz_objeto.putEllipsoid(ft*50,ft*50,ft*46,ft*5,ft*5,ft*1); //elipsoide(x,y,z,rx,ry,rz)
    
    //sec 0 - tronco da taça
    matriz_objeto.setColor(1,1,0,0.8); //cor amarela
    matriz_objeto.putBox(ft*48,ft*52,ft*48,ft*52,ft*47,ft*62); //caixa(x0,x,y0,y,z0,z)
    
    //sec 2 - s1
    matriz_objeto.setColor(1,1,0,0.8); //cor amarela
    matriz_objeto.putEllipsoid(ft*50,ft*50,ft*55,ft*4,ft*5,ft*9); //elipsoide(x,y,z,rx,ry,rz)
   
    //sec 3 - s2
    matriz_objeto.putEllipsoid(ft*50,ft*50,ft*55,ft*5,ft*4,ft*9); //elipsoide(x,y,z,rx,ry,rz)
    
    //globo 1
    matriz_objeto.putSphere(ft*50,ft*50,ft*62,ft*6); //esfera(x,y,z,r) 

    //remover
    matriz_objeto.cutEllipsoid(ft*50,ft*50,ft*64,ft*4,ft*9,ft*6);
    matriz_objeto.cutEllipsoid(ft*50,ft*50,ft*64,ft*9,ft*4,ft*6);

    //globo 2
    matriz_objeto.putSphere(ft*50,ft*50,ft*63,ft*5); //esfera(x,y,z,r)

    /*
        Gerar arquivo.off
    */
    matriz_objeto.writeOFF("objeto3d.off"); //arquivo 
    
    return 0;

}