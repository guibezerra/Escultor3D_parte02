#include "putellipsoid.h"
#include <iostream>
#include<cmath>

using namespace std;

putEllipsoid::putEllipsoid(int xcenter,int ycenter,int zcenter,int rx, int ry,int rz, float r, float g, float b, float a)
{
    this->xcenter = xcenter; this->ycenter = ycenter; this->zcenter = zcenter;
    this->rx = rx; this->ry = ry; this->rz = rz;
    this->r = r;this->g = g;this->b = b;this->a = a;
}
/* Método responsável por construir uma elipsoide. A ideia é a mesma do método putSphere entretanto, deve-se atentar a subtração dos
 * valores i, j e k no codigo, pelas coordenadas dos centros da elipsoide obtidas na chamada do método. Essa operação assegura a
 * obtenção das coordenadas dos eixos x, y e z.
 */
void putEllipsoid::draw(Sculptor &t)
{
    double auxiliar = 0;

    for(int i = 0; i < t.nx; i++)
       {
           for(int j= 0; j < t.ny; j++)
           {
               for(int k = 0; k < t.nz; k++)
               {
                  auxiliar = ((float)pow((i-xcenter),2)/pow(rx,2)) + ((float)pow((j-ycenter),2)/pow(ry,2)) + ((float)pow((k-zcenter),2)/pow(rz,2));

                  if (auxiliar <= 1.0)
                   {
                        t.putVoxel(i,j,k);
                   }

               }
           }
       }
}
putEllipsoid::~putEllipsoid()
{

}
