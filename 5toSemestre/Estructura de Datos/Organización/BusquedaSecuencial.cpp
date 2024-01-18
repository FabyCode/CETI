#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

struct Datos {
    string nombre;
    string apellido;
    int registro;
    int edad;
};

void insertionSort(Datos arr[], int n) {
    int i, j;
    Datos key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j].registro > key.registro) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void sequentialSearch(Datos arr[], int n, string campo, string valor) {
    bool encontrado = false;
    for (int i = 0; i < n; i++) {
        if (campo == "Nombre") {
            if (arr[i].nombre == valor) {
                encontrado = true;
                cout << "Nombre: " << arr[i].nombre << endl;
                cout << "Apellido: " << arr[i].apellido << endl;
                cout << "Registro: " << arr[i].registro << endl;
                cout << "Edad: " << arr[i].edad << endl << endl;
            }
        }
        else if (campo == "Registro") {
            if (arr[i].registro == stoi(valor)) {
                encontrado = true;
                cout << "Nombre: " << arr[i].nombre << endl;
                cout << "Apellido: " << arr[i].apellido << endl;
                cout << "Registro: " << arr[i].registro << endl;
                cout << "Edad: " << arr[i].edad << endl << endl;
            }
        }
        else {
            cout << "Campo de búsqueda no válido" << endl;
            break;
        }
    }
    if (!encontrado) {
        cout << "No se encontraron coincidencias" << endl;
    }
}

int main()
{
    Datos arr[50];
    int n, op;
    string campo, valor;
    cout << "Determina el numero maximo de datos: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Ingrese los datos del objeto " << i + 1 << endl;
        cout << "Nombre: ";
        cin >> arr[i].nombre;
        fflush(stdin);
        cout << "Apellido: ";
        cin >> arr[i].apellido;
        fflush(stdin);
        cout << "Registro: ";
        cin >> arr[i].registro;
        fflush(stdin);
        cout << "Edad: ";
        cin >> arr[i].edad;
        fflush(stdin);
        cout << endl;
    }
    cout << "Elija una opcion de ordenamiento:" << endl;
    cout << "1. Ordenar por Registro" << endl;
    cout << "2. Ordenar por Nombre" << endl;
    cin >> op;
    if (op == 1) {
        insertionSort(arr, n);
    }
    else if (op == 2) {
        sort(arr, arr + n, [](const Datos& lhs, const Datos& rhs) {
            return lhs.nombre < rhs.nombre;
            });
    }
    else {
        cout << "Opción no válida" << endl;
        return 0;
    }
}
