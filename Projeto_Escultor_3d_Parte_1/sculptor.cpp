#include <iostream>
#include "sculptor.h"
#include "voxel.h"
#include <fstream>
#include <iomanip>

/*

    - Nesse módulo é definida os membros da classe Sculptor;

*/

//construtor de argumanetos (alocação dinâmica e valores iniciais para os membros da classe Sculptor);
Sculptor::Sculptor(int tamx, int tamy, int tamz){
    
    //passagem das variáveis para os membros da classe e valores iniciais dos membros;
    nx = tamx; ny = tamy; nz = tamz; 
    r = g = b = a = 0.5; // -> inicialize no meio, mova depois;

    //alocação dinâmica de memória do membro 'Voxel v' da classe Sculptor;
    v = new Voxel**[nz]; 
    v[0] = new Voxel*[nz*nx]; 
    v[0][0] = new Voxel[nz*nx*ny];

    //fixação da alocação de memória da 'struct v';
    for(int k=1; k<nz; k++){

        v[k] = v[k-1] + nx;        

    }

    for(int i = 1; i<nz*nx; i++){

        v[0][i] = v[0][i-1] + ny;
        
    }
    
    std::cout << "Entrada recebida!" << std::endl;

    //a liberação de memória se encontra no destrutor da classe Sculptor;

}

//destrutor da classe Sculptor;
Sculptor::~Sculptor(){

    //liberação de memória do 'struct v';
    delete[] v[0][0];
    delete[] v[0];
    delete v;

    std::cout << "Arquivo (.off) pronto!" << std::endl;    

}

    /*

        -   FUNÇÕES DA CLASSE Sculptor;
    
    */

//define as propriedades (cores e transparência);
void Sculptor::setColor(float r, float g, float b, float a){

    //condição para pertencer ao intervalo [0;1];
    if((r >= 0 && r <= 1) || (g >= 0 && g <= 1) || (b >= 0 && b)){

        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;

    }
        
}

//colocar os valores das propriedades no voxel (fazendo isOn = true e atribui ao mesmo a cor atual de desenho);
void Sculptor::putVoxel(int x, int y, int z){

    v[z][x][y].r = this->r;
    v[z][x][y].g = this->g;
    v[z][x][y].b = this->b;
    v[z][x][y].a = this->a;
    v[z][x][y].isOn = true;

}

//Desativa o voxel na posição (x,y,z) (fazendo isOn = false);
void Sculptor::cutVoxel(int x, int y, int z){

    v[z][x][y].isOn = false;

}

//Ativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1] e atribui aos mesmos a cor atual de desenho;
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){

    //ferramenta para adicionar voxels de forma rápida;
    for(int k=z0; k<=z1; k++){

        for(int i=x0; i<=x1; i++){

            for(int j=y0; j<=y1; j++){

               Sculptor::putVoxel(i,j,k); //equivale a putVoxel(i,j,k) (?);
                    
            }
        
        }

    }

}

//Desativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1];
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){

    //ferramenta para remover voxels de forma rápida;
    for(int k=z0; k<=z1; k++){

        for(int i=x0; i<=x1; i++){

            for(int j=y0; j<=y1; j++){

               Sculptor::cutVoxel(i,j,k);;
                    
            }
        
        }

    }

}

//ferramenta para ativar todos os voxels (em esfera);
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){

    //parcelas da equação da esfera: (x-x0)² + (y-Y0)² + (z-Z0)² = r², onde x0, y0 e z0 são as coordenadas do centro da esfera;
    double px, py, pz;

    //k=0->nz, i=0->nx e j=0-> é o domínio da esfera; 
    for(int k=0; k<nz ; k++){

        for(int i=0; i<nx ;i++){

            for(int j=0; j<ny ;j++){

                px = double((i-xcenter)*(i-xcenter));
                py = double((j-ycenter)*(j-ycenter));
                pz = double((k-zcenter)*(k-zcenter));

                //definição da esfera(propriedade)
                if((px+py+pz)<=(radius*radius)){

                    Sculptor::putVoxel(i,j,k); //equivale a putVoxel(i,j,k) (?);

                }

            }

        }

    }

}

//ferramenta para desativar todos os voxels (em esfera);
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){

    double px, py, pz;
    
    
    for(int k=0; k<nz ; k++){

        for(int i=0; i<nx ;i++){

            for(int j=0; j<ny ;j++){

                px = double((i-xcenter)*(i-xcenter));
                py = double((j-ycenter)*(j-ycenter));
                pz = double((k-zcenter)*(k-zcenter));

                if((px+py+pz)<=(radius*radius)){

                    Sculptor::cutVoxel(i,j,k);

                }

            }

        }

    }

}

//ferramenta para ativar todos os voxels (em elipsoide);
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){

    double px, py, pz;
    
    for(int k=0; k<nz ; k++){

        for(int i=0; i<nx ;i++){

            for(int j=0; j<ny ;j++){

                px = double(((i-xcenter)*(i-xcenter))/double(rx*rx));
                py = double(((j-ycenter)*(j-ycenter))/double(ry*ry));
                pz = double(((k-zcenter)*(k-zcenter))/double(rz*rz));

                if((px+py+pz)<1){

                    Sculptor::putVoxel(i,j,k);

                }

            }

        }

    }

}

