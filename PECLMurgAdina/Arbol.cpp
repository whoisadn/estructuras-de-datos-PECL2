#include "Arbol.hpp"

Arbol::Arbol()
{
    raiz = new NodoArbol(-2);
}
void Arbol::insertar(Aficionado a1)
{
    if(a1.esSocio()) {
        raiz->izq = insertarA(raiz->izq, a1);
    } else {
        raiz->der = insertarA(raiz->der, a1);
    }
}
anodo Arbol::insertarA(anodo nodo, Aficionado a1)
{
    if(!nodo)
        return new NodoArbol(a1);

    if(a1.getId() >= nodo->a1.getId()) {
        nodo->der = insertarA(nodo->der, a1);
    } else {
        nodo->izq = insertarA(nodo->izq, a1);
    }
    return nodo;
}

void Arbol::InOrden(anodo aux)
{
    if(raiz != NULL) {
        if(aux != NULL) {
            InOrden(aux->izq); // Izquierda
            if(aux->a1.getId() != -2) {
                cout << endl;
                aux->a1.mostrar();
            }
            InOrden(aux->der); // Derecha
        }
    } else {
        cout << "EL ARBOL ESTA VACIO";
    }
}

void Arbol::mostrar(string opcion)
{
    anodo aux;
    aux = raiz; //Puntero auxiliar que nos ayudará a recorrer donde corresponda
    if(opcion == "socio") {
        aux = aux->izq;
    }
    if(opcion == "simpatizante") {
        aux = aux->der;
    }
    if(opcion == "aficionado") {
    }
    InOrden(aux);
}

Aficionado Arbol::maximo(Aficionado a, anodo aux)
{
    Aficionado af1, af2, af3;
    af1.setMllegada();
    af2.setMllegada();
    af3.setMllegada();

    if(aux == NULL) { // Nos retorna un Aficionado con los minutos de llegada a 0.
        return af3;
    }
    if((aux->izq == NULL) && (aux->der == NULL)) { // Si no hay elementos en la izquierda y la derecha
        if(a.getMllegada() <= aux->a1.getMllegada()) {
            a = aux->a1;
        }
        return a;
    }
    if(aux->izq) {
        af1 = maximo(a, aux->izq);
    }
    if(aux->der) {
        af2 = maximo(a, aux->der);
    }
    if(af1.getMllegada() != 0 || af2.getMllegada() != 0) {
        if(af1.getMllegada() > af2.getMllegada()) {
            return af1;
        } else {
            return af2;
        }
    } else {
        return a;
    }
}

Aficionado Arbol::minimo(Aficionado a, anodo aux)
{
    Aficionado af1, af2, af3;
    af1.setMllegada();
    af2.setMllegada();
    af3.setMllegada();

    if(aux == NULL) {
        return af3;
    }
    if((aux->izq == NULL) && (aux->der == NULL)) { // Si no hay elementos en la izquierda y la derecha
        if(a.getMllegada() > aux->a1.getMllegada()) {
            a = aux->a1;
        }
        return a;
    }
    if(aux->izq) {
        af1 = minimo(a, aux->izq);
    }
    if(aux->der) {
        af2 = minimo(a, aux->der);
    }
    if(af1.getMllegada() != 0 || af2.getMllegada() != 0) {
        if(af1.getMllegada() > af2.getMllegada()) {
            return af1;
        } else {
            return af2;
        }
    } else {
        return a;
    }
}

void Arbol::buscar()
{
    anodo der, izq;
    der = raiz;
    izq = raiz;

    der = der->der; // Simpatizante
    izq = izq->izq; // Socio
    Aficionado a, b, c, d;

    a = der->a1;
    c = der->a1;
    cout << "El Simpatizante que ha llegado mas tarde es :" << endl;
    a = maximo(a, der);
    a.mostrar();

    cout << "El Simpatizante que ha llegado mas pronto es :" << endl;
    c = minimo(c, der);
    c.mostrar();

    b = izq->a1;
    d = izq->a1;
    cout << "El Socio que ha llegado mas tarde es : " << endl;
    b = maximo(b, izq);
    b.mostrar();

    cout << "El Socio que ha llegado mas pronto es : " << endl;
    d = minimo(d, izq);
    d.mostrar();
}

