#ifndef ARBOL_HPP
#define ARBOL_HPP

#include "NodoArbol.hpp"
#include "Lista.hpp"
#include <vector>
using namespace std;

class Arbol
{
public:
    Arbol();
    void insertar(Aficionado a1);
    void pintar();
    void dibujar();
    void mostrar(string opcion);
    void buscar();
    void aficionadosPares();
    void mostrarHojas();
    bool existe(int id);
    bool vacio();
    void eliminar(int id); //Eliminar el id del arbol
    ~Arbol();

private: 
    anodo raiz;
    anodo insertarA(anodo, Aficionado);
    void pintar(anodo);
    int altura(anodo);
    void dibujarNodo(vector<string>& output, vector<string>& linkAbove, anodo nodo, int nivel, int minPos, char linkChar);
    void InOrden(anodo aux);
    int contarAficionados(anodo aux);
    void nodosHojas(anodo aux);
    bool comprobarExistencia(int id, anodo aux);
    Aficionado maximo (Aficionado a, anodo aux);
    Aficionado minimo(Aficionado a, anodo aux);
    anodo eliminarNodo(int id,anodo aux);
    Aficionado maximoId(anodo a);
    Aficionado minimoId(anodo a);
};

#endif // ARBOL_HPP
