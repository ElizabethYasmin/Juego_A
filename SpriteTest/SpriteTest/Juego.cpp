#include "Juego.h"


Juego::Juego()
{
	paloma = new Paloma();
	cant = 0;
	gatos = new Gato * [cant];


	AgregarGatos(10);
}

Juego::~Juego()
{
}

void Juego::Disparar()
{
	paloma->crearBala();
}

void Juego::MoverPaloma(Keys key, Graphics^ g)
{
	if (key == Keys::Up)
		paloma->Mover(Direccion::Arriba, g);
	else if (key == Keys::Down)
		paloma->Mover(Direccion::Abajo, g);
	else if (key == Keys::Left)
		paloma->Mover(Direccion::Izquierda, g);
	else if (key == Keys::Right)
		paloma->Mover(Direccion::Derecha, g);

}

void Juego::MostrarPaloma(Graphics^ g, Bitmap^ img)
{
	
	paloma->MostrarBalas(g);
	paloma->Mostrar(g, img);

	
}

void Juego::MoverGatos( Graphics^ g)
{
	for (int i = 0;i < cant;i++) {
		if (gatos[i]->GetX() > paloma->GetX())
			gatos[i]->Mover(Direccion::Izquierda, g);

		else if (gatos[i]->GetX() < paloma->GetX())
			gatos[i]->Mover(Direccion::Derecha, g);



		if (gatos[i]->GetY() > paloma->GetY())
			gatos[i]->Mover(Direccion::Arriba, g);

		else if (gatos[i]->GetY() < paloma->GetY())
			gatos[i]->Mover(Direccion::Abajo, g);
	}
}

void Juego::MostrarGatos(Graphics ^g, Bitmap ^img)
{
	for (int i = 0;i < cant;i++) {
		gatos[i]->Mostrar(g, img);
	}
	paloma->MoverBalas();
}

void Juego::AgregarGatos(int n)//agregando elementos a un arreglo 
{
	for (int m = 0;m < n;m++) {

		Gato** aux = new Gato * [cant + 1];

		for (int i = 0;i < cant;i++)
			aux[i] = gatos[i];

		aux[cant] = new Gato();

		gatos = aux;
		cant++;
	}
}


void Juego::EliminarGatos(int n)//agregando elementos a un arreglo 
{
	delete gatos[n];
	Gato** aux = new Gato * [cant - 1];
	
	//Elimino la direccion de memoria
	//-------------------------------
	for (int i = 0;i < n;i++) {
		aux[i] = gatos[i];

	}
	for (int i = n;i < cant - 1;i++) {
		aux[i] = gatos[i + 1];
	}
	
	//----------------------------------------
	cant--;
	gatos = aux;
	
}
void Juego::Coliciones()
{
	//Rectangle a = Rectangle(paloma->GetX(), paloma->GetY(), paloma->GetAlto(), paloma->GetAncho());
	Rectangle bala;
	Rectangle esqueleto;


	Bala* BALA;

	inicio:
	for (int b = 0;b < paloma->GetCantBalas();b++) {
		BALA = paloma->GetBala(b);
		bala= Rectangle(paloma->GetX(), paloma->GetY(), paloma->GetAlto(), paloma->GetAncho());


		for (int e = 0;e < cant;e++) {

		esqueleto = Rectangle(gatos[e]->GetX(), gatos[e]->GetY(), gatos[e]->GetAlto(), gatos[e]->GetAncho());

		if (bala.IntersectsWith(esqueleto)) {//si coliciona bala y esqueleto 

			//return true;


			/*timer1->Enabled = false;
			MessageBox::Show("Perdiste");
			this->Close();*/
			

			EliminarGatos(e);
			paloma->EliminarBala(b);
			goto inicio;


		}

		}
	}
	//return false;

}
