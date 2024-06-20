#pragma once
#include"data.hpp"

class Block
{
    public:
    void outputCgns();
    real operator()(int,int);
    std::array<int,3> getICMax();
    std::array<int,3> getIMax();
    int getDim();
    std::vector<real> getCellCoor(int idim);
    std::vector<real> getVertexCoor(int idim);
    


    protected:
    friend class Initializer;
    Data coorVer;
    Data coorCel;
    int nVer,nCel;
    bool inited=false;
    int dim;
    std::array<int,3> iMax,icMax;

};