#pragma once

class Select : public Comanda {
	vector<string> numeColoana;
	string whereNumeColoana;
	string valoare;
	int nrColoane = 0;
	bool FROM = false;
	bool WHERE = false;
public:
	void run(const vector<string>& camp, const int& nrCampuri) override {
		for (int i = 1; i < nrCampuri; i++) {
			if (camp[i] == "FROM") {
				FROM = true;
				if (i == nrCampuri - 2)
					numeTabela = camp[i + 1];
				else if (i == nrCampuri - 6) {
					numeTabela = camp[i + 1];
					if (camp[i + 2] == "WHERE") {
						WHERE = true;
						whereNumeColoana = camp[i + 3];
						valoare = camp[i + 5];
					}
					else {
						throw logic_error("Format invalid!");
					}
				}
				else {
					throw logic_error("Format invalid!");
				}
				break;
			}
			if (camp[i] != ",") nrColoane++;
		}

		if (!FROM)
			throw logic_error("Format invalid!");

		if (nrColoane > 0 && camp[1] != "*") {
			for (int i = 0; i < nrColoane; i++) {
				numeColoana.push_back(camp[1 + i * 2]);
			}
			if (!WHERE)
				gt.afisareInregistrari(numeTabela, nrColoane, numeColoana);
			else
				gt.afisareInregistrariWHERE(numeTabela, nrColoane, numeColoana, whereNumeColoana, valoare);
		}
		else if (nrColoane == 1 && camp[1] == "*" && whereNumeColoana.empty()) {
			gt.afisareInregistrariALL(numeTabela);
		}
		else if (nrColoane == 1 && camp[1] == "*" && !whereNumeColoana.empty()) {
			gt.afisareInregistrariWHEREALL(numeTabela, whereNumeColoana, valoare);
		}
		else {
			throw logic_error("Format invalid!");
		}
	}
};