#pragma once

class DisplayTable : public Comanda {
public:
	void run(const vector<string>& camp, const int& nrCampuri) override {
		if (nrCampuri != 3)
			throw logic_error("Comanda invalida!");
		numeTabela = camp[2];
		if (camp[2] == "*")
			gt.displayTabele();
		else
			gt.displayTabela(numeTabela);
	}
};