int Arbol::contarAficionados(anodo aux)
{
    int n;
    if(aux == NULL) {
        return n = 0;
    } else {
        return n = 1 + contarAficionados(aux->izq) + contarAficionados(aux->der);
    }
}

void Arbol::aficionadosPares()
{
    anodo aux;
    aux = raiz;     // Nodo Auxiliar.
    aux = aux->izq; // Rama del arbol aficionados
    cout << endl << "Los aficionados que son pares: " << contarAficionados(aux);
}

void Arbol::nodosHojas(anodo aux)
{
    if(!aux) { // Si el nodo es Null
        return;
    }
    if((aux->izq == NULL) && (aux->der == NULL)) { // Si no hay elementos en la izquierda y la derecha
        aux->a1.mostrar();
        return;
    }
    if(aux->der) {
        nodosHojas(aux->der);
    }
    if(aux->izq) {
        nodosHojas(aux->izq);
    }
}

void Arbol::mostrarHojas()
{
    anodo aux;
    aux = raiz;
    nodosHojas(aux);
}
bool Arbol::comprobarExistencia(int id, anodo aux)
{
    if(!aux) {
        return false;
    }
    if(id == aux->a1.getId()) {
        // cout<<"EXISTE";
        return true;
    } else {
        if(aux->a1.getId() == -2) { // CUANDO ELEGIMOS ENTRE SOCIO Y AFICIONADOS
            if(id % 2 == 0) {
                comprobarExistencia(id, aux->izq);
            } else {
                comprobarExistencia(id, aux->der);
            }
        } else { // CUANDO ESTAMOS DENTRO DE UNA DE LAS RAMAS DE SOCIOS O AfICIONADOS
            if(id <= aux->a1.getId()) {
                comprobarExistencia(id, aux->izq);
            } else {
                comprobarExistencia(id, aux->der);
            }
        }
    }
}
bool Arbol::existe(int id)
{
    anodo aux;
    aux = raiz;
    if(comprobarExistencia(id, aux)) {
        return true;
    } else {
        return false;
    }
}


Aficionado Arbol::maximoId(anodo b)
{
    while(b->der != NULL) {
        b = b->der;
    }
    return b->a1;
}

Aficionado Arbol::minimoId(anodo b)
{
    while(b->izq != NULL) {
        b = b->izq;
    }
    return b->a1;
}

anodo Arbol::eliminarNodo(int id, anodo aux) //
{
    Aficionado maximo, minimo;
    if(aux != NULL){
        if(id == aux->a1.getId()) {
            if(aux->izq == NULL) { //Si la izquierda esta vacía 
                if(aux->der) {//La derecha tiene alguna rama
                    minimo = minimoId(aux->der); //AFICIONADO MINIMO DE LA RAMA DERECHA
                    aux->der = eliminarNodo(minimo.getId(), aux->der); //Esto nos devolvera la izquierda sin el minimo
                    aux->a1 = minimo;
                }else{
                    aux=NULL;
                    delete aux;
                }
            }else if(aux->der == NULL) {
                maximo = maximoId(aux->izq); //EL Aficionado maximo de la izquierda
                aux->izq = eliminarNodo(maximo.getId(), aux->izq); //Tenemos que eliminar el aficionado de la rama izquierda
                aux->a1 = maximo;
            }else{ //Sabemos que el nodo tiene Hijo izquiero y derecho
                maximo = maximoId(aux->izq);
                aux->izq=eliminarNodo(maximo.getId(), aux->izq);
                aux->a1 = maximo;
                //return aux;
            }
        }else{
            if(id < aux->a1.getId()) {
                aux->izq=eliminarNodo(id, aux->izq);
            }else{
                aux->der=eliminarNodo(id, aux->der);
            }
        }
    }
    return aux;
}

