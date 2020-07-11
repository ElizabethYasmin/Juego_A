#pragma once
#include "Entid.h"
class Jugad2 :public Entid
{
public:
    Jugad2();
    ~Jugad2();

    void Mostrar(Graphics^ g, Bitmap^ img);
    void Mover(Direccion direccion, Graphics^ g);
};

