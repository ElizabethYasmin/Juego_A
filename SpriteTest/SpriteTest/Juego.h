#pragma once
#include "Paloma.h"
#include "Gato.h"
using namespace System::Windows::Forms;
class Juego
{
private:
	Paloma* paloma;
	Gato** gatos;
	int cant;


public:
	Juego();
	~Juego();

	void Disparar();


	void MoverPaloma(Keys key,Graphics ^g);
	void MostrarPaloma(Graphics ^g,Bitmap ^img);

	void MoverGatos( Graphics^ g);
	void MostrarGatos(Graphics ^g, Bitmap ^img);

	void AgregarGatos(int n);

	void EliminarGatos(int n);

	void Coliciones();
};

