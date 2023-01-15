#pragma once

class Update : public Comanda {
	string numeColoana;
	string valoare;
	string whereNumeColoana;
	string whereValoare;
public:
	void run(const vector<string>& camp, const int& nrCampuri) override {
		if (nrCampuri != 10)
			throw logic_error("Format invalid!");
		if (camp[2] != "SET")
			throw logic_error("Format invalid!");
		if (camp[4] != "=")
			throw logic_error("Format invalid!");
		if (camp[6] != "WHERE")
			throw logic_error("Format invalid!");
		if (camp[8] != "=")
			throw logic_error("Format invalid!");

		numeTabela = camp[1];
		numeColoana = camp[3];
		valoare = camp[5];
		whereNumeColoana = camp[7];
		whereValoare = camp[9];

		gt.actualizareInregistrari(numeTabela, numeColoana, valoare, whereNumeColoana, whereValoare);
	}
};