#ifndef SCULPTOR_H
#define SCULPTOR_H


struct Voxel {
  float r,g,b; // Cores
  float a; // Transparencia
  bool isOn; // Incluir ou não
};

class Sculptor
{
protected:
  Voxel ***v; //matriz 3d
  float r,g,b,a; // cor e opacidade
public:
  int nx,ny,nz; // Dimensões da matriz
  Sculptor(int _nx, int _ny, int _nz);
  ~Sculptor();
  void setColor(float r, float g, float b, float alpha);
  void putVoxel(int x, int y, int z);
  void cutVoxel(int x, int y, int z);
  void writeOFF(char* filename);

};

void troca(int &x, int &y);

#endif // SCULPTOR_H
