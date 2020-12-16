#include "interpretador.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "putbox.h"
#include "cutbox.h"
#include "putvoxel.h"
#include "cutvoxel.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"

using namespace std;

interpretador::interpretador()
{

}

std::vector<figuraGeometrica *> interpretador::parse(string filename)
{
    std::vector<figuraGeometrica*> figs;
    std::ifstream fin;
    std::stringstream ss;
    std::string s, token;

    fin.open(filename.c_str());
    //verifica se o fluxo foi aberto
    if(!fin.is_open()) {
       cout << "nao abriu" << filename << endl;
       exit(0);
    }
    while (fin.good())
    {
     // fin >> s;
       std::getline(fin,s);
        if (fin.good()) {
            //lanca a string s no fluxo ss
            ss.clear();
            ss.str(s);
            ss >> token;
            // realiza o parsing dos tokens
            if(ss.good()) {
                //dimensoes da tela
                if(token.compare("dim") == 0) {
                    ss >> dimx >> dimy >> dimz;
                }
                //usuario define brush
                else if (token.compare("putvoxel") == 0){
                    int x0, y0, z0;
                    ss >> x0 >> y0 >> z0 >> r >> g >> b >> a;
                    figs.push_back(new putVoxel(x0, y0, z0, r, g, b, a));
                }
                else if (token.compare("cutvoxel") == 0) {
                    int x0, y0, z0;
                    ss >> x0 >> y0 >> z0;
                      figs.push_back(new cutVoxel(x0, y0, z0));
                }
                else if (token.compare("putbox") == 0) {
                    int x0, x1, y0, y1, z0, z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
                    figs.push_back(new putBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
                }
                else if (token.compare("cutbox") == 0) {
                    int x0, x1, y0, y1, z0, z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
                    figs.push_back(new cutBox(x0, x1, y0, y1, z0, z1));
                }
                else if (token.compare("putsphere") == 0) {
                    int xcenter, ycenter, zcenter, radius;
                    ss >> xcenter >> ycenter >> zcenter >> r >> g >> b >> a;
                    figs.push_back(new putSphere(xcenter, ycenter, zcenter, radius, r, g, b, a));
                }
                else if (token.compare("cutsphere") == 0) {
                    int xcenter, ycenter, zcenter, radius;
                    ss >> xcenter >> ycenter >> zcenter;
                    figs.push_back(new cutSphere(xcenter, ycenter, zcenter, radius));
                }
                else if (token.compare("putellipsoid") == 0) {
                    int xcenter, ycenter, zcenter, rx, ry, rz;
                    ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> a;
                    figs.push_back(new putEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz, r, g, b, a));
                }
                else if (token.compare("cutellipsoid") == 0) {
                    int xcenter, ycenter, zcenter, rx, ry, rz;
                    ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz;
                    figs.push_back(new cutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz));
                }
            }
        }
    }
    return(figs);
}

int interpretador::getDimx()
{
    return dimx;
}
int interpretador::getDimy()
{
    return dimy;
}
int interpretador::getDimz()
{
    return dimz;
}

