#include "Gato.h"
using namespace System;
Gato::Gato() {
	Random j;
	x = j.Next(100, 500);
	System::Threading::Thread::Sleep(10);
	y  = j.Next(200, 500);//posicion del gato al inicio
	System::Threading::Thread::Sleep(10);
	dx = dy = 2;//velocidad a la que se va a mover la paloma
	fila = columna = 0;


}

Gato::~Gato()
{
}

void Gato::Mostrar(Graphics^ g, Bitmap^ img)
{
	alto = img->Height / 4;
	ancho = img->Width / 3;//por imagenes en la fila

	Rectangle molde = Rectangle(columna * ancho, fila * alto, ancho, alto);



	g->DrawImage(img, x, y, molde, GraphicsUnit::Pixel);

	columna++;

	if (columna == 3)
		columna = 0;




}

void Gato::Mover(Direccion direccion, Graphics^ g)

{

	switch (direccion)
	{
	case Direccion::Arriba:
		if (y - dy > 0)
			y -= dy;
		fila = 3;
		break;
	case Direccion::Abajo:
		if (y + alto + dy < g->VisibleClipBounds.Bottom)
			y += dy;
		fila = 0;
		break;
	case Direccion::Izquierda:
		if (x - dx > 0)
			x -= dx;
		fila = 1;
		break;
	case Direccion::Derecha:
		if (x + ancho + dx < g->VisibleClipBounds.Right)
			x += dx;
		fila = 2;
		break;
	default:
		break;
	}
}