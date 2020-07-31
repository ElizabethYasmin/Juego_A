

#include <stdlib.h>
#include <ctime>

using namespace System::Drawing;

class Mejora
{
public:
	Mejora() {
		srand(time(NULL));
		tipo_de_mejora = rand() % 5 + 1;//4 mejoras
		ubicado = false;

		i = rand() % 13 + 1;//desde 1 hasta 13
		j = rand() % 15 + 1;

		ancho = 128 / 8;
		alto = 96 / 6;

		indiceX = 0;
		indiceY = 0;
	}
	~Mejora();



	void dibujar(Graphics^ g, Bitmap^ bmpMejoras, int** matriz) {
		Rectangle porcionAUsar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);

		while (ubicado == false) {
			if (matriz[i][j] == 3) {
				ubicado = true;
			}
			else {
				if (j < 17) {
					i++;
					if (i == 14) { i = 0; j++; }
				}
			}
		}
		Rectangle aumento = Rectangle(j * 50, i * 50, ancho * 3.125, alto * 3.125);
		g->DrawImage(bmpMejoras, aumento, porcionAUsar, GraphicsUnit::Pixel);

	}

	void animar() {
		switch (tipo_de_mejora)
		{
		case 1://bomba adicional
			indiceX = 0;
			if (indiceY >= 0 && indiceY < 1)
				indiceY++;
			else
				indiceY = 0;
			break;
		case 2://mover bomba
			indiceX = 4;
			if (indiceY >= 0 && indiceY < 1)
				indiceY++;
			else
				indiceY = 0;
			break;
		case 3://calavera
			indiceX = 5;
			if (indiceY >= 0 && indiceY < 1)
				indiceY++;
			else
				indiceY = 0;
			break;
		case 4://patines
			indiceX = 8;
			if (indiceY >= 0 && indiceY < 1)
				indiceY++;
			else
				indiceY = 0;
			break;
		case 5://vidas
			indiceX = 9;
			if (indiceY >= 0 && indiceY < 1)
				indiceY++;
			else
				indiceY = 0;
			break;
		}
	}

private:
	int i;
	int j;
	int indiceX;
	int indiceY;

	int ancho;
	int alto;

	int tipo_de_mejora;

	bool ubicado;
};

