#ifndef RESOLVEDOR_H
#define RESOLVEDOR_H

#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <stack>
#include "../include/Var.h"

using namespace std;

class Resolvedor
{
    public:
        Resolvedor(int n, int m);
        int indiceRamificacao(vector<Var> x);
        int indiceRamificacaoMenorDominio(vector<Var> x);
        bool parcialmenteViavel(vector<Var> x);
        void vai(vector<Var> x);
        virtual ~Resolvedor();
    protected:
    private:
        //tamanho do vetor solucao a ser trabalhado, no caso,
        //a ordem(quantidade de pontos a serem colocados nas
        //marcacoes da regua).
        int _n;

        //tamamnho da regua(quantidade de pontos inteiros que
        //serão os valores possiveis da regua para a colocacao
        //dos pontos).
        int _m;
};

#endif // RESOLVEDOR_H
