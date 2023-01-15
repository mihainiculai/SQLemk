#pragma once

void importTabele() {
	if (autoSave) {
		cout << "Se importa tabelele din fisierele de configurare..." << endl;
		lf.import();
		gt.importStructura(lf.getNrFisiere(), lf.getFisiere());
		cout << "Importarea s-a realizat cu succes!" << endl << endl;

		Sleep(1000);
		clear();
	}
}
void executeScripts(int n, char* fisiere[]) {
	for (int i = 1; i <= n; i++) {
		string numeFisier(fisiere[i]);
		if (numeFisier.substr(numeFisier.length() - 4, 4) == ".sql") {
			ifstream f(mainPath + fisiere[i]);
			if (f.is_open()) {
				if (!showScripts)
					stopPrinting();
				string comanda;
				while (getline(f, comanda)) {
					try {
						cout << comanda << endl;
						ic.rulare(comanda);
						log("Executed from script: " + comanda);
					}
					catch (const exception& e) {
						cout << e.what() << endl << endl;
						log("Error: " + string(e.what()));
					}
				}
				f.close();
				if (!showScripts)
					startPrinting();
				cout << "Scriptul " << numeFisier << " a fost executat cu succes.";
			}
			else {
				cout << "Fisierul " << fisiere[i] << " introdus ca argument nu a putut fi deschis!";
			}
		}
		else {
			cout << "Fisierul " << numeFisier << " nu are extensia .sql !";
		}
	}
	Sleep(2000);
	clear();
}