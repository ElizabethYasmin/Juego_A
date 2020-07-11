#pragma once
#include "Entid.h"
class Jugad1 :public Entid
{
public:
	Jugad1();
	~Jugad1();
	void Mostrar(Graphics^ g, Bitmap^ img);
	void Mover(Direccion direccion, Graphics^ g);
};

