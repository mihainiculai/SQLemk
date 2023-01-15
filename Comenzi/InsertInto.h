#pragma once

class InsertInto : public Comanda {
	int nrColoane;
	vector<string> valoare;
public:
	void run(const vector<string>& camp, const int& nrCampuri) override {
		if (nrCampuri < 4)
			throw logic_error("Comanda invalida!");

		numeTabela = camp[2];
		nrColoane = gt.getNrColoane(numeTabela);

		if (camp[3] != "(")
			throw logic_error("Format invalid!");
		if (camp[nrCampuri - 1] != ")")
			throw logic_error("Format invalid!");
		if (4 + nrColoane*2 != nrCampuri)
			throw logic_error("Format invalid!");

		if (nrColoane > 0) {
			valoare.reserve(nrColoane);
			for (int i = 0; i < nrColoane; i++) {
				valoare.push_back(camp[4 + 2 * i]);
			}
			gt.adaugareInregistrare(numeTabela, valoare);
		}
		else {
			throw logic_error("Tabela fara coloane!");
		}
	}
};