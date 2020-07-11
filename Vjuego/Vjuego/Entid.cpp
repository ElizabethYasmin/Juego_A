#include "Entid.h"

Entid::Entid() {
}
Entid::~Entid() {

}									// las variables fila , columna nos sirven para hallar/establecer la posicion de nuestro objeto 

int Entid::GetX() {
	return x;
}
int Entid::GetY() {	
	return y;
}
int Entid::GetDX() {
	return dx;
}
int Entid::GetDY() {
	return dy;
}
int Entid::GetAncho() {
	return ancho;
}
int Entid::GetAlto() {
	return alto;
}
int Entid::GetFila() {
	return fila;
}
int Entid::GetColumna() {
	return columna;
}

void Entid::SetX(int n) {
	x = n;
}
void Entid::SetY(int n) {
	y = n;
}
void Entid::SetDX(int n) {
	dx = n;
}
void Entid::SetDY(int n) {
	dy = n;
}
void Entid::SetAncho(int n) {
	ancho = n;
}
void Entid::SetAlto(int n) {
	alto = n;
}
void Entid::SetFila(int n) {
	fila = n;
}
void Entid::SetColumna(int n) {
	columna = n;
}




void Entid::Mostrar(Graphics^ g, Bitmap^ img)   // mostrar .. tenemos un puntero a Graphics ,   Bitmap .... mapa de bits para la creacion de imagen(visualización)
{
	// rellenar conforme al tiempo
}
void Entid::Mover(Direccion direccion, Graphics^ g)
{
	// rellenar conforme al tiempo
}
