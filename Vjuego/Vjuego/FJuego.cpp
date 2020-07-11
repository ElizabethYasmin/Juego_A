#include "FJuego.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Eli(array<String^>^ args) {//Main se cambia en Proyecto->Propiedades Vjuego->Vinculador->Avanzadas->Punto de entrada(No debe ser igual que mi otro proyecto CLR)
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	//WinformCDemo is your project name
	Vjuego::FJuego form;
	Application::Run(% form);
}


//  GDI -- > Graphics Device Interface ---- /  diseño de lineas figuras y formas , relleno de objeto 
// win32  --- > Api de Windows --  > permite obtener de forma directa	los servicios del SO  Windows










