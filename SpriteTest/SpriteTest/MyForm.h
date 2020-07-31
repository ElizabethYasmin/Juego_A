#pragma once
#include "Juego.h"
//#include "Paloma.h"
//#include "Gato.h"
namespace SpriteTest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)//constructor del formulario
		{
			InitializeComponent();
			g = this->CreateGraphics();//componente grafico para dibujar (blanco)
			
			juego = new Juego();
									  
									   
		    //paloma = new Paloma();
			palomita = gcnew Bitmap("tanque.png");  //misma ruta del archivo//clase tipo administrado
			//gato = new Gato();
			gatito = gcnew Bitmap("calavera.png");
		}

	protected:
		~MyForm()//destructor del formulario
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	private://atributos del formulario

		Graphics ^g;//aqui vamos a dibujar todas nuestras imagenes  
	private: System::Windows::Forms::Timer^ timer1;
		  // Paloma *paloma;
		   Bitmap ^palomita;
		  // Gato *gato;
		   Bitmap ^gatito;


		   Juego* juego;


#pragma region Windows Form Designer generated code
	
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(819, 662);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			this->ResumeLayout(false);

		}
#pragma endregion//controles que se crearan 
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {//en la variable e se guarda la tecla presionada 
	//cuando precionamos
		juego->MoverPaloma(e->KeyCode, g);


		if (e->KeyCode == Keys::Space) {
			juego->Disparar();
		}
		/*if (e->KeyCode == Keys::Up)
			paloma->Mover(Direccion::Arriba,g);
		else if(e->KeyCode==Keys::Down)
			paloma->Mover(Direccion::Abajo,g);
		else if(e->KeyCode==Keys::Left)
			paloma->Mover(Direccion::Izquierda,g);
		else if(e->KeyCode==Keys::Right)
			paloma->Mover(Direccion::Derecha,g);*/
	
	}


	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		BufferedGraphicsContext^ bfc = BufferedGraphicsManager::Current;
		BufferedGraphics^ bf = bfc->Allocate(g, this->ClientRectangle);
		
		
		
		
		//g = this->CreateGraphics();
		
		//g->Clear(Color::LightBlue);
		bf->Graphics->Clear(Color::LightBlue);



		/*//paloma->Mostrar(g, palomita);
		paloma->Mostrar(bf->Graphics, palomita);
		gato->Mostrar(bf->Graphics, gatito);*/
		juego->MostrarGatos(bf->Graphics, gatito);//graficador + imagen 


		juego->MostrarPaloma(bf->Graphics,palomita);
		


		bf->Render(g);
		delete bf, bfc;

	
		/*if (gato->GetX() > paloma->GetX())
			gato->Mover(Direccion::Izquierda, g);
		
		else if (gato->GetX() < paloma->GetX())
			gato->Mover(Direccion::Derecha, g);



		if (gato->GetY() > paloma->GetY())
			gato->Mover(Direccion::Arriba, g);

		else if (gato->GetY() < paloma->GetY())
			gato->Mover(Direccion::Abajo, g);*/

		juego->MoverGatos(g);

		/*
		Rectangle a = Rectangle(paloma->GetX(),paloma->GetY(),paloma->GetAlto(),paloma->GetAncho());
		Rectangle b = Rectangle(gato->GetX(), gato->GetY(), gato->GetAlto(), gato->GetAncho());



		if (a.IntersectsWith(b)) {
			timer1->Enabled = false;
			MessageBox::Show("Perdiste");
			this->Close();
		}*/
		
		
		//if (juego->Coliciones())
		//	this->Close();


		juego->Coliciones();
	}
	private: System::Void MyForm_Resize(System::Object^ sender, System::EventArgs^ e) {
		g = this->CreateGraphics();
	}
	};
}
