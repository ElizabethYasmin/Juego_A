#include "MyMenu.h"


using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void El(array<String^>^ args) {//Main se cambia en Proyecto->Propiedades Vjuego->Vinculador->Avanzadas->Punto de entrada(No debe ser igual que mi otro proyecto CLR)
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	//WinformCDemo is your project name
	Vjuego::MyMenu form;
	Application::Run(% form);
}
