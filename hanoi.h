#include<iostream>

using namespace std;

class Disco
{
	int numero;
public:
	Disco* siguienteDisco;
	Disco(int num);
	void Imprimir();
};

class Varilla
{
	Disco* primerDisco;
public:
	int longitud;
	Varilla();
	void ApilarDisco(Disco* disco);
	Disco* DesapilarDisco();
	void Imprimir(int nivel);
	Disco* ObtenerDisco(int pos);
};

class Juego
{
	Varilla* varilla1;
	Varilla* varilla2;
	Varilla* varilla3;
public:
	Juego();
	void ProcesarMovimiento(string varillaOrigen, string varillaDestino);
	void ImprimirJuego();
	bool VerificarGanador();
};