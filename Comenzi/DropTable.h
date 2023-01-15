#pragma once

class DropTable : public Comanda {
public:
	void run(const vector<string>& camp, const int& nrCampuri) override {
		if (nrCampuri != 3)
			throw logic_error("Comanda invalida!");
		numeTabela = camp[2];
		if (numeTabela == "*")
			gt.stergereTabele();
		else
			gt.stergereTabela(numeTabela);
	}
};