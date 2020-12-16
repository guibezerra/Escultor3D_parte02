#include<iostream>
#include "cutvoxel.h"
#include "sculptor.h"

using namespace std;

cutVoxel::cutVoxel(int x, int y, int z)
{
    this->x = x; this->y = y; this->y = y; this->z = z;
}

void cutVoxel::draw(Sculptor &t)
{
    t.cutVoxel(x,y,z);
}
cutVoxel::~cutVoxel()
{

}
