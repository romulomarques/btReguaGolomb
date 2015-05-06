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
    for (int i=0; i<_n; i++)
        if (! x[i].fixa())
            return i;
    return -1;
}

// Dentre as variaveis que ainda nao tiveram seus valores fixados,
// escolhe uma que possui o menor dominio.
int Resolvedor::indiceRamificacaoMenorDominio(vector<Var> x)
{
    int indice = -1;
    for (int i=0; i<_n; i++)
        if (! x[i].fixa())
        {
            if (indice == -1)
                indice = i;
            else
                if (x[i].getDominio().size() < x[indice].getDominio().size())
                    indice = i;
        }
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
    int n = 0;
    for(int i = 0; i < _n; i++)
    {
        if(x[i].fixa())
        {
            n++;
        }
    }

    vector<int> xFixos(n);

    int cont = 0;
    for(int i = 0; i < _n; i++)
    {
        if(x[i].fixa())
        {
            xFixos[cont] = x[i].getDominio().back();
            cont++;
        }
    }

    for(int i = 0; i < n-1; i++)
    {
        int xi = xFixos[i];
        int xip1 = xFixos[i+1];
        if(xFixos[i] >= xFixos[i+1])
        {
            return false;
        }
    }

    for(int i = 0; i < n-1; i++)
    {
        int xi = xFixos[i];
        for(int j = i+1; j < n; j++)
        {
            int xj = xFixos[j];
            if(xFixos[j] > xFixos[i])
            {
                for(int k = 0; k < n-1; k++)
                {
                    int xk = xFixos[k];
                    if(xFixos[k] > xFixos[j])
                    {
                        for(int l = k+1; l < n; l++)
                        {
                            int xl = xFixos[l];
                            if(xFixos[l] > xFixos[k])
                            {
                                if ( ~((i == k) && (j == l)) )
                                {
                                    if((xFixos[j] - xFixos[i]) == (xFixos[l] - xFixos[k]))
                                    {
                                        return false;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return true;
}

// Metodo principal: busca em profundidade; imprime todas as solucoes
// completas, ou, caso nao exista solucao, imprime um aviso que informa
// a inexistencia de solucoes.
void Resolvedor::vai(vector<Var> x)
{

    // Estrutura que ira conter os nos ainda nao explorados.
    stack<vector<Var> > P;
    P.push( x );

    // Solucao parcial -- variavel auxiliar.
    vector<Var> solParcial;

    while (P.size() > 0)
    {
        //Pega a solucao do topo da pilha.
        solParcial = P.top();

        //Deleta a solucao do topo da pilha(que foi capturada no comando anterior).
        P.pop();

        // Verifica viabilidade ate o momento
        if (! parcialmenteViavel(solParcial))
            continue;

        // Escolhe variavel a ser ramificada
        int j = indiceRamificacao( solParcial );
        if (j == -1)
        {
            //imprime solucao completa.
            int n = solParcial.size();
            cout << "[";
            for (int i=0; i<n; i++) {

                list<int> valores = solParcial[i].getDominio();
                if (valores.size() == 1)
                    cout << " " << *valores.begin();
                else {
                    int v;
                    list<int>::iterator it;

                    cout << " [";
                    for(it = valores.begin(); it != valores.end(); it++)
                    {
                        v = (*it);
                        cout << " " << v;
                    }
                    cout << " ]";
                }
            }
            cout << "]" << endl;

            continue;
        }

        //Captura dominio da variavel a ser ramificada.
        list<int> domXj = solParcial[j].getDominio();

        list<int>::iterator it;
        int valor;

        //Adiciona todos os filho possiveis de acordo com o proprio dominio.
        for(it = domXj.begin(); it != domXj.end(); it++)
        {
            valor = (*it);
            vector<Var> filho = solParcial;
            list<int> domUnitario;
            domUnitario.push_back( valor );
            filho[j].setDominio( domUnitario );

            P.push( filho );
        }
    }
}

Resolvedor::~Resolvedor()
{
    //dtor
}
