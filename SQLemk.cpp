#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <windows.h>
#include <string>
#include <vector>
#include <set>
#include <exception>

using namespace std;

#include "config.h"
#include "Source/Mesaje.h"
#include "Source/Gestionar fisiere.h"
#include "Source/Gestionar tabele.h"
#include "Comenzi/Comanda.h"
#include "Comenzi/CreateTable.h"
#include "Comenzi/DropTable.h"
#include "Comenzi/DisplayTable.h"
#include "Comenzi/InsertInto.h"
#include "Comenzi/DeleteFrom.h"
#include "Comenzi/Select.h"
#include "Comenzi/Update.h"
#include "Comenzi/Help.h"
#include "Comenzi/Export.h"
#include "Comenzi/Import.h"
#include "Source/Interpretator comenzi.h"
#include "Source/Logger.h"
#include "Source/Preprocessor.h"
#include "Source/Preseturi.h"

int Tabela::index = 1;
int GestionareTabele::nrTabele = 0;
GestionareTabele gt;
ListaFisiere lf;
InterpretatorComanda ic;
string comanda;

int main(int argc, char* argv[]) {
	clear();
	welcomeMessage();
	importTabele();
	executeScripts(argc-1, argv);
	
	while (true) {
		getline(cin, comanda);
		
		if (comanda.length() > 0)
			log("Executed from console: " + comanda);
		
		if (comanda == "PRESETS") {
			presets();
			clear();
			continue;
		}
		
		try {
			ic.rulare(comanda);
		}
		catch (const exception& e) {
			cout << e.what() << endl << endl;
			log("Error: " + string(e.what()));
		}
	}
}

