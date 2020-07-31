#pragma once
#include "Entidad.h"
class Gato :public Entidad
{

public:
	Gato();
	~Gato();
	void Mostrar(Graphics^ g, Bitmap^ img);
	void Mover(Direccion direccion, Graphics^ g);

};