void Arbol::eliminar(int id)
{
    if(id % 2 == 0) {
        raiz->izq = eliminarNodo(id, raiz->izq);
    } else {
        raiz->der = eliminarNodo(id, raiz->der);
    }
}

bool Arbol::vacio()
{ // Método para comprobar si el arbol esta vacio, teniendo en cuenta el Nodo Ficticio.
    if((raiz->a1.getId() == -2) && (raiz->der == NULL) && (raiz->izq == NULL)) {
        return true;
    }
    return false;
}

void Arbol::pintar()
{
    pintar(raiz);
    cout << '\n';
}
void Arbol::pintar(anodo nodo)
{
    if(!nodo)
        return;
    pintar(nodo->izq);
    cout << nodo->a1.getId() << " ";
    pintar(nodo->der);
}
int Arbol::altura(anodo nodo)
{
    if(!nodo)
        return 0;
    return 1 + max(altura(nodo->izq), altura(nodo->der));
}

void Arbol::dibujarNodo(vector<string>& output, vector<string>& linkAbove, anodo nodo, int nivel, int p, char linkChar)
{
    if(!nodo)
        return;

    int h = output.size();
    string SP = " ";

    if(p < 0) {
        string extra(-p, ' ');
        for(string& s : output)
            if(!s.empty())
                s = extra + s;
        for(string& s : linkAbove)
            if(!s.empty())
                s = extra + s;
    }
    if(nivel < h - 1)
        p = max(p, (int)output[nivel + 1].size());
    if(nivel > 0)
        p = max(p, (int)output[nivel - 1].size());
    p = max(p, (int)output[nivel].size());

    if(nodo->izq) {
        string izqdato = SP + to_string(nodo->izq->a1.getId()) + SP;
        dibujarNodo(output, linkAbove, nodo->izq, nivel + 1, p - izqdato.size(), 'L');
        p = max(p, (int)output[nivel + 1].size());
    }

    int space = p - output[nivel].size();
    if(space > 0)
        output[nivel] += string(space, ' ');
    string nododato = SP + to_string(nodo->a1.getId()) + SP;
    output[nivel] += nododato;

    space = p + SP.size() - linkAbove[nivel].size();
    if(space > 0)
        linkAbove[nivel] += string(space, ' ');
    linkAbove[nivel] += linkChar;

    if(nodo->der)
        dibujarNodo(output, linkAbove, nodo->der, nivel + 1, output[nivel].size(), 'R');
}
void Arbol::dibujar()
{
    int h = altura(raiz);
    vector<string> output(h), linkAbove(h);
    dibujarNodo(output, linkAbove, raiz, 0, 5, ' ');

    for(int i = 1; i < h; i++) {
        for(int j = 0; j < linkAbove[i].size(); j++) {
            if(linkAbove[i][j] != ' ') {
                int size = output[i - 1].size();
                if(size < j + 1)
                    output[i - 1] += string(j + 1 - size, ' ');
                int jj = j;
                if(linkAbove[i][j] == 'L') {
                    while(output[i - 1][jj] == ' ')
                        jj++;
                    for(int k = j + 1; k < jj - 1; k++)
                        output[i - 1][k] = '_';
                } else if(linkAbove[i][j] == 'R') {
                    while(output[i - 1][jj] == ' ')
                        jj--;
                    for(int k = j - 1; k > jj + 1; k--)
                        output[i - 1][k] = '_';
                }
                linkAbove[i][j] = '|';
            }
        }
    }

    cout << '\n' << '\n';
    for(int i = 0; i < h; i++) {
        if(i)
            cout << linkAbove[i] << '\n';
        cout << output[i] << '\n';
    }
    cout << '\n' << '\n';
}

Arbol::~Arbol()
{
    raiz->der=NULL;
    raiz->izq=NULL;
    
    delete raiz->der;
    delete raiz->izq;
}
