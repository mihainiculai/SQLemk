#pragma once

class DeleteFrom : public Comanda {
	string numeColoana;
	string valoare;
public:
	void run(const vector<string>& camp, const int& nrCampuri) override {
		if (nrCampuri == 3) {
			gt.stergereInregistrari(camp[2]);
			return;
		}
		if (nrCampuri != 7)
			throw logic_error("Format invalid!");
		if (camp[3] != "WHERE")
			throw logic_error("Format invalid!");
		if (camp[5] != "=")
			throw logic_error("Format invalid!");
		
		numeTabela = camp[2];
		numeColoana = camp[4];
		valoare = camp[6];
		
		gt.stergereInregistrare(numeTabela, numeColoana, valoare);
	
	}
};