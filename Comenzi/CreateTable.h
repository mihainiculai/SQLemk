#pragma once

class CreateTable : public Comanda {
	int nrColoane = 0;
	vector<string> numeColoana;
	vector<string> tip;
	vector<int> dimensiune;
	vector<string> valoareImplicita;
public:
	void run(const vector<string>& camp, const int& nrCampuri) override {
		if (nrCampuri < 3)
			throw logic_error("Comanda invalida!");
		for (int i = 3; i < nrCampuri; i += 10) {
			if (i + 8 >= nrCampuri)
				throw logic_error("Format invalid!");
			if (camp[i] != "(")
				throw logic_error("Format invalid!");
			if (camp[i + 2] != ",")
				throw logic_error("Format invalid!");
			if (camp[i + 4] != ",")
				throw logic_error("Format invalid!");
			if (camp[i + 6] != ",")
				throw logic_error("Format invalid!");
			if (camp[i + 8] != ")")
				throw logic_error("Format invalid!");
			nrColoane++;
		}
		
		numeTabela = camp[2];
		
		if (nrColoane > 0) {			
			numeColoana.reserve(nrColoane);
			tip.reserve(nrColoane);
			dimensiune.reserve(nrColoane);
			valoareImplicita.reserve(nrColoane);
			
			for (int i = 0; i < nrColoane; i++) {
				numeColoana.push_back(camp[4 + i * 10]);
				tip.push_back(camp[6 + i * 10]);
				dimensiune.push_back(stoi(camp[8 + i * 10]));
				valoareImplicita.push_back(camp[10 + i * 10]);
			}
			
			gt.adaugareTabela(numeTabela, nrColoane, numeColoana, tip, dimensiune, valoareImplicita);
		}
		else {
			throw logic_error("Tabela nu are coloane!");
		}
	}
};