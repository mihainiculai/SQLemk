#pragma once

void importPreset(const string& numePreset) {
	ifstream fisierPreset;
	fisierPreset.open(mainPath + "Preseturi/" + numePreset + ".sql");
	if (fisierPreset.is_open()) {
		stopPrinting();
		string linie;
		while (getline(fisierPreset, linie)) {
			try {
				ic.rulare(linie);
			}
			catch (const exception& e) {
				cout << e.what();
			}
		}
		fisierPreset.close();
		startPrinting();
		cout << endl << "Presetul " << numePreset << " a fost importat cu succes!" << endl << endl;
		log("Presetul " + numePreset + " a fost importat");
	}
	else {
		cout << endl << "Fisierul presetului nu a putut fi deschis!" << endl << endl;
	}
	Sleep(2000);
}

void presets() {
	cout << "Alege un preset:" << endl;
	cout << "\t1. Baza de date pentru o firma" << endl;
	cout << "\t2. Baza de date pentru o scoala" << endl;
	cout << "\t3. Baza de date pentru o biblioteca" << endl;
	cout << "\t4. Baza de date pentru un magazin" << endl;
	cout << "\t5. Baza de date pentru un joc" << endl;
	cout << "\t0. Inapoi" << endl;
	string input;
	int optiune;
	while (true) {
		cout << endl;
		cout << "Alege o optiune: ";
		getline(cin, input);
		if (input.length() == 1) {
			optiune = input[0] - '0';
			if (optiune >= 0 && optiune <= 5) {
				break;
			}
		}
		cout << endl << "Optiune invalida!" << endl;
	}
	if (optiune != 0) {
		while (true) {
			cout << endl;
			cout << "Toate tabelele si datele existente vor fi sterse." << endl;
			cout << "Esti sigur ca vrei sa continui? (y/n): ";
			getline(cin, input);
			if (input.length() == 1) {
				if (input[0] == 'y' || input[0] == 'Y') {
					cout << endl;
					gt.stergereTabele();
					break;
				}
				else if (input[0] == 'n' || input[0] == 'N') {
					return;
				}
			}
			cout << endl << "Optiune invalida!" << endl;
		}
	}
	switch (optiune) {
	case 1:
		importPreset("Firma");
		break;
	case 2:
		importPreset("Scoala");
		break;
	case 3:
		importPreset("Biblioteca");
		break;
	case 4:
		importPreset("Magazin");
		break;
	case 5:
		importPreset("Joc");
		break;
	case 0:
		return;
	default:
		break;
	}
}