#include "../include/Var.h"

void Var::troca(int &a, int &b)
{
    int aux=a;
    a=b;
    b=aux;
}

Var::Var() {	}

Var::Var(int li, int ls)
{
    if (ls < li)
        troca(li,ls);

    for (int v=li; v<=ls; v++)
        _dom.push_back(v);
}

Var::Var(const Var &outra)
{
    _dom = outra.getDominio();
}

Var & Var::operator=(const Var &outra)
{
    _dom = outra.getDominio();
    return *this;
}

void Var::setDominio(list<int> dominio)
{
    _dom = dominio;
}

list<int> Var::getDominio() const
{
    return _dom;
}

bool Var::fixa()
{
    return _dom.size() == 1;
}

//remove do dominio o elemento passado como parâmetro.
void Var::removeDom(int elem)
{
    _dom.remove(elem);
}

Var::~Var()
{
    //dtor
}
