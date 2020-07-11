#pragma once
#include "Entid.h"

using namespace System::Drawing;
// ahora le agrego mas ,
enum Directions(ar);

class Enemigo : public Entid{
	private:
		int x;
		int y;
		int dx;
		int dy;
		int ancho;
		int alto;
		int indiceX;
		int indiceY;
		// Clase enemigo(compatible con jugador)
	public:
		Enemigo();
		~Enemigo();
		Enemigo(int x, int y);
		
		enum Direcciones direccion;

		void dibujar(BufferedGraphics^ buffer, Bitmap^ bmp);
		void mover(BufferedGraphics^ buffer, Bitmap^ bmp);
};

