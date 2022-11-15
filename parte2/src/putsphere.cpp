#include "headers/figurageometrica.h"
#include "headers/putsphere.h"
#include "headers/sculptor.h"
    
PutSphere::PutSphere(int x0, int y0, int z0, float raio, float r, float g, float b, float a){

    this->x0 = x0; this->y0 = y0; this->z0 = z0;
    this->raio = raio; this->r = r; this->g = g; this->b = b;

}
PutSphere::~PutSphere(){}

void PutSphere::draw(Sculptor &t){

    t.setColor(r,g,b,a);
    t.putSphere(x0,y0,z0,raio);

}