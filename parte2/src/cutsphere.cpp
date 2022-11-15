#include "headers/figurageometrica.h"
#include "headers/sculptor.h"
#include "headers/cutsphere.h"

CutSphere::CutSphere(int x0, int y0, int z0, float raio){

    this->x0 = x0; this->y0 = y0; this->z0 = z0;
    this->raio = raio;

}

CutSphere::~CutSphere(){}

void CutSphere::draw( Sculptor &t){

    t.cutSphere(x0,y0,z0,raio);

}