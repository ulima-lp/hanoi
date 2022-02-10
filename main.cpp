#include<iostream>
#include "hanoi.h"

using namespace std;

int main()
{
	Juego* juego = new Juego();

	string varillaOrigen;
	string varillaDestino;
	bool finJuego = false;
	while (!finJuego)
	{
		cout << "Ingrese numero de varilla/torre origen:";
		cin >> varillaOrigen;
		cout << "Ingrese numero de varilla/torre destino:";
		cin >> varillaDestino;

		juego->ProcesarMovimiento(varillaOrigen, varillaDestino);
		juego->ImprimirJuego();
		finJuego = juego->VerificarGanador();
		if (finJuego) cout << "GANADO!!";
	}
	return 0;
}