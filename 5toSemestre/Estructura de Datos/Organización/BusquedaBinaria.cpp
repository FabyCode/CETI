#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Persona {
private:
    int registro;
    char nombre[50];
    char apellido[50];
    int edad;

public:

    int getRegistro() const {
        return registro;
    }

    char* getNombre() {
        return nombre;
    }

    char* getApellido() {
        return apellido;
    }

    int getEdad() {
        return edad;
    }


    void print()  {
        cout << "+------------------------------------+\n";
        cout << "| Registro: " << std::setw(10) << registro << "             \n";
        cout << "| Nombre: " << std::setw(14) << nombre << "           \n";
        cout << "| Apellido: " << std::setw(12) << apellido << "         \n";
        cout << "| Edad: " << std::setw(16) << edad << "                 \n";
        cout << "+------------------------------------+\n";
    }

    Persona(int registro, const char nombre[], const char apellido[], int edad);
    Persona() {
        registro = 0;
        nombre[0] = '\0';
        apellido[0] = '\0';
        edad = 0;
    }
};

Persona::Persona(int registro, const char nombre[], const char apellido[], int edad) {
    strcpy_s(this->nombre, nombre);
    strcpy_s(this->apellido, apellido);
    this->registro = registro;
    this->edad = edad;
}

class PersonasArray {
public:
    vector<Persona> personas;
    int size;
    //constructor
    PersonasArray(vector<Persona> personas) {
        this->personas = personas;
        this->size = personas.size();
    }

    //método para imprimir información de todas las personas en el array
    void print() {
        for (int i = 0; i < personas.size(); i++) {
            personas[i].print();
        }
    }

    vector<int> getRegistrosOrdenados() {
        vector<int> registrosArray(personas.size());

        for (int i = 0; i < personas.size(); i++) {
            Persona persona = personas.at(i);
            int currentRegistro = persona.getRegistro();
            registrosArray.push_back(currentRegistro);
        }

        int n = personas.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (registrosArray[j] > registrosArray[j + 1]) {
                    // intercambiar elementos
                    int temp = registrosArray[j];
                    registrosArray[j] = registrosArray[j + 1];
                    registrosArray[j + 1] = temp;
                }        
            }
        }

    return registrosArray;
    }

    Persona findByRegistro(int registro) {
        
        vector<int> registrosOrdenados = getRegistrosOrdenados();

        // implementacion de binary search en el arreglo registrosOrdenados buscando "registro"
        int inicio = 0;
        int fin = registrosOrdenados.size() - 1;

        while (inicio <= fin) {
            int medio = (inicio + fin) / 2;

            if (registrosOrdenados[medio] == registro) {
                // hemos encontrado el registro, devolvemos la Persona correspondiente
                for (Persona& persona : personas) {
                    if (persona.getRegistro() == registro) {
                        return persona;
                    }
                }
            }
            else if (registrosOrdenados[medio] > registro) {
                fin = medio - 1;
            }
            else {
                inicio = medio + 1;
            }
        }

        // si no encontramos el registro, devolvemos una Persona con valores predeterminados
        return Persona();
    }

    vector<Persona> findByName(string nombre) {
        vector<Persona> personasEncontradas;
        for (int i = 0; i < personas.size(); i++) {
            Persona persona = personas[i];
            if (persona.getNombre() == nombre) {
                personasEncontradas.push_back(persona);
            }
        }
        return personasEncontradas;
    }
     
    void setPersonas(vector<Persona> nuevasPersonas) {
        personas = nuevasPersonas;
    }
    
};

int main() {
    vector<Persona> vectorPersonas;
    PersonasArray personasArray(vectorPersonas);

    char opcion;
    do {
        cout << "Ingrese una opcion:" << endl;
        cout << "A) Ingresar datos" << endl;
        cout << "B) Buscar datos" << endl;
        cout << "C) Salir" << endl;

        cin >> opcion;
        opcion = toupper(opcion);

        switch (opcion) {
        case 'A': {
            string nuevoRegistro;
            string nuevoNombre;
            string nuevoApellido;
            int nuevaEdad;

            cout << "Ingrese los datos de la nueva persona: " << endl;

            do {
                cout << "Registro (8 digitos): ";
                cin >> nuevoRegistro;
            } while (nuevoRegistro.length() != 8 || nuevoRegistro.find_first_not_of("0123456789") != string::npos || stoi(nuevoRegistro) <= 0);

            cout << "Nombre: ";
            cin.ignore(); // se ignora el salto de línea que queda en el buffer
            getline(cin, nuevoNombre); // se utiliza getline para leer toda la cadena
            cout << "Apellido: ";
            getline(cin, nuevoApellido);

            do {
                cout << "Edad: ";
                cin >> nuevaEdad;
            } while (nuevaEdad <= 0);

            // Validar si ya existe el registro
            bool existeRegistro = false;
            for (const auto& persona : vectorPersonas) {
                if (persona.getRegistro() == stoi(nuevoRegistro)) {
                    existeRegistro = true;
                    cout << "Error: el registro ya existe." << endl;
                    break;
                }
            }

            if (!existeRegistro) {
                // crear nueva persona
                Persona nuevaPersona(stoi(nuevoRegistro), nuevoNombre.c_str(), nuevoApellido.c_str(), nuevaEdad);
                vectorPersonas.push_back(nuevaPersona);
                personasArray.setPersonas(vectorPersonas);
            }

            break;
        }
        case 'B': {
            char opcionBusqueda;
            cout << "Ingrese una opcion de busqueda:" << endl;
            cout << "A) Por nombre" << endl;
            cout << "B) Por registro" << endl;
            cin >> opcionBusqueda;
            opcionBusqueda = toupper(opcionBusqueda);

            if (opcionBusqueda == 'A') {
                string nombreBuscado;
                cout << "Ingrese el nombre que desea buscar: ";

                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, nombreBuscado);

                vector<Persona> personasEncontradas = personasArray.findByName(nombreBuscado);
                if (personasEncontradas.empty()) {
                    cout << "Personas no encontradas" << endl;
                }
                else {
                    cout << "Personas encontradas: ";
                    cout << personasEncontradas.size() << endl;
                    for (int i = 0; i < personasEncontradas.size(); i++) {
                        personasEncontradas[i].print();

                    }
                }
            }
            else if (opcionBusqueda == 'B') {
                int registroBuscado;
                cout << "Ingrese el registro que desea buscar: ";
                cin >> registroBuscado;

                Persona personaEncontrada = personasArray.findByRegistro(registroBuscado);
                if (personaEncontrada.getRegistro() == 0) {
                    cout << "Persona no encontrada" << endl;
                }
                else {
                    cout << "Persona encontrada:" << endl;
                    personaEncontrada.print();
                }
            }
            else {
                cout << "Opcion no valida" << endl;
            }
            break;
        }
        case 'C':
            // Salir del programa
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
    } while (opcion != 'C');

    return 0;
}