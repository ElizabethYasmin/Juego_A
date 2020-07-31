#include "Bala.h"

Bala::Bala(int x,int y,int dx,int dy)//el x que se pasa por parametro y el x que es atributo de bala que hereda de identidad 
{//iniciamos posicion y direccion
	this->x = x;//x heredada=x psada por parametro
	this->y = y;
	this->dx = dx;
	this ->dy = dy;


	ancho = alto = 10;//no filas y columnas por que usaremos primitivas

}

Bala::~Bala()
{
}

void Bala::Mostrar(Graphics^ g){

	//Draw solo dibuja el contorno
	//Fill un circulo completo, lleno
	//Brush^ br = gcnew SolidBrush(Color::Black);
	g->FillEllipse(Brushes::Black,x,y,ancho,alto);

}

void Bala::Mover()
{//en funcion a donde se encuentra la cara a donde mira

	x += dx;
	y += dy;
}
