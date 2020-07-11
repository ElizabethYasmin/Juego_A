#include "Jugad2.h"

using namespace System;
Jugad2::Jugad2()
{
	Random j;
	x = j.Next(100, 500);
	System::Threading::Thread::Sleep(10);
	y = j.Next(200, 500);//posicion del jugador 2 al inicio
	System::Threading::Thread::Sleep(10);
	dx = dy = 3;//velocidad a la que se va a mover el jugador 2
	fila = columna = 0;

}

Jugad2::~Jugad2()
{
}

void Jugad2::Mostrar(Graphics^ g, Bitmap^ img)
{
	alto = img->Height / 4;
	ancho = img->Width / 4;//por imagenes en la fila(Sprite dividido en 4x4)


	img->MakeTransparent(img->GetPixel(0,0));//imagen superior izquierda //desaparece el color del fondo de la imagen 


	Rectangle molde = Rectangle(columna * ancho, fila * alto, ancho, alto);

	g->DrawImage(img, x, y, molde, GraphicsUnit::Pixel);

	columna++;

	if (columna == 4)
		columna = 0;

}

void Jugad2::Mover(Direccion direccion, Graphics^ g)  // Movimiento del Personaje --> DIRECCIONES --->(arriba,abajo,izquierda,derecha)
{

	switch (direccion)
	{
	case Direccion::Arriba:
		if (y - dy > 0)
			y -= dy;
		fila = 3;
		break;
	case Direccion::Abajo:								// orientacion de movimiento basado en la velocidad de movimiento del objeto(imagen)
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