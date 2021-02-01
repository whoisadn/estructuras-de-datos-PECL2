#ifndef GESTOR_HPP
#define GESTOR_HPP

#include "Pila.hpp"
#include "Cola.hpp"
#include "Lista.hpp"
#include "Pila.hpp"
#include "Arbol.hpp"
#include <algorithm> // shuffle
#include <array>     // array
#include <chrono>    // chrono::system_clock
#include <random>    // std::default_random_engine


class Gestor
{
public:
    Gestor();
    void genera10Aficionados();
    void borraAficionados();
    void muestraAficionados();
    void encolarAficionados();
    void muestraSocios();
    void muestraSimpatizantes();
    void vaciaColas();
    void muestraAficionadosEnLista();
    void buscaSocios();
    void reiniciar();
    void dibujarAbb();
    void sociosOrdenados();
    void simpatizantesOrdenados();
    void crearArbol();
    void todosAficionados();
    void mostrarAficionadosPares();
    void buscar();
    void mostrarHojas();
    void eliminarNodo();
    ~Gestor();

private:
    Pila pilaAficionados;
    Cola colaSocios;
    Cola colaSimpatizantes;
    Lista listaSocios;
    Arbol arbolAficionados;
};

#endif // GESTOR_HPP
