#include "headers/figurageometrica.h"
#include "headers/sculptor.h"
#include "headers/cutellipsoid.h"

CutEllipsoid::CutEllipsoid(int x0, int y0, int z0, float raiox,float raioy,float raioz){

    this->x0 = x0; this->y0 = y0; this->z0 = z0;
    this->raiox = raiox; this->raioy = raioy; this->raioz = raioz;

}
    
CutEllipsoid::~CutEllipsoid(){}

void CutEllipsoid::draw(Sculptor &t){

    t.cutEllipsoid(x0,y0,z0,raiox,raioy,raioz);

}