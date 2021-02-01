#include "NodoArbol.hpp"

NodoArbol::NodoArbol(Aficionado a1)
{
    this->a1 = a1;
    this->izq = NULL;
    this->der = NULL;
}

NodoArbol::~NodoArbol()
{
}

