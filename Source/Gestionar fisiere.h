#pragma once

class Fisiere {
	string numeTabela;
public:
	Fisiere(const string& numeTabela) {
		this->numeTabela = numeTabela;
	}
	Fisiere(const Fisiere& f) {
		this->numeTabela = f.numeTabela;
	}

	string getNumeTabela() const {
		return numeTabela;
	}

	friend bool operator < (const Fisiere& f1, const Fisiere& f2) {
		return f1.numeTabela < f2.numeTabela;
	}
	operator string() {
		return numeTabela;
	}

	Fisiere& operator=(const Fisiere& f) {
		this->numeTabela = f.numeTabela;
		return *this;
	}
};

class ListaFisiere {
	int nrFisiere = 0;
	set<Fisiere> fisiere;
public:
	int getNrFisiere() const {
		return nrFisiere;
	}
	vector<string> getFisiere() {
		vector<string> aux;
		int i = 0;
		for (auto it = fisiere.begin(); it != fisiere.end(); it++) {
			aux.push_back(it->getNumeTabela());
			i++;
		}
		return aux;
	}

	void import() {
		ifstream f(autoSaveFolder + autoSaveFile);
		string numeTabela;

		while (f >> numeTabela) {
			Fisiere f(numeTabela);

			ifstream test(autoSaveFolder + numeTabela + ".bin", ios::binary);
			if (test.good()) {
				fisiere.insert(f);
				nrFisiere++;
			}
		}
		f.close();
		update();
	}
	void update() {
		ofstream f(autoSaveFolder + autoSaveFile);
		set<Fisiere>::iterator it;
		for (it = fisiere.begin(); it != fisiere.end(); it++) {
			f << it->getNumeTabela() << endl;
		}
		f.close();
	}
	void adaugareFisier(const string& numeTabela) {
		Fisiere f(numeTabela);
		fisiere.insert(f);
		nrFisiere++;
		update();
	}
	void deleteFisier(const string& numeTabela) {
		for (auto it = fisiere.begin(); it != fisiere.end(); it++) {
			if (it->getNumeTabela() == numeTabela) {
				fisiere.erase(it);
				nrFisiere--;
				remove((autoSaveFolder + numeTabela + ".bin").c_str());
				break;
			}
		}
		update();
	}
};

extern ListaFisiere lf;