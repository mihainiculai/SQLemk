#pragma once

class Import : public Comanda {
	string numeFisier;
public:
	void run(const vector<string>& camp, const int& nrCampuri) override {
		if (nrCampuri != 3)
			throw logic_error("Format invalid!");
		if (camp[2].find(".csv") == string::npos)
			throw logic_error("Format invalid!");
		
		numeTabela = camp[1];
		numeFisier = camp[2];

		gt.importInregistrari(numeTabela, numeFisier);
	}
};