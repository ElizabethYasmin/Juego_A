
#include"Mejora.h"
#include <vector>
using namespace std;


class ArrMejoras
{
public:
	ArrMejoras();
	~ArrMejoras();

	void crearMejoras() {
		Mejora* nueva_mejora = new Mejora();
		vector_mejoras.push_back(nueva_mejora);
	}
	void dibujar(Graphics^ g, Bitmap^ bmpMejoras, int** matriz) {
		for (int i = 0 ; i < vector_mejoras.size();i++) {
			vector_mejoras.at(i)->dibujar(g, bmpMejoras, matriz);
			vector_mejoras.at(i)->animar();
		}
	}
private:
	vector<Mejora*>vector_mejoras;

};

