#include<iostream>
#include "hanoi.h"

using namespace std;

int main()
{
	Varilla* varilla = new Varilla();
	varilla->Imprimir(0);
	cout << endl;
	varilla->Imprimir(1);
	cout << endl;
	varilla->Imprimir(2);
	/*string varillaOrigen;
	string varillaDestino;
	bool finJuego = false;
	while (!finJuego)
	{
		cout << "Ingrese numero de varilla/torre origen";
		cin >> varillaOrigen;
		cout << "Ingrese numero de varilla/torre destino";
		cin >> varillaDestino;

		//finJuego = ValidarFinJuego(varillaOrigen, varillaDestino);
	}*/
	return 0;
}