#include <iostream>
#include<sculptor.h>
#include<figurageometrica.h>
#include<putvoxel.h>
#include<cutvoxel.h>
#include<putbox.h>
#include<cutbox.h>
#include<putsphere.h>
#include<cutsphere.h>
#include<putellipsoid.h>
#include<cutellipsoid.h>
#include<vector>
#include<interpretador.h>

using namespace std;

int main(void)
{
    Sculptor *s1;

    interpretador parser;
    vector<figuraGeometrica*> figs;

    figs = parser.parse("/home/guiba/Documentos/Escultor3D_parte02/escutor_part02/figurasGeometricas/figTeste.txt");

    s1 = new Sculptor (parser.getDimx(),parser.getDimy(), parser.getDimz());

    for (size_t i = 0; i<figs.size(); i++)
    {
        figs[i]->draw(*s1);
    }

    s1->writeOFF((char*)"/home/guiba/Documentos/Escultor3D_parte02/escutor_part02/figurasGeometricas/saida.off");
    for(size_t i = 0; i<figs.size(); i++) {
        delete figs[i];
    }

    delete s1;
    return 0;
}


