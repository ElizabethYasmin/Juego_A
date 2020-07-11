#pragma once
#include "Jueg.h"
namespace Vjuego {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class FJuego : public System::Windows::Forms::Form
	{
	public:
		FJuego(void)
		{
			InitializeComponent();

			g = this->CreateGraphics();//componente grafico para dibujar (blanco)

			juego = new Jueg();

			pika = gcnew Bitmap("pika.png");  //misma ruta del archivo//clase tipo administrado

			otro = gcnew Bitmap("pok.png");
			
		}

	protected:
		~FJuego()
		{
			if (components)
			{
				delete components;
			}
		}
	
	
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:

		Graphics^ g;

	private: System::Windows::Forms::Timer^ timer1;

		   Bitmap^ pika;

		   Bitmap^ otro;


		   Jueg* juego;


	

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
			this->timer1->Tick += gcnew System::EventHandler(this, &FJuego::timer1_Tick);
			// 
			// FJuego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(610, 548);
			this->Name = L"FJuego";
			this->Text = L"FJuego";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FJuego::FJuego_KeyDown);
			this->Resize += gcnew System::EventHandler(this, &FJuego::FJuego_Resize);
			this->ResumeLayout(false);
		}
#pragma endregion
	private: System::Void FJuego_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		
		juego->MoverJugador1(e->KeyCode, g);
		

		juego->MoverJugador2(e->KeyCode, g);
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//---------------------------------------------------------------------------
		BufferedGraphicsContext^ bfc = BufferedGraphicsManager::Current;
		BufferedGraphics^ bf = bfc->Allocate(g, this->ClientRectangle);
		//***************************************************************************
		bf->Graphics->Clear(Color::LightBlue);


		juego->MostrarJugador1(bf->Graphics, pika);
		juego->MostrarJugador2(bf->Graphics, otro);//graficador + imagen 


		bf->Render(g);
		delete bf, bfc;


		//juego->MoverGatos(g);
/*
		if (juego->Coliciones())
			this->Close();*/


	
	}
	private: System::Void FJuego_Resize(System::Object^ sender, System::EventArgs^ e) {
		g = this->CreateGraphics();
	}
	
	};
}
