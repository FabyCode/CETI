#include <iostream>
#include <vector>
using namespace std;

class Matriz
{
private:
    int** matriz;
    int tam;
public:
    Matriz(int n)
    {
        tam = n;
        matriz = new int* [tam];
        for (int i = 0; i < tam; i++) {
            matriz[i] = new int[tam];
        }
    };
    ~Matriz()
    {
        for (int i = 0; i < tam; i++)
        {
            delete[] matriz[i];
        }
        delete[] matriz;
    };

    void llenar()
    {
        for (int i = 0; i < tam; i++) {
            for (int j = 0; j < tam; j++) {
                cout << "Ingrese el elemento [" << i << "][" << j << "]: ";
                cin >> matriz[i][j];
            }
        }
    }

    int determinante() {
        int det = 0;
        if (tam == 2) {
            det = (matriz[0][0] * matriz[1][1]) - (matriz[0][1] * matriz[1][0]);
        }
        else {
            for (int i = 0; i < tam; i++) {
                Matriz submatriz(tam - 1);
                for (int j = 1; j < tam; j++) {
                    int k = 0;
                    for (int l = 0; l < tam; l++) {
                        if (l != i) {
                            submatriz.matriz[j - 1][k++] = matriz[j][l];
                        }
                    }
                }
                det += (i % 2 == 1 ? -1 : 1) * matriz[0][i] * submatriz.determinante();
            }
        }
        return det;
    }
};

class metodos
{
public:
    vector<int> vecArr;
    int Arr[50] = { 0 };
    int tam;

    void leer()
    {
        for (int i = 0; i <= tam; i++)
        {
            cout << "Introduce el dato en la posicion [" << i << "]: ";
            fflush(stdin);
            cin >> Arr[i];
        }
    }
    void muestra()
    {
        for (int i = 0; i <= tam; i++)
        {
            cout << Arr[i] << " ";
        }
        cout << endl;
    }

    void burbuja()
    {
        for (int i = 0; i <= tam; i++)
        {
            for (int j = 1; j <= tam; j++)
            {
                if (Arr[j] < Arr[j - 1])
                {
                    int temp = Arr[j];
                    Arr[j] = Arr[j - 1];
                    Arr[j - 1] = temp;
                }
            }
        }
    }
    void burbujamuestra()
    {
        int temp;
        for (int i = 0; i < tam; i++)
        {
            for (int j = 1; j <= tam; j++)
            {
                if (Arr[j] < Arr[j - 1])
                {
                    temp = Arr[j];
                    Arr[j] = Arr[j - 1];
                    Arr[j - 1] = temp;
                }
            }
            for (int k = 0; k <= tam; k++) {
                cout << Arr[k] << " ";
            }
            cout << endl;
        }
    }

    void seleccion()
    {
        int min;
        int temp;
        for (int i = 0; i <= tam - 1; i++)
        {
            min = i;
            for (int j = i + 1; j <= tam; j++)
            {
                if (Arr[j] < Arr[min])
                {
                    min = j;
                }
            }
            temp = Arr[min];
            Arr[min] = Arr[i];
            Arr[i] = temp;  //swap(v, v2);
        }
    }
    void seleccionmuestra()
    {
        int min;
        int temp;
        for (int i = 0; i <= tam - 1; i++)
        {
            min = i;
            for (int j = i + 1; j <= tam; j++)
            {
                if (Arr[j] < Arr[min])
                {
                    min = j;
                }
            }
            temp = Arr[min];
            Arr[min] = Arr[i];
            Arr[i] = temp;
            for (int k = 0; k <= tam; k++)
            {
                cout << Arr[k] << " ";
            }
            cout << endl;
        }
    }

    void insercion() {
        int temp, k;
        for (int i = 1; i <= tam; i++) {
            temp = Arr[i];
            k = i - 1;

            while (k >= 0 && Arr[k] > temp) {
                Arr[k + 1] = Arr[k];
                k = k - 1;
            }
            Arr[k + 1] = temp;

            muestra();
        }
    }

    void shell() {
        int salto, j, temp;

        for (salto = tam / 2; salto > 0; salto /= 2) {
            for (int i = salto; i <= tam; i++) {
                temp = Arr[i];
                for (j = i; j >= salto && Arr[j - salto] > temp; j -= salto) {
                    Arr[j] = Arr[j - salto];
                }
                Arr[j] = temp;

            }
        }
    }
    void shellmuestra() {
        int salto, j, temp;

        for (salto = tam / 2; salto > 0; salto /= 2) {
            for (int i = salto; i <= tam; i++) {
                temp = Arr[i];
                for (j = i; j >= salto && Arr[j - salto] > temp; j -= salto) {
                    Arr[j] = Arr[j - salto];
                }
                Arr[j] = temp;

                muestra();
            }
        }
    }

    metodos(int n)
    {
        tam = n;
    }

    ~metodos() {}
};



