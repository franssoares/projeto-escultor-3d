#include "headers/figurageometrica.h"
#include "headers/sculptor.h"
#include "headers/putellipsoid.h"

PutEllipsoid::PutEllipsoid(int x0, int y0, int z0, float raiox,float raioy,float raioz, float r, float g, float b, float a){

    this->x0 = x0; this->y0 = y0; this->z0 = z0;
    this->raiox = raiox; this->raioy = raioy; this->raioz = raioz; this->r = r; this->g = g; this->b = b;

}
    
PutEllipsoid::~PutEllipsoid(){}

void PutEllipsoid::draw(Sculptor &t){

    t.setColor(r,g,b,a);
    t.putEllipsoid(x0,y0,z0,raiox,raioy,raioz);

}