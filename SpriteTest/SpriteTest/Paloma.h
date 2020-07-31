#pragma once
#include "Entidad.h"
#include "Bala.h"
using namespace System::Drawing;//se encuentra todo lo grafico
class Paloma : public Entidad
{
private :
    Direccion direccion;
    Bala** balas;
    int cant;

public:
    Paloma();
    ~Paloma();


    void crearBala();
    void EliminarBala(int p);
    void MostrarBalas(Graphics^g);
    void MoverBalas();

    int GetCantBalas();
    Bala* GetBala(int i);

    void Mostrar(Graphics ^g,Bitmap ^img);
    void Mover(Direccion direccion, Graphics^ g);

};

