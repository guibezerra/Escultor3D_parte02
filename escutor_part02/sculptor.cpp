#include "sculptor.h"
#include<iostream>
#include<fstream>

using namespace std;

// chamada do construtor e criação do objeto
Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    nx = _nx;
    ny = _ny;
    nz = _nz;

// Criação da Matriz3d via alocação dinamica
    v = new Voxel **[nx];
    for(int i = 0; i < nx; i++)
    {
        v[i] = new Voxel *[ny];
        for(int j=0; j < ny; j++)
        {
            v[i][j] = new Voxel [nz];
        }
     }
// Inicialização da Matriz3d
    for(int i = 0; i < nx; i++)
    {
        for(int j = 0; j < ny; j++)
        {
            for(int k = 0; k < nz; k++)
            {
                v[i][j][k].isOn = false;
                v[i][j][k].r = 0;
                v[i][j][k].g = 0;
                v[i][j][k].b = 0;
                v[i][j][k].a = 0;
            }
        }
    }
}

// chamada do destrutor da classe
Sculptor::~Sculptor()
{

    for(int i = 0; i < nx; i++)
    {
        for(int j=0; j < ny; j++)
        {
            delete [] v[i][j];
        }
    }
    for (int i = 0; i < nx; i++)
    {
        delete [] v[i];
    }
     delete [] v;
}
// Recebe cores e opacidade da figura e valida se as cores respeitam ou não os intervalos de cada propriedade
void Sculptor::setColor(float r, float g, float b, float alpha)
{
    if (r > 1 || g > 1 || b > 1 || alpha > 1)
    {
        cout << "Um dos valores é maior que o permitido" << endl;
    }
    else if(r < 0 || g < 0 || b < 0 || alpha < 0)
    {
        cout << "Um dos valores é menor que o permitido" << endl;
    }
    else
    {
        this->r = r;
        this->g = g;
        this->b = b;
        a = alpha;
    }
}
// Método que atribui as propriedades r, g, b e alpha a posição da matriz
void Sculptor::putVoxel(int x, int y, int z)
{
    if(x >= 0 && x <nx &&
       y >= 0 && y <ny &&
       z >= 0 && z <nz)
    {
         v[x][y][z].r = r;
         v[x][y][z].g = g;
         v[x][y][z].b = b;
         v[x][y][z].a = a;
         v[x][y][z].isOn = true;
    }
}
// Método que desativa a propriedade responsável pela visibilidade do voxel
void Sculptor::cutVoxel(int x, int y, int z)
{
    if(x >= 0 && x <nx &&
       y >= 0 && y <ny &&
       z >= 0 && z <nz)
    {
        v[x][y][z].isOn = false;
    }
}

// Método que escreve as coordenadas das figuras obtidas através dos métodos anteriores em um arquivo .OFF
void Sculptor::writeOFF(char *filename)
{   // um cubo possui 8 vetices e 6 faces
    int NVertices = 0, Nfaces = 0, NArestas = 0, ContVoxel = 0;
    ofstream fout;

    fout.open(filename);
    fout<< "OFF" <<endl;
 /*
  * As estruturas de repetição varrem a matriz em busca dos elementos que estão com a propriedade isOn=true. Isso indica a presença de um
  *  cubo, permitindo assim contabilizar o total de cubos que compõem a figura.
  */
    for(int i = 0; i < nx; i++)
    {
        for(int j = 0; j < ny; j++)
        {
            for(int k = 0; k < nz; k++)
            {
                if (v[i][j][k].isOn == true) {
                    ContVoxel++;
                }
            }
        }
    }
    NVertices = ContVoxel * 8; // Retorna a quantidade total de vertices presentes na figura.
    Nfaces = ContVoxel * 6; // Retorna a qtd. total de faces presentes na figura.
    fout<< NVertices<< " " << " " << Nfaces << " " << NArestas << endl;

// Adiciona ao arquivo as coordenadas dos pontos de todos os elementos que possuem a propriedade de visibilidade isOn = true.
    for(int k=0; k<nz; k++)
    {
             for(int j=0; j<ny; j++)
             {
                 for (int i=0;i<nx;i++)
                 {
                     if(v[i][j][k].isOn)
                     {
                             fout << -0.5+i << " " << 0.5+j << " " << -0.5+k << endl;
                             fout << -0.5+i << " " << -0.5+j << " " << -0.5+k << endl;
                             fout << 0.5+i << " " << -0.5+j << " " << -0.5+k << endl;
                             fout << 0.5+i << " " << 0.5+j << " " << -0.5+k << endl;
                             fout << -0.5+i << " " << 0.5+j << " " << 0.5+k << endl;
                             fout << -0.5+i << " "<< -0.5+j << " " << 0.5+k << endl;
                             fout << 0.5+i << " " << -0.5+j << " " << 0.5+k << endl;
                             fout << 0.5+i << " " << 0.5+j << " " << 0.5+k << endl;
                     }
                 }
             }

         }
/* Adiciona ao arquivo a sequencia de pontos que formam a face de cada cubo que compõe a imagem. Alem disso, adiciona a propriedade de
 * cores e da opacidade de cada uma das faces.
*/
     int nf = 0;
          for(int k=0;k<nz; k++){
               for(int j=0;j<ny;j++){
                   for (int i=0;i<nx;i++) {
                       if(v[i][j][k].isOn){
                           fout<<"4 "<<0+nf*8<<" "<<3+nf*8<<" "<<2+nf*8<<" "<<1+nf*8<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl
                               <<"4 "<<4+nf*8<<" "<<5+nf*8<<" "<<6+nf*8<<" "<<7+nf*8<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl
                               <<"4 "<<0+nf*8<<" "<<1+nf*8<<" "<<5+nf*8<<" "<<4+nf*8<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl
                               <<"4 "<<0+nf*8<<" "<<4+nf*8<<" "<<7+nf*8<<" "<<3+nf*8<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl
                               <<"4 "<<3+nf*8<<" "<<7+nf*8<<" "<<6+nf*8<<" "<<2+nf*8<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl
                               <<"4 "<<1+nf*8<<" "<<2+nf*8<<" "<<6+nf*8<<" "<<5+nf*8<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                           nf++;
                       }


                   }
               }

           }
  fout.close();
}

void troca(int &x, int &y) {
    int aux = 0;
    aux = x;
    x = y;
    y = aux;
}

