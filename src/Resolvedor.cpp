#include "../include/Resolvedor.h"

Resolvedor::Resolvedor(int n, int m)
{
    _n = n;
    _m = m;
}

// Escolher sempre a variavel de menor indice que ainda nao teve
// seu valor fixado (i.e., tem mais de um valor no dominio).
int Resolvedor::indiceRamificacao(vector<Var> x)
{
    return -1;
}

// Dentre as variaveis que ainda nao tiveram seus valores fixados,
// escolhe uma que possui o menor dominio.
int Resolvedor::indiceRamificacaoMenorDominio(vector<Var> x)
{
    int indice = -1;
    return indice;
}

// Verifica se a solucao parcial fornecida viola alguma
// restricao existente entre as variaveis que estao fixas.
//bool Resolvedor::parcialmenteViavel(Solucao x)
//{
//    for (int i=0; i<_n; i++)
//        if (x.getVar(i).fixa())
//        {
//            for (int j=0; j<_n; j++)
//                if ((x.getVar(j).fixa()) && (j != i))
//                {
//                    list<int> domXi = x.getVar(i).getDominio();
//                    list<int> domXj = x.getVar(j).getDominio();
//                    int di = *domXi.begin();
//                    int dj = *domXj.begin();
//                    if ((di == dj) || (abs(i-j) == abs(di-dj)))
//                        return false;
//                }
//        }
//    return true;
//}

bool Resolvedor::parcialmenteViavel(vector<Var> x)
{
    return true;
}

// Metodo principal: busca em profundidade; imprime todas as solucoes
// completas, ou, caso nao exista solucao, imprime um aviso que informa
// a inexistencia de solucoes.
void Resolvedor::vai(vector<Var> x)
{

  
}

Resolvedor::~Resolvedor()
{
    //dtor
}
