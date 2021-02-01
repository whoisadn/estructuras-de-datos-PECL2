#include "Lista.hpp"

Lista::Lista()
{
    primero=NULL;
    longitud=0;
}

void Lista::insertarOrden(Aficionado a1){
    
    lnodo aux, lp;
    lp = new NodoLista(a1);
    if(longitud==0){ //Si la lista esta vacía 
        primero=lp; 
        lp->siguiente=NULL;
    }
    else{
        aux=primero; //Aux apuntara a primero y lo utilizaremos para recorrer la lista. 
        //Utilizaremos los minutos de llegada en las comparaciones.
        if (lp->aficionado1.getMllegada()<aux->aficionado1.getMllegada()){ //Caso en el que el aficionado a insertar es al principio.
            lp->siguiente=primero;
            primero=lp;
        }else{  //El aficionado a insertar esta en medio de la lista.
            while((aux->siguiente!=NULL) && (aux->siguiente->aficionado1.getMllegada()<lp->aficionado1.getMllegada())){
                aux=aux->siguiente; 
            }
            lp->siguiente=aux->siguiente;//Siguiente de lp será el número mayor de aux 
            aux->siguiente=lp;//El siguiente de aux sera lp que es menor que lp
        }
    }
    longitud++;

}

void Lista::concatenar(Lista simpatizantes){
    lnodo aux;
    aux=primero;//aux es igual al primero de listaSocios.
    
    while(aux->siguiente!=NULL){ //Pararemos cuando lleguemos al último elemento de la listaSocios
            aux=aux->siguiente;
    }
    aux->siguiente=simpatizantes.primero; //El último nodo apuntara al primero de simpatizantes
    longitud=longitud+simpatizantes.longitud; //Sumamos la longitud de la listaSocios más la longitud de simpatizantes
    
}



//METODO CORRECTO
Aficionado Lista::elemento(){
    Aficionado af1;
    lnodo aux;
    if(primero!=NULL){ //Si hay elementos en la lista
        aux=primero;// Aux es igual a primero
        primero=aux->siguiente;
        af1=aux->aficionado1;
        aux->siguiente=NULL;
        delete(aux);
        longitud--;
        
    }
    return af1;
}


bool Lista::listaVacia(){
	if(longitud == 0){
		return true;
	}
	else{
		return false;
	}
}

void Lista::mostrarLista()
{
  lnodo aux;
  aux = primero;
  if (aux != NULL){
    while(aux){
      aux->aficionado1.mostrar();
      aux = aux->siguiente;
    }
  }else{
    cout <<"La Lista esta vacia y/o se han acabado los elementos, ya no hay mas elementos";
  }

}

void Lista::mostrarAficionados() //Mostraremos los Socios y Aficionados que han llegado más pronto y más tarde.
{
    lnodo aux;
    aux=primero;
    if(aux!=NULL){
        cout<<"El socio que ha llegado mas pronto es :"<<endl;
        aux->aficionado1.mostrar();
        while(aux){
            if((aux->aficionado1.esSocio()) &&( aux->siguiente->aficionado1.esSocio()==false)){
                cout<<"El socio que ha llegado mas tarde es: "<<endl;
                aux->aficionado1.mostrar();
                cout<<"El simpatizante que ha llegado mas pronto es: "<<endl;
                aux->siguiente->aficionado1.mostrar();
            }
            if((aux->aficionado1.esSocio()==false)&&(aux->siguiente==NULL)){
                cout<<"El simpatizante que ha llegado mas tarde es: "<<endl;
                aux->aficionado1.mostrar();
            }
            aux=aux->siguiente;
        }
    }else{
        cout<<"La lista esta vacia";
    }

}
int Lista::getLongitud()
{
    return longitud;
}


Lista::~Lista()
{
    primero=NULL;
    longitud=0;
}

