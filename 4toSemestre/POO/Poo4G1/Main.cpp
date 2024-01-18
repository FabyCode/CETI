#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cstring>

using namespace std;

void leer();
void leer2();
char nom[50];
int nofactura;
float total;

class Factura {
public:
	char nom[50];
	int nofactura;
	float total;
	Factura(char*, int, float);
	Factura(char*, float);
	Factura() {};
	~Factura();

	void muestra();
	void muestra2();
};

Factura::Factura(char* nom, int nofactura, float total)
{
	strcpy_s(Factura::nom, nom);
	Factura::nofactura = nofactura;
	Factura::total = total;
}

Factura::Factura(char* nom, float total)
{
	strcpy_s(Factura::nom, nom);
	Factura::total = total;
}

void leer()
{
	cout << "Registra los datos: " << endl;
	fflush(stdin);
	cout << "\nCliente: ";
	gets_s(nom); gets_s(nom);
	fflush(stdin);
	cout << "\nNo. de factura: ";
	cin >> nofactura;
	fflush(stdin);
	cout << "\nTotal de ventas: ";
	cin >> total;
}
void leer2()
{
	cout << "Registra los datos: " << endl;
	fflush(stdin);
	cout << "\nCliente: ";
	gets_s(nom); gets_s(nom);
	fflush(stdin);
	cout << "\nTotal de ventas: ";
	cin >> total;
}

void Factura::muestra()
{
	cout << "Datos capturados" << endl;
	fflush(stdout);
	cout << "\nCliente: ";
	cout << nom;
	fflush(stdout);
	cout << "\nNo. de factura: ";
	cout << nofactura;
	fflush(stdout);
	cout << "\nTotal de ventas: ";
	cout << total;
}
void Factura::muestra2()
{
	cout << "Datos capturados" << endl;
	fflush(stdout);
	cout << "\nCliente: ";
	cout << nom;
	fflush(stdout);
	cout << "\nTotal de ventas: ";
	cout << total;
}
Factura::~Factura()
{
	cout << "\nDestruyendo" << endl;
}
int
main(int argc, char** argv)
{
	char opcion;
	int subop;
	do
	{
		cout << "Menu\n[A] Crear ob1 con 3 atributos\n[B] Crear ob2 con 2 atributos\n[C] Consultar objetos\n[S] Salir\n\n";
		fflush(stdin);
		cin >> opcion;
		switch (opcion)
		{
		case 'A':
		{
			leer();
			Factura ob1(nom, nofactura, total);
		}
		break;
		case 'B':
		{
			leer2();
			Factura ob2(nom, total);
		}
		break;
		case 'C':
		{
			do
			{
				cout << "Sub Menu\n[1] Mostrar ob1\n[2] Mostrar ob2\n[3] Salir\n\n";
				fflush(stdin);
				cin >> subop;
				switch (subop)
				{
				case 1:
				{
					Factura ob1(nom, nofactura, total);
					ob1.muestra();
				}
				break;
				case 2:
				{
					Factura ob2(nom, total);
					ob2.muestra2();

				}
				break;
				}
			} while (subop != 3);
		}
		break;
		}
	} while (opcion != 'S');
	return 0;
}


