#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "sculptor.h"

class figuraGeometrica
{
protected:
    float r,g,b,a;
public:
    figuraGeometrica();
    virtual ~figuraGeometrica();
    virtual void draw(Sculptor &t)=0; // metodo virtual puro
};

#endif // FIGURAGEOMETRICA_H
