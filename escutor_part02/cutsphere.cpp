#include "cutsphere.h"
#include<iostream>
#include<cmath>

using namespace std;

cutSphere::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
 this->xcenter = xcenter; this->ycenter = ycenter; this->zcenter = zcenter;  this->radius = radius;
}

// Método que desativa a visibilidade dos cubos que compõe a esfera, que foi construida por meio do método putSphere
void cutSphere::draw(Sculptor &t)
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
                        t.cutVoxel(i,j,k);
                   }

               }
           }
       }

}
cutSphere::~cutSphere()
{

}
