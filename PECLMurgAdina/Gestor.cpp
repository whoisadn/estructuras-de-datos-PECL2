#include "Gestor.hpp"

// CONSTRUCTOR VACÍO
Gestor::Gestor()
{
}

void Gestor::genera10Aficionados()
{
    //Método para generar los 10 aficionados
    int numAficionados = pilaAficionados.getLongitud();

    array<int, 10> foo = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    // obtain a time-based seed:
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    shuffle(foo.begin(), foo.end(), std::default_random_engine(seed));

    for(int& x : foo) {
        int id = x + numAficionados;
        Aficionado a(id);
        pilaAficionados.apilarA(a);
    }
} 

void Gestor::borraAficionados()
{
        pilaAficionados.~Pila();
}

void Gestor::muestraAficionados()
{
    pilaAficionados.mostrarPila();
}

void Gestor::encolarAficionados()
{     
    cout<<"Vamos a encolar los aficionados a las colas";
    Aficionado af1;
    while(pilaAficionados.getLongitud()>0){ //Mientras que tengamos elementos en la pila, podremos repartirlos en las colas..
        
        af1 = pilaAficionados.desapilar();//SACAMOS EL OBJETO AFICIONADO DE LA PILA Y LO ASIGNAMOS EN UNA VARIABLE DEL MISMO TIPO
        if(af1.getId()%2==0){
            colaSocios.encolar(af1);
        }else{
            colaSimpatizantes.encolar(af1);
        }
    }
}

void Gestor::muestraSocios(){
    colaSocios.mostrarCola();
        
}
void Gestor::muestraSimpatizantes(){
  colaSimpatizantes.mostrarCola();
}

void Gestor::vaciaColas(){
    colaSimpatizantes.~Cola();
    colaSocios.~Cola();
}

void Gestor::muestraAficionadosEnLista(){
    
        Lista listaSimpatizantes; // Lista auxiliar
        while(colaSocios.getLongitud()>0){
                Aficionado af1=colaSocios.desencolar();
                listaSocios.insertarOrden(af1);
        }
        while(colaSimpatizantes.getLongitud()>0){
            Aficionado af2=colaSimpatizantes.desencolar();
            listaSimpatizantes.insertarOrden(af2); //Almacenamos en esta lista auxiliar los aficionados simpatizantes concatenados.
        }
        listaSocios.concatenar(listaSimpatizantes);
        listaSocios.mostrarLista();
        
}

void Gestor::buscaSocios()
{
        listaSocios.mostrarAficionados();
}

void Gestor::crearArbol()
{
        Aficionado a;
        while(listaSocios.getLongitud()!=0){
                a=listaSocios.elemento(); //Sacamos el objeto Aficionado de la lista 
                arbolAficionados.insertar(a);
        }
        cout<<"Hemos creado el arbol";
    
}

void Gestor::dibujarAbb()
{
    if(!arbolAficionados.vacio()){//Comprobamos que el arbol no este vacio
        arbolAficionados.dibujar(); 
    }else{
        cout<<"El arbol esta vacio";
    }
}

void Gestor::sociosOrdenados(){
    if(!arbolAficionados.vacio()){ 
            cout<<"Los socios ordenados de menor a mayor son: ";
            arbolAficionados.mostrar("socio");
    }else{
        cout<<"El arbol esta vacio";
    }
}

void Gestor::simpatizantesOrdenados(){
    if(!arbolAficionados.vacio()){    
            cout<<"Los simpatizantes ordenador de menor a mayor son: ";
            arbolAficionados.mostrar("simpatizante");
    }else{
        cout<<"El arbol esta vacio";    
    }
}

void Gestor::todosAficionados(){
    if(!arbolAficionados.vacio()){    
        cout<<"Los Aficionados en inorden son : ";
        arbolAficionados.mostrar("aficionado");
    }else{
        cout<<"El arbol esta vacio";    
    }
}

void Gestor::buscar(){
    if(!arbolAficionados.vacio()){    
        arbolAficionados.buscar();
    }else{
        cout<<"El arbol esta vacio";    
    }
}

void Gestor::mostrarAficionadosPares(){
    if(!arbolAficionados.vacio()){    
        arbolAficionados.aficionadosPares();
        cout<<endl<<"Mostrar los aficionados pares "<<endl;
        arbolAficionados.mostrar("socio");
    }else{
        cout<<"El arbol esta vacio";    
    }
}
void Gestor::mostrarHojas(){
    if(!arbolAficionados.vacio()){    
        cout<<"Los nodos hojas son:"<<endl;
        arbolAficionados.mostrarHojas();
    }else{
        cout<<"El arbol esta vacio";    
    }
}

void Gestor::eliminarNodo(){
    if(!arbolAficionados.vacio()){    
        int id;
        cout<<"Introduzca el Id que desea eliminar";
        cin>>id;

        if(arbolAficionados.existe(id)){
            cout<<"Existe vamos a borrar el id. ";
            arbolAficionados.eliminar(id);
            arbolAficionados.dibujar();
        }else{
            cout<<"Vuelva a introducir otro id a eliminar,ya que el introducido previamente no existe";
        }
    }else{
        cout<<"El arbol esta vacio";    
    }
}

void Gestor::reiniciar()
{
    cout<<"Vamos a reiniciar"; //Llamamos a los destructores de cada clase.
    pilaAficionados.~Pila();
    colaSimpatizantes.~Cola();
    colaSocios.~Cola();
    listaSocios.~Lista();
    arbolAficionados.~Arbol();
  
}

Gestor::~Gestor()
{
}
