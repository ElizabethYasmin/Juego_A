#include "Jugad1.h"

using namespace System;
Jugad1::Jugad1()
{
	Random j;

	x = y = j.Next(10, 40);
	dx = dy = 4;//velocidad de movimiento del objeto Paloma(¿a que velocidad se esta moviendo la paloma?)
	fila = columna = 0;
}

Jugad1::~Jugad1()
{
}

void Jugad1::Mostrar(Graphics^ g, Bitmap^ img)
{
	alto = img->Height / 4;
	ancho = img->Width / 4;//por imagenes en la fila

	Rectangle molde = Rectangle(columna * ancho, fila * alto, ancho, alto);

	g->DrawImage(img, x, y, molde, GraphicsUnit::Pixel);

	columna++;

	if (columna == 4)
		columna = 0;
}

void Jugad1::Mover(Direccion direccion, Graphics^ g)
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
	//case Direccion::	

	//default:
		//break;
	}
}