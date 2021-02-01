#ifndef NODOARBOL_HPP
#define NODOARBOL_HPP
#include  "Aficionado.hpp"

class NodoArbol
{
public:
    NodoArbol(Aficionado a1);
    ~NodoArbol();
private:
    Aficionado a1;
    NodoArbol* izq;
    NodoArbol* der;

    friend class Arbol;
};
typedef NodoArbol* anodo;
#endif // NODOARBOL_HPP