//ferramenta para desativar todos os voxels (em elipsoide);
void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){

    double px, py, pz;
    
    for(int k=0; k<nz ; k++){

        for(int i=0; i<nx ;i++){

            for(int j=0; j<ny ;j++){

                px = double(((i-xcenter)*(i-xcenter))/double(rx*rx));
                py = double(((j-ycenter)*(j-ycenter))/double(ry*ry));
                pz = double(((k-zcenter)*(k-zcenter))/double(rz*rz));

                if((px+py+pz)<=1){

                    Sculptor::cutVoxel(i,j,k);

                }

            }

        }

    }

}

//grava a escultura no formato OFF no arquivo objeto3d;
void Sculptor::writeOFF(const char* filename){

    //quantos voxels ativos existem;
    int Nvoxels = 0;

    for(int k=0;k<nz;k++){

        for(int i=0;i<nx;i++){

            for(int j=0;j<ny;j++){

                if(v[k][i][j].isOn == true){

                    Nvoxels++;

                }

            }

        }

    }

    //declarando e abrindo o fluxo de entrada de dados para o arquivo .OFF (filename);
    std::ofstream arquivo;
    arquivo.open(filename);
    arquivo << std::setiosflags(std::ios::fixed);
    //cabeçalho do arquivo 'filename.OFF' e definição dos vertices, faces e arestas;
    int Nvertices = Nvoxels*8, 
        Nfaces = Nvoxels*6, 
        Narestas = Nvoxels*0;

    arquivo << "OFF" << std::endl << Nvertices << " " << Nfaces << " " << Narestas << std::endl;

    //setando vertices;
    for (int k=0;k<nz;k++){

        for(int i=0;i<nx;i++){

            for(int j=0;j<ny;j++){

                if(v[k][i][j].isOn == true){

                    arquivo << i-0.5 << " " << j+0.5 << " " << k-0.5 << std::endl;
                    arquivo << i-0.5 << " " << j-0.5 << " " << k-0.5 << std::endl;
                    arquivo << i+0.5 << " " << j-0.5 << " " << k-0.5 << std::endl;
                    arquivo << i+0.5 << " " << j+0.5 << " " << k-0.5 << std::endl; 
                    arquivo << i-0.5 << " " << j+0.5 << " " << k+0.5 << std::endl;
                    arquivo << i-0.5 << " " << j-0.5 << " " << k+0.5 << std::endl;
                    arquivo << i+0.5 << " " << j-0.5 << " " << k+0.5 << std::endl;
                    arquivo << i+0.5 << " " << j+0.5 << " " << k+0.5 << std::endl;     

                }

            }

        }

    }

    //setando as faces, a cada voxel completado imcremento vertices=+8 ;
    int vertices = 0;
    for (int k=0;k<nz;k++){

        for(int i=0;i<nx;i++){

            for(int j=0;j<ny;j++){

                if(v[k][i][j].isOn == true){

                    arquivo << 4 << " " << vertices+0 << " " << vertices+3 << " " << vertices+2 << " " <<
                    vertices+1 << " " << v[k][i][j].r << " " << v[k][i][j].g << " " << v[k][i][j].b << " " << 
                    v[k][i][j].a << std::endl;

                    arquivo << 4 << " " << vertices+4 << " " << vertices+5 << " " << vertices+6 << " " <<
                    vertices+7 << " " << v[k][i][j].r << " " << v[k][i][j].g << " " << v[k][i][j].b << " " << 
                    v[k][i][j].a << std::endl;

                    arquivo << 4 << " " << vertices+0 << " " << vertices+1 << " " << vertices+5 << " " <<
                    vertices+4 << " " << v[k][i][j].r << " " << v[k][i][j].g << " " << v[k][i][j].b << " " << 
                    v[k][i][j].a << std::endl;

                    arquivo << 4 << " " << vertices+0 << " " << vertices+4 << " " << vertices+7 << " " <<
                    vertices+3 << " " << v[k][i][j].r << " " << v[k][i][j].g << " " << v[k][i][j].b << " " << 
                    v[k][i][j].a << std::endl;

                    arquivo << 4 << " " << vertices+3 << " " << vertices+7 << " " << vertices+6 << " " <<
                    vertices+2 << " " << v[k][i][j].r << " " << v[k][i][j].g << " " << v[k][i][j].b << " " << 
                    v[k][i][j].a << std::endl;

                    arquivo << 4 << " " << vertices+1 << " " << vertices+2 << " " << vertices+6 << " " <<
                    vertices+5 << " " << v[k][i][j].r << " " << v[k][i][j].g << " " << v[k][i][j].b << " " << 
                    v[k][i][j].a << std::endl;

                    vertices = vertices + 8;

                }

            }

        }

    }

    arquivo.close();

}