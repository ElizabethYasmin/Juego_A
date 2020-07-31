#pragma once

#include "Escenario.h"
#include"Jugador.h"
#include "ArrBombas.h"

class Controladora
{
public:
	Controladora() {
		oEscenario = new Escenario();
		oJugador = new Jugador(50,50);
		oArrBombas = new ArrBombas();
		

	}
	~Controladora();
	void CambiarNivel() {
		oEscenario->generarMatriz();
	}

	void agregarBomba() {
		oArrBombas->crear_una_bomba(oJugador->getX(), oJugador->getY());
	}
	void dibujar(Graphics^ g, Bitmap^ bmpBase, Bitmap^ bmpSolido, Bitmap^ bmpBomba, Bitmap^ bmpExplosion, Bitmap^ bmpDestruible,Bitmap^bmpJugador) {
		oEscenario->PintarBase(g, bmpBase);
		oEscenario->PintarMatriz(g, bmpSolido, bmpDestruible);
		oJugador->moverJugador(g, bmpJugador,oEscenario->getmatriz());
		oArrBombas->dibujar_una_bomba(g, bmpBomba, bmpExplosion, oJugador->getX(), oJugador->getY(), oEscenario->getmatriz());
	}


	Jugador* getoJugador() {
		return oJugador;
	}


private:
	Escenario *oEscenario;
	Jugador* oJugador;
	ArrBombas* oArrBombas;


};

