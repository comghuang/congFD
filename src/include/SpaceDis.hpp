
#pragma once
#include "block.hpp"
#include "oneDBnd.hpp"
#include "info.hpp"




class SpaceDis
{
    public:
    SpaceDis(int n_,std::shared_ptr<Data> data_,std::shared_ptr<Data> rhs_
            ,std::shared_ptr<OneDBnd> bndL_,std::shared_ptr<OneDBnd> bndR_,std::shared_ptr<Info> info);
    SpaceDis();
    void difference();
    void setOffset(int,int);
    void setMethod(EquationType ,DiffMethod);
    


    private:
    std::shared_ptr<Data> data;
    std::shared_ptr<Data> rhs;
    std::shared_ptr<OneDBnd> bndL,bndR;

    void calFlux();
    void calFluxConv(ind);
    void calFluxBurgers(ind);
    void calFluxEuler(ind);
    void (SpaceDis::*calTypeFlux)(ind);

    real at(int,int);
    real& fAt(int,int);
    real reconL(ind,ind);
    real reconR(ind,ind);


    void difHCS();
    void difTraditional6();
    void dif2Order();
    void (SpaceDis::*difMethod)();
    
    ind n,nVar,nPrim;
    int i0=0,offset=1;
    ind nHalf;
    std::shared_ptr<Data> flux;
    std::shared_ptr<OneDBnd> fBndL,fBndR;
    EquationType fluxType;
    DiffMethod diffMethod=TRAD2;
    InterMethod interMethod=FIRSTORDER;


};