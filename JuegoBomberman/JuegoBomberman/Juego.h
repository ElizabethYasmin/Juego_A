#pragma once
#include "Controladora.h"


namespace JuegoBomberman {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Juego
	/// </summary>
	public ref class Juego : public System::Windows::Forms::Form
	{
	

	private:
		Controladora* oControladora = new Controladora();
		Bitmap^ bmpSolido = gcnew Bitmap("MATERIALES\\bmpSolido.png");
		Bitmap^ bmpDestruible = gcnew Bitmap("MATERIALES\\bmpDestruible.png");
		Bitmap^ bmpSuelo = gcnew Bitmap("MATERIALES\\bmpSuelo.png");
		//declaramos nuestra variable de lo que es el juegador 
		Bitmap^ bmpJugador = gcnew Bitmap("MATERIALES\\Jugador.png");
		Bitmap^bmpBomba= gcnew Bitmap("MATERIALES\\bomba.png");
		Bitmap^ bmpExplosion= gcnew Bitmap("MATERIALES\\explosion.png");
		
	public:
		Juego(void)
		{
			
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//

			bmpJugador->MakeTransparent(bmpJugador->GetPixel(0, 0));
			bmpBomba->MakeTransparent(bmpBomba->GetPixel(0, 0));
			bmpExplosion->MakeTransparent(bmpExplosion->GetPixel(0, 0));
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Juego()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Juego::timer1_Tick);
			// 
			// Juego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 749);
			this->Name = L"Juego";
			this->Text = L"Juego";
			this->Load += gcnew System::EventHandler(this, &Juego::Juego_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Juego::Juego_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Juego::Juego_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion


	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);

		
		oControladora->dibujar(buffer->Graphics, bmpSuelo, bmpSolido, bmpBomba, bmpExplosion, bmpDestruible,bmpJugador);
		buffer->Render(g);
		delete buffer, espacio,g;
	}
	private: System::Void Juego_Load(System::Object^ sender, System::EventArgs^ e) {

		oControladora->CambiarNivel();


	}
	private: System::Void Juego_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::Up:
			oControladora->getoJugador()->setDireccion(Direcciones::Arriba);
			break;
		case Keys::Down:
			oControladora->getoJugador()->setDireccion(Direcciones::Abajo);
			break;
		case Keys::Left:
			oControladora->getoJugador()->setDireccion(Direcciones::Izquierda);
			break;
		case Keys::Right:
			oControladora->getoJugador()->setDireccion(Direcciones::Derecha);
			break;
		default:
			break;
		}
	}


	private: System::Void Juego_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	///ultima tecla presionada
		switch (e->KeyCode)
		{
		case Keys::Space:
			oControladora->agregarBomba();
			break;
		default:
			oControladora->getoJugador()->setDireccion(Direcciones::Ninguna);
			break;
		}
	
	}
	};
}
