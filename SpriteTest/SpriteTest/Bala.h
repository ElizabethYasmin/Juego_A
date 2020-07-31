#pragma once
#include "Entidad.h"
class Bala :public Entidad
{
public:
	Bala(int x, int y,int dx,int dy);
	~Bala();


	void Mostrar(Graphics^ g);
	void Mover();

};

