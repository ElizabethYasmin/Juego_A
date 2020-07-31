#include "Paloma.h"
using namespace System;


Paloma::Paloma()
{
	Random j;

	x = y = j.Next(10,40);
	dx = dy = 4;//velocidad a la que se va a mover la paloma
	fila = columna  = 0;
	cant = 0;
	direccion = Direccion::Abajo;  

}

Paloma::~Paloma()
{
}

void Paloma::crearBala()
{
	Bala** aux = new Bala * [cant + 1];

	for (int i = 0;i < cant;i++) {
		aux[i] = balas[i];
	}

	int dx=0, dy=0;

	switch (direccion) {
	case Direccion::Arriba:dy = -16;break;
	case Direccion::Abajo:dy = 16;break;
	case Direccion::Izquierda:dx = -16;break;
	case Direccion::Derecha:dx = 16;break;
	}



	aux[cant] = new Bala(x  + ancho /2 ,y + alto /2,dx,dy);

	cant++;
	balas = aux;
}

void Paloma::EliminarBala(int p)
{
	Bala** aux = new Bala * [cant - 1];
	delete balas[p];
	for (int i =0 ;i < p;i++) {
		aux[i] = balas[i];

	}
	for (int i = p;i < cant - 1;i++) {
		aux[i] = balas[i + 1];
	}
	cant--;
	balas = aux;
}

void Paloma::MostrarBalas(Graphics ^g)
{
	for (int i = 0;i < cant;i++) {
		balas[i]->Mostrar(g);
	}
}

void Paloma::MoverBalas()
{
	for (int i = 0;i < cant;i++) {
		balas[i]->Mover();
	}
}


int Paloma::GetCantBalas() {
	return cant;
}


Bala* Paloma::GetBala(int i)
{
	return balas[i];
}

void Paloma::Mostrar(Graphics ^g, Bitmap ^img)
{
	alto = img->Height / 4;
	ancho = img->Width / 4;//por imagenes en la fila


	img->MakeTransparent(img->GetPixel(0, 0));//imagen superior izquierda //desaparece el color del fondo de la imagen

	Rectangle molde = Rectangle(columna*ancho,fila*alto,ancho,alto);





	g->DrawImage(img, x, y, molde, GraphicsUnit::Pixel);

	columna++;

	if (columna == 3)
		columna = 0;




}

void Paloma::Mover(Direccion direccion, Graphics^ g)

{

	switch (direccion)
	{
	case Direccion::Arriba:
		if(y -dy>0)
			y -= dy;
		fila = 3;
		
		this->direccion = Direccion::Arriba;//cambia la direccon de la palaloma
		break;
	case Direccion::Abajo:
		if(y+alto+dy<g->VisibleClipBounds.Bottom)
			y += dy;
		fila = 0;

		this->direccion = Direccion::Abajo;
		break;
	case Direccion::Izquierda:
		if(x-dx>0)
			x -= dx;
		fila = 1;
		this->direccion = Direccion::Izquierda;
		break;
	case Direccion::Derecha:
		if (x + ancho + dx < g->VisibleClipBounds.Right)
			x += dx;
		fila = 2;

		this->direccion = Direccion::Derecha;
		break;
	default:
		break;
	}
}
