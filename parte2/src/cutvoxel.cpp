#include "headers/sculptor.h"
#include "headers/cutvoxel.h"

//Função que implementa voxel
CutVoxel::CutVoxel(int x, int y, int z){

    this->x = x; this->y = y; this->z = z;

}

CutVoxel::~CutVoxel(){}

void CutVoxel::draw(Sculptor &t){

    t.cutVoxel(this->x,this->y,this->z);
    
}