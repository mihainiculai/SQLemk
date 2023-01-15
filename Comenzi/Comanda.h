#pragma once

class Comanda {
protected:
	string numeTabela;
public:
	virtual void run(const vector<string>& camp, const int& nrCampuri) = 0;
};