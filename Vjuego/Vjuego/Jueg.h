#pragma once

#include "Jugad1.h"
#include "Jugad2.h"
using namespace System::Windows::Forms;
class Jueg
{
	private:

		Jugad1* ju1;//crear memoria para almacer mi imagen -->mapa de bitmap 
		Jugad2* ju2;

	public:
		Jueg();
		~Jueg();
		
		
		void MoverJugador1(Keys key, Graphics^ g);
		void MostrarJugador1(Graphics^ g, Bitmap^ img);


		void MoverJugador2(Keys key, Graphics^ g);
		void MostrarJugador2(Graphics^ g, Bitmap^ img);
		//void 
		//bool Coliciones();
};

