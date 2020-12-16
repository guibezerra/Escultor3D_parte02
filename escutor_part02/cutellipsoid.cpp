#include "cutellipsoid.h"
#include <iostream>
#include<cmath>

using namespace std;

cutEllipsoid::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    this->xcenter = xcenter; this->ycenter = ycenter; this->zcenter = zcenter;
    this->rx = rx; this->ry = ry; this->rz = rz;
}

// Método que desativa a visibilidade dos blocos que compõe a elipsoide, que foi construida por meio do método putEllipsoid
void cutEllipsoid::draw(Sculptor &t)
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
                        t.cutVoxel(i,j,k);
                   }

               }
           }
       }
}
cutEllipsoid::~cutEllipsoid()
{

}
