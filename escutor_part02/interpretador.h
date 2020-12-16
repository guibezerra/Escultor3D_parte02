#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H
#include<vector>
#include "figurageometrica.h"
#include <string>
#include <iostream>

using namespace std;

class interpretador
{
    int dimx, dimy, dimz;
    float r, g, b, a;
public:
    interpretador();
    std::vector<figuraGeometrica *> parse(string filename);
    int getDimx();
    int getDimy();
    int getDimz();
};

#endif // INTERPRETADOR_H
