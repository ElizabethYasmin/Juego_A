#include "Jueg.h"


Jueg::Jueg()
{
	//creacion de un nuevo jugador reservacion
	ju1 = new Jugad1();

	ju2 = new Jugad2();

}

Jueg::~Jueg()
{
}

void Jueg::MoverJugador1(Keys key, Graphics^ g) 
{
	if (key == Keys::W)
		ju1->Mover(Direccion::Arriba, g);
	else if (key == Keys::S)
		ju1->Mover(Direccion::Abajo, g);
	else if (key == Keys::A)
		ju1->Mover(Direccion::Izquierda, g);
	else if (key == Keys::D)
		ju1->Mover(Direccion::Derecha, g);

}



//----------------------------------------------------------------

void Jueg::MostrarJugador1(Graphics^ g, Bitmap^ img)
{
	ju1->Mostrar(g, img);
}

void Jueg::MoverJugador2(Keys key, Graphics^ g)
{
	if (key == Keys::Up)
		ju2->Mover(Direccion::Arriba, g);
	else if (key == Keys::Down)
		ju2->Mover(Direccion::Abajo, g);
	else if (key == Keys::Left)
		ju2->Mover(Direccion::Izquierda, g);
	else if (key == Keys::Right)
		ju2->Mover(Direccion::Derecha, g);

}

void Jueg::MostrarJugador2(Graphics^ g, Bitmap^ img)
{
	ju2->Mostrar(g, img);
}


