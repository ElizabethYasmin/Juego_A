#include "Entidad.h"
Entidad::Entidad() {
}
Entidad::~Entidad() {

}


int Entidad::GetX() {
	return x;
}
int Entidad::GetY() {
	return y;
}
int Entidad::GetDX() {
	return dx;
}
int Entidad::GetDY() {
	return dy;
}
int Entidad::GetAncho() {
	return ancho;
}
int Entidad::GetAlto() {
	return alto;
}
int Entidad::GetFila() {
	return fila;
}
int Entidad::GetColumna() {
	return columna;
}


void Entidad::SetX(int n) {
	x = n;
}
void Entidad::SetY(int n) {
	y = n;
}
void Entidad::SetDX(int n) {
	dx = n;
}
void Entidad::SetDY(int n) {
	dy = n;
}
void Entidad::SetAncho(int n) {
	ancho = n;
}
void Entidad::SetAlto(int n) {
	alto = n;
}
void Entidad::SetFila(int n) {
	fila = n;
}
void Entidad::SetColumna(int n) {
	columna = n;
}




void Entidad::Mostrar(Graphics^ g, Bitmap^ img)
{
}
void Entidad::Mover(Direccion direccion, Graphics^ g)
{
}
