#include<iostream>

using namespace std;

int main()
{
	string varillaOrigen;
	string varillaDestino;
	bool finJuego = false;
	while (!finJuego)
	{
		cout << "Ingrese numero de varilla/torre origen";
		cin >> varillaOrigen;
		cout << "Ingrese numero de varilla/torre destino";
		cin >> varillaDestino;

		finJuego = ValidarFinJuego(varillaOrigen, varillaDestino);
	}
	return 0;
}