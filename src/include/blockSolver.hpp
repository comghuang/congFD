#pragma once
#include "initializer.hpp"
#include "cgnsio.hpp"
#include "SourceTerm.hpp"

class BlockSolver
{
    public:
    BlockSolver();
    BlockSolver(Info*);
    void solve(real);
    ~BlockSolver();


    void outputGrid();
    void outputCons();
    void outputPrim();


    void stepsLoop();
    void stepsLoopCFL();
    void stepsLoopDTS();
    void Test();

    private:
    
    CgnsIO cgnsIO;
    Info* info;
    Block* block;
    Initializer* initer;
    Equation* eqn;
    Bnds* bnds;
    SpDistributor* spDis;
    Data* cons,*rhs;
    SourceTerm* sourceTerm;
    void RK3_SSP(real);
    void DTS_Euler(real);
    std::vector<real> calLocalCFL();
    TimeMethod timeMethod=RK3SSP;
};