int main() {
    int n;
    int op, subop;
    char p;
    do {
        cout << "Introduzca la operacion que desea realizar: \n\n[1] Determinantes\t[6] M. shell\n[2] M. Burbuja\t\t[7] M. merge\n[3] M. Seleccion\t[8] M. Radix\n[4] M. Insercion\t[9] M. Tabla Hash\n[5] M. Quicksort\t[10] M. Busca Secuencial\n\t[11] M. Busqueda Binaria\n" << endl;
        cin >> op;
        switch (op)
        {
        case 1:
        {
            cout << "Ingrese el tamaño de la matriz: (2-10) ";
            cin >> n;
            if (n >= 2 && n <= 10)
            {
                Matriz m(n);
                m.llenar();
                cout << "La determinante de la matriz es: " << m.determinante() << endl;
            }
            else
            {
                cout << "Valores no permitidos" << endl;
            }
        }//case 1 (recursividad)
        break;
        case 2:
        {
            cout << "Que tipo de ordenancion quieres? (1) Al final (2) Por pasos ";
            cin >> subop;
            switch (subop)
            {
            case 1:
            {
                cout << "Determina el tamanio del arreglo: " << endl;
                cin >> n;
                if (n >= 1 && n <= 50)
                {
                    metodos m(n);
                    m.leer();
                    m.burbuja();
                    m.muestra();
                }
                else
                {
                    cout << "Valores no permitidos" << endl;
                }
            } break;
            case 2:
            {
                cout << "Determina el tamanio del arreglo: " << endl;
                cin >> n;
                if (n >= 1 && n <= 50)
                {
                    metodos m(n);
                    m.leer();
                    m.burbujamuestra();
                }
                else
                {
                    cout << "Valores no permitidos" << endl;
                }
            } break;
            default:
            {
                cout << "Opción no valida" << endl;
            }
            break;
            }//subcase
        }//case 2 (burbuja)
        break;
        case 3:
        {
            cout << "Que tipo de ordenancion quieres? (1) Al final (2) Por pasos ";
            cin >> subop;
            switch (subop)
            {
            case 1:
            {
                cout << "Determina el tamanio del arreglo: " << endl;
                cin >> n;
                if (n >= 1 && n <= 50)
                {
                    metodos m(n);
                    m.leer();
                    m.seleccion();
                    m.muestra();
                }
                else
                {
                    cout << "Valores no permitidos" << endl;
                }
            } break;
            case 2:
            {
                cout << "Determina el tamanio del arreglo: " << endl;
                cin >> n;
                if (n >= 1 && n <= 50)
                {
                    metodos m(n);
                    m.leer();
                    m.seleccionmuestra();
                }
                else
                {
                    cout << "Valores no permitidos" << endl;
                }
            } break;
            default:
            {
                cout << "Opción no valida" << endl;
            }
            break;
            }//subcase
        }//case 3 (selección)
        break;
        case 4:
        {
            cout << "Determina el tamanio del arreglo: " << endl;
            cin >> n;
            if (n >= 1 && n <= 50)
            {
                metodos m(n);
                m.leer();
                m.insercion();
            }
            else
            {
                cout << "Valores no permitidos" << endl;
            }
        }//case 4 (insercion)
        break;
        case 5:
        {

        }//case 5 (quicksort)
        break;
        case 6:
        {
            cout << "Que tipo de ordenancion quieres? (1) Al final (2) Por pasos ";
            cin >> subop;
            switch (subop)
            {
            case 1:
            {
                cout << "Determina el tamanio del arreglo: " << endl;
                cin >> n;
                if (n >= 1 && n <= 50)
                {
                    metodos m(n);
                    m.leer();
                    m.shell();
                    m.muestra();
                }
                else
                {
                    cout << "Valores no permitidos" << endl;
                }
            } break;
            case 2:
            {
                cout << "Determina el tamanio del arreglo: " << endl;
                cin >> n;
                if (n >= 1 && n <= 50)
                {
                    metodos m(n);
                    m.leer();
                    m.shellmuestra();
                }
                else
                {
                    cout << "Valores no permitidos" << endl;
                }
            } break;
            default:
            {
                cout << "Opción no valida" << endl;
            }
            break;
            }//subop
        }//case 6 (shell)
        break;
        case 7:
        {
            cout << "Determina el tamanio del arreglo: " << endl;
            cin >> n;
            if (n >= 1 && n <= 50)
            {
                metodos m(n);
                m.leer();
                m.mergeSort(0, n);
            }
            else
            {
                cout << "Valores no permitidos" << endl;
            }
        }//case 7 (merge)
        break;
        case 8:
        {
            
        }//case 8 (radix)
        break;
        case 9:
        {

        }//case 9 (tabla hash)
        break;
        case 10:
        {

        }//case 10 (busqueda secuencial)
        break;
        case 11:
        {

        }//case 11 (busqueda binaria)
        break;
        }//switch
        cout << "\nDesea volver a realizar otra operacion? (Y/N)  ";
        cin >> p;
    } while (p != 'N');
    return 0;
}