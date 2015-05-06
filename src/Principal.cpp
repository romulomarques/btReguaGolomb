#include "../include/Principal.h"

int main()
{
    //tamanho da regua.
	int m = 6;

	//numero de pontos.
	int n = 4;

	// Cria um dominio com elementos indo de 1 a m. Dominio completo.
	list<int> dominio1aM;
	for (int i=0; i<m; i++)
		dominio1aM.push_back( i );

    vector<Var> x(n);
	for (int i=0; i<n; i++)
		x[i].setDominio( dominio1aM );

    // Chamada do resolvedor propriamente dito
	Resolvedor res(n, m);
	res.vai( x );

    cout << "\nFim\n";

    //p.Imprime();
    //cout << "Deu certo?\n" << p.pviavel(theta);

	getchar();
	return 0;
}
