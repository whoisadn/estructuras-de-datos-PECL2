#ifndef LISTA_HPP
#define LISTA_HPP
#include "NodoLista.hpp"



class Lista
{
public:
    Lista();
    void insertarOrden(Aficionado a1);
    bool listaVacia();
    void mostrarLista();
    void concatenar(Lista listaSimpatizantes);
    int getLongitud();
    Aficionado elemento();
    void mostrarAficionados();//Método que nos muestra los socios y aficionados que más pronto y tarde han llegado.
    ~Lista();
    
private:
    lnodo primero; //El alias de la clase NodoLista -> lnodo
    int longitud;
};

#endif // LISTA_HPP
