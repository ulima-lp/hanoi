#include "hanoi.h"
// ------------------- Disco -----------------------
Disco::Disco(int num)
{
	this->numero = num;
	this->siguienteDisco = nullptr;
}
void Disco::Imprimir()
{
	if (numero == 1) 
	{
		cout << "    _    ";
	}
	else if (numero == 2) 
	{
		cout << "  _ _ _  ";
	}
	else if (numero == 3)
	{
		cout << "_ _ _ _ _";
	}
}

// ------------------- Varilla ---------------------

Varilla::Varilla()
{
	this->primerDisco = nullptr;
	this->longitud = 0;
}
void Varilla::ApilarDisco(Disco* disco)
{}
Disco* Varilla::DesapilarDisco()
{
	return nullptr;
}

void Varilla::Imprimir(int nivel)
{
	if (nivel == 0) 
	{
		if (this->longitud < 3)
		{
			cout << "|";
		}
		else
		{
			Disco* disco = ObtenerDisco(nivel);
			disco->Imprimir();
		}
	}
	else if (nivel == 1)
	{
		if (this->longitud < 2)
		{
			cout << "|";
		}
		else
		{
			Disco* disco = ObtenerDisco(nivel);
			disco->Imprimir();
		}
	}
	else if (nivel == 2)
	{
		if (this->longitud < 1)
		{
			cout << "|";
		}
		else
		{
			Disco* disco = ObtenerDisco(nivel);
			disco->Imprimir();
		}
	}
}

Disco* Varilla::ObtenerDisco(int pos)
{
	int cont = 0;
	Disco* pDisco = this->primerDisco;
	while (pDisco != nullptr)
	{
		if (pos == cont)
		{
			return pDisco;
		}
		pDisco = pDisco->siguienteDisco;
		cont++;
	}
	return nullptr;
}

// -------------------- Juego ----------------------
Juego::Juego()
{
	this->varilla1 = new Varilla();
	this->varilla2 = new Varilla();
	this->varilla3 = new Varilla();
}
void Juego::ProcesarMovimiento(string varillaOrigen, string varillaDestino)
{}
void Juego::ImprimirJuego()
{}
bool Juego::VerificarGanador()
{
	return true;
}