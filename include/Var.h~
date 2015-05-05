#ifndef VAR_H
#define VAR_H

#include <list>
using namespace std;

class Var
{
    public:
        Var();
        Var(int li, int ls);
        Var(const Var &outra);
        Var & operator=(const Var &outra);
        void setDominio(list<int> dominio);
        list<int> getDominio() const;
        bool fixa();
        void removeDom(int elem);

        virtual ~Var();
    protected:
    private:
        /**Atributos**/
        list<int> _dom;

        /**Metodos**/
        void troca(int &a, int &b);
};

#endif // VAR_H
