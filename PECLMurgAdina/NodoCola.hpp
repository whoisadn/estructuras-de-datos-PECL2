#ifndef NODOCOLA_HPP
#define NODOCOLA_HPP
#include "Aficionado.hpp"


class NodoCola
{
public:
    NodoCola(Aficionado a1);
    ~NodoCola();
private:
    Aficionado aficionado1;
    NodoCola* siguiente;
    
    friend class Cola;
};
typedef NodoCola* cnodo; //Alias de la clase NodoCola
#endif // NODOCOLA_HPP