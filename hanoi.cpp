#include "hanoi.h"
// ------------------- Disco -----------------------
Disco::Disco(int num)
{}
void Disco::Imprimir()
{}

// ------------------- Varilla ---------------------

Varilla::Varilla()
{}
void Varilla::ApilarDisco(Disco* disco)
{}
Disco* Varilla::DesapilarDisco()
{}
void Varilla::Imprimir()
{}

// -------------------- Juego ----------------------
Juego::Juego()
{}
void Juego::ProcesarMovimiento(string varillaOrigen, string varillaDestino)
{}
void Juego::ImprimirJuego()
{}
bool Juego::VerificarGanador()
{}