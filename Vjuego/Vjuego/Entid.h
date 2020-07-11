#pragma once
//Esto es la primera clase que se creo 
using namespace System::Drawing;//Encapsula una superficie de dibujo GDI +. Esta clase no puede heredarse.


enum Direccion { Arriba, Abajo, Izquierda, Derecha };//enum para definir grupos de elementos comunes (conjuntos)
//  direccion donde se mueve el personaje

class Entid
{
	protected:
		int x, y;				// coordenadas de posición en pantalla 
		int dx, dy;				// velocidad en x y velocidad en y
		int ancho, alto;		// tamaño y ancho de las imagenes
		int fila, columna;
	public:
		Entid(); 
		~Entid();

		int GetX();
		int GetY();
		int GetDX();
		int GetDY();
		int GetAncho();
		int GetAlto();
		int GetFila();
		int GetColumna();


		void SetX(int n);
		void SetY(int n);
		void SetDX(int n);
		void SetDY(int n);
		void SetAncho(int n);
		void SetAlto(int n);
		void SetFila(int n);
		void SetColumna(int n);

		virtual void Mostrar(Graphics^ g, Bitmap^ img);
		virtual void Mover(Direccion direccion, Graphics^ g);
	//	virtual void Aumentar_velocidad();   
	};

