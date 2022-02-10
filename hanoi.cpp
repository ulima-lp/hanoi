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
{
	disco->siguienteDisco = this->primerDisco;
	this->primerDisco = disco;
	this->longitud++;
}
Disco* Varilla::DesapilarDisco()
{
	if (this->primerDisco != nullptr)
	{
		Disco* discoADesapilar = primerDisco;
		primerDisco = discoADesapilar->siguienteDisco;
		discoADesapilar->siguienteDisco = nullptr;

		this->longitud--;
	
		return discoADesapilar;
	}
	else
	{
		return nullptr;
	}
}

void Varilla::Imprimir(int nivel)
{
	// nivel : 0 longitud : 2
	/*Disco* disco = ObtenerDisco(nivel + longitud - 3);
	if (disco != nullptr) 
		disco->Imprimir();
	else cout << "      |      ";*/

	Disco* disco = nullptr;
	if (this->longitud == 3)
	{
		if (nivel == 2)
		{
			disco = ObtenerDisco(0);
		}
		else if (nivel == 1)
		{
			disco = ObtenerDisco(1);
		}
		else if (nivel == 0)
		{
			disco = ObtenerDisco(2);
		}
	}
	else if (this->longitud == 2)
	{
		if (nivel == 2)
		{
			disco = nullptr;
		}
		else if (nivel == 1)
		{
			disco = ObtenerDisco(0);
		}
		else if (nivel == 0)
		{
			disco = ObtenerDisco(1);
		}
	}
	else if (this->longitud == 1)
	{
		if (nivel == 2)
		{
			disco = nullptr;
		}
		else if (nivel == 1)
		{
			disco = nullptr;
		}
		else if (nivel == 0)
		{
			disco = ObtenerDisco(0);
		}
	}

	if (disco != nullptr)
	{
		disco->Imprimir();
	}
	else
	{
		cout << "    |    ";
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

	Disco* disco1 = new Disco(1);
	Disco* disco2 = new Disco(2);
	Disco* disco3 = new Disco(3);

	this->varilla1->ApilarDisco(disco3);
	this->varilla1->ApilarDisco(disco2);
	this->varilla1->ApilarDisco(disco1);
}
void Juego::ProcesarMovimiento(string letraOrigen, string letraDestino)
{
	Varilla* varillaOrigen = ObtenerVarilla(letraOrigen);
	Varilla* varillaDestino = ObtenerVarilla(letraDestino);

	Disco* disco = varillaOrigen->DesapilarDisco();
	Disco* discoEnLaCabeza = varillaDestino->ObtenerDisco(0);
	if (discoEnLaCabeza != nullptr)
	{
		if (disco->numero < discoEnLaCabeza->numero)
		{
			varillaDestino->ApilarDisco(disco);
		}
		else
		{
			varillaOrigen->ApilarDisco(disco);
			cout << "Movimiento invalido" << endl;
		}
	}
	else
	{
		varillaDestino->ApilarDisco(disco);
	}
	
}
void Juego::ImprimirJuego()
{
	this->varilla1->Imprimir(2);
	this->varilla2->Imprimir(2);
	this->varilla3->Imprimir(2);
	cout << endl;
	this->varilla1->Imprimir(1);
	this->varilla2->Imprimir(1);
	this->varilla3->Imprimir(1);
	cout << endl;
	this->varilla1->Imprimir(0);
	this->varilla2->Imprimir(0);
	this->varilla3->Imprimir(0);
	cout << endl;
}
bool Juego::VerificarGanador()
{
	return this->varilla2->longitud == 3 || 
		this->varilla3->longitud == 3;
}

Varilla* Juego::ObtenerVarilla(string letra)
{
	if (letra == "A") return this->varilla1;
	if (letra == "B") return this->varilla2;
	if (letra == "C") return this->varilla3;
}