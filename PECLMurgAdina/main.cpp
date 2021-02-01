#include "Gestor.hpp"
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    Gestor gestor;
    char opcion;
    do {

        /* cout << "\n\t----------------------------------------------------------------------\n";
         cout << "\t" << gestor.getNumAficionados() << " Aficionados en la pila. " << gestor.getNumSociosEnCola()
              << " Socios en cola. " << gestor.getNumSimpatizantesEnCola() << " Simpatizantes en cola.\n ";
         cout << "\t----------------------------------------------------------------------\n\n";*/

        cout << "\n\t----------------------------------------------------------------------\n";
        cout << "\t" << 0 << " Aficionados en la pila. " << 0 << " Socios en cola. " << 0
             << " Simpatizantes en cola.\n ";
        cout << "\t----------------------------------------------------------------------\n\n";

        cout << "\t0. Generar 10 aficionados de forma aleatoria.\n";
        cout << "\t1. Consultar todos los aficionados generados en la Pila (pendientes de entrar en las colas).\n";
        cout << "\t2. Borrar los aficionados generados en la pila.\n";
        cout << "\t3. Simular llegada de los aficionados en las colas.\n";
        cout << "\t4. Consultar la cola de aficionados socios.\n";
        cout << "\t5. Consultar la cola de aficionados no socios.\n";
        cout << "\t6. Borrar los todos los aficionados de las colas.\n";
        cout << "\t7. Simular la entrada de los aficionados al estadio (a la lista).\n";
        cout << "\t8. Buscar en la lista el socio y el simpatizante que mas temprano y mas tarde han llegado al "
                "estadio.\n";
        cout << "\tX. Crear el arbol.\n";
        cout << "\tA. Dibujar el arbol en la consola.\n";
        cout << "\tB. Mostrar los datos de todos los socios ordenados por sus IDs de menor a mayor.\n";
        cout << "\tC. Mostrar los datos de todos los simpatizantes ordenados por sus IDs de menor a mayor.\n";
        cout << "\tD. Mostrar los datos de todos los aficionados recorriendo el ABB en inorden.\n";
        cout << "\tE. Buscar en el arbol el socio y  el simpatizante que mas temprano y mas tarde han llegado al "
                "estadio.\n";
        cout << "\tF. Contar el numero de aficionados almacenados en el ABB cuyos IDs son pares.\n";
        cout << "\tG. Mostrar los aficionados que se encuentran almacenados en un nodo hoja.\n";
        cout << "\tH. Eliminar un aficionado indicado por su ID (que se pide desde consola). Mostrar el arbol resultante "
                 "tras la eliminacion de dicho aficionado..\n";
        cout << "\t9. Reiniciar el programa.\n";
        cout << "\tS. Salir.\n\n";
        cout << "\tIndique la opcion deseada: ";
        cin >> opcion;
        //system("clear"); // MAC
         system("cls");// Windows
        switch(opcion) {
        
        case '0':
            gestor.genera10Aficionados();
            break;
        case '1':
            gestor.muestraAficionados();
            break;
        case '2':
            gestor.borraAficionados();
            break;
        case '3':
            gestor.encolarAficionados();
            break;
        case '4':
            gestor.muestraSocios();
            break;
        case '5':
            gestor.muestraSimpatizantes();
            break;
        case '6':
            gestor.vaciaColas();
            break;
        case '7':
            gestor.muestraAficionadosEnLista();
            break;
        case '8':
            gestor.buscaSocios();
            break;
        case '9':
            gestor.reiniciar();
            break;
        case 'X':
            gestor.crearArbol();
            break;
        case 'A':
            gestor.dibujarAbb();
            break;
        case 'B':
            gestor.sociosOrdenados();
            break;
        case 'C':
            gestor.simpatizantesOrdenados();
            break;
        case 'D':
            gestor.todosAficionados();
            break;
        case 'E':
            gestor.buscar();
            break;
        case 'F':
            gestor.mostrarAficionadosPares();
            break;
        case 'G':
            gestor.mostrarHojas();
            break;
        case 'H':
            gestor.eliminarNodo();
            break;
        case 'S':
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opcion incorrecta!\n\n";
            break;
        }
    } while(opcion != 'S');

    return 0;
}