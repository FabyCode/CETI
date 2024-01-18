#include <iostream>
#include <string>
#include <stack>

using namespace std;


struct Elemento 
{
    string nombre;
    string apellido;
    int registro;
    int edad;
};


class TablaHash 
{
private:
    static const int TAM_TABLA = 113;
    stack<Elemento> tabla[TAM_TABLA];

    
    int funcionHash(int registro) 
    {
        return registro % TAM_TABLA;
    }

public:
    
    void insertar(Elemento e) 
    {
        int indice = funcionHash(e.registro);
        tabla[indice].push(e);
    }

    
    void buscar(int registro) 
    {
        int indice = funcionHash(registro);
        while (!tabla[indice].empty()) 
        {
            Elemento e = tabla[indice].top();
            if (e.registro == registro) 
            {
                cout << "Nombre: " << e.nombre << endl;
                cout << "Apellido: " << e.apellido << endl;
                cout << "Registro: " << e.registro << endl;
                cout << "Edad: " << e.edad << endl;
                return;
            }
            tabla[indice].pop();
        }
        cout << "Elemento no encontrado" << endl;
    }
};

int main() 
{
    TablaHash tabla;
    int numElementos;
    cout << "Ingrese el numero de elementos a insertar (max 50): ";
    cin >> numElementos;
    while (numElementos < 1 || numElementos > 50) 
    {
        cout << "Número de elementos inválido. Ingrese de nuevo: ";
        cin >> numElementos;
    }

    
    for (int i = 0; i < numElementos; i++) 
    {
        Elemento e;
        cout << "Ingrese los datos para el elemento #" << i + 1 << endl;
        cout << "Nombre: ";
        cin >> e.nombre;
        cout << "Apellido: ";
        cin >> e.apellido;
        cout << "Registro: ";
        cin >> e.registro;
        cout << "Edad: ";
        cin >> e.edad;
        tabla.insertar(e);
    }

    
    int registroBusqueda;
    cout << "Ingrese el registro del elemento a buscar: ";
    cin >> registroBusqueda;
    tabla.buscar(registroBusqueda);

    return 0;
}