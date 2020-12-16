#include "putsphere.h"
#include<iostream>
#include<cmath>

using namespace std;

putSphere::putSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a)
{
    this->xcenter = xcenter; this->ycenter = ycenter; this->zcenter = zcenter;  this->radius = radius;
    this->r = r; this->g = g; this->b = b; this->a = a;
}
/* Método responsável por construir uma esfera. A ideia é que as estruturas de repetição percorrão toda a matriz de forma a verificar
 * quais dos pontos que a compõe, fazem parte da esfera cuja as coordenadas são previamente definidas na chamada do método.
 */
void putSphere::draw(Sculptor &t)
{
    double distancia = 0;

    for(int i = 0; i < t.nx; i++)
           {
               for(int j= 0; j < t.ny; j++)
               {
                   for(int k = 0; k < t.nz; k++)
                   {
                       distancia = sqrt(pow(i - xcenter,2) + pow(j - ycenter,2) + pow(k - zcenter,2));
                       if (distancia <= radius)
                       {
                            t.putVoxel(i,j,k);
                       }

                   }
               }
           }
}

putSphere::~putSphere()
{

}
