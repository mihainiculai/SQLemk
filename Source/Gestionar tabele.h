#pragma once

// Clasa de tabela
class Tabela {
private:
	const int id;

	enum tipColoana { INT, CHAR, FLOAT };

	string nume = "Tabela noua";
	int nrColoane = 0;
	vector<string> numeColoana;
	vector<tipColoana> tip;
	vector<int> dimensiune;
	vector<string> valoareImplicita;

	int nrInregistrari = 0;
	vector<vector<string>> inregistrari;

	static int index;
public:
	//Constructori
	Tabela() :id(index) {
		index++;
	}
	Tabela(const string& nume, int nrColoane, vector<string> numeColoana, vector<string> tip, vector<int> dimensiune, vector<string> valoareImplicita) :id(index) {
		this->nume = nume;
		this->nrColoane = nrColoane;

		for (int i = 0; i < nrColoane; i++) {
			this->numeColoana.push_back(numeColoana[i]);

			if (tip[i] == "INT") this->tip.push_back(INT);
			else if (tip[i] == "CHAR") this->tip.push_back(CHAR);
			else if (tip[i] == "FLOAT") this->tip.push_back(FLOAT);
			else throw invalid_argument("Tipul unei coloane nu este valid!");

			if (dimensiune[i] > 0 && dimensiune[i] < 256)
				this->dimensiune.push_back(dimensiune[i]);
			else throw length_error("Dimensiunea unei coloane nu este valida!");

			this->valoareImplicita.push_back(valoareImplicita[i]);
		}
		cout << "Tabela " << nume << " a fost creata cu succes!" << endl;
		index++;
	}
	Tabela(const Tabela& t) :id(t.id) {
		this->nume = t.nume;
		this->nrColoane = t.nrColoane;

		for (int i = 0; i < t.nrColoane; i++) {
			this->numeColoana.push_back(t.numeColoana[i]);
			this->tip.push_back(t.tip[i]);
			this->dimensiune.push_back(t.dimensiune[i]);
			this->valoareImplicita.push_back(t.valoareImplicita[i]);
		}

		this->nrInregistrari = t.nrInregistrari;
		for (int i = 0; i < t.nrInregistrari; i++) {
			vector<string> inregistrare;
			for (int j = 0; j < t.nrColoane; j++) {
				inregistrare.push_back(t.inregistrari[i][j]);
			}
			this->inregistrari.push_back(inregistrare);
		}
		index++;
	}
	//Destructor
	~Tabela() {
		index--;
	}

	//Geters
	[[nodiscard]] string getNume() const {
		return this->nume;
	}
	int getNrColoane() const {
		return this->nrColoane;
	}

	//Copiere
	Tabela& operator=(const Tabela& t) {
		if (this != &t) {
			this->nume = t.nume;
			this->nrColoane = t.nrColoane;

			for (int i = 0; i < t.nrColoane; i++) {
				this->numeColoana.push_back(t.numeColoana[i]);
				this->tip.push_back(t.tip[i]);
				this->dimensiune.push_back(t.dimensiune[i]);
				this->valoareImplicita.push_back(t.valoareImplicita[i]);
			}

			this->nrInregistrari = t.nrInregistrari;
			for (int i = 0; i < t.nrInregistrari; i++) {
				vector<string> inregistrare;
				for (int j = 0; j < t.nrColoane; j++) {
					inregistrare.push_back(t.inregistrari[i][j]);
				}
				this->inregistrari.push_back(inregistrare);
			}
		}
		return *this;
	}

	//DISPLAY TABLE
	friend ostream& operator<<(ostream& out, Tabela& t) {
		size_t lungimeS, lungimeR;
		if (t.nume.length() % 2 == 0) {
			lungimeS = 28 - t.nume.length() / 2;
			lungimeR = 28 - t.nume.length() / 2;
		}
		else {
			lungimeS = 28 - t.nume.length() / 2;
			lungimeR = 27 - t.nume.length() / 2;
		}

		for (int i = 0; i < lungimeS; i++)
			out << "=";
		out << "[ " << t.nume << " ]";
		for (int i = 0; i < lungimeR; i++)
			out << "=";

		out << endl;
		out << "ID: " << t.id << endl;
		out << "Nr coloane: " << t.nrColoane << endl << endl;
		for (int i = 0; i < t.nrColoane; i++) {
			out << "Nume coloana: " << t.numeColoana[i] << endl;
			out << "Tip coloana: ";
			if (t.tip[i] == INT) {
				out << "INT" << endl;
			}
			else if (t.tip[i] == CHAR) {
				out << "CHAR" << endl;
			}
			else if (t.tip[i] == FLOAT) {
				out << "FLOAT" << endl;
			}
			out << "Dimensiune coloana: " << t.dimensiune[i] << endl;
			out << "Valoare implicita coloana: " << t.valoareImplicita[i] << endl;
			out << endl;
		}
		out << "Nr inregistrari: " << t.nrInregistrari << endl << endl;
		out << "============================================================" << endl;
		return out;
	}

	//INSERT INTO
	void adaugareInregistrare(const vector<string>& valori) {
		for (int i = 0; i < this->nrColoane; i++) {
			if (this->tip[i] == INT) {
				if (valori[i].find_first_not_of("0123456789-") != string::npos) {
					throw invalid_argument("O valoarea nu este de tipul specificat!");
				}
			}
			if (this->tip[i] == FLOAT) {
				if (valori[i].find_first_not_of("0123456789.-") != string::npos) {
					throw invalid_argument("O valoarea nu este de tipul specificat!");
				}
			}
			if (valori[i].length() > this->dimensiune[i]) {
				throw length_error("O valoare are dimensiunea mai mare decat cea specificata!");
			}
		}

		vector<string> inregistrare;
		for (int i = 0; i < this->nrColoane; i++) {
			inregistrare.push_back(valori[i]);
		}
		this->inregistrari.push_back(inregistrare);

		this->nrInregistrari++;
	}

	//DELETE FROM
	void stergereInregistrare(const string& numeColoana, const string& valoare) {
		int indexColoana = -1;
		for (int i = 0; i < this->nrColoane; i++) {
			if (this->numeColoana[i] == numeColoana) {
				indexColoana = i;
				break;
			}
		}
		if (indexColoana == -1) {
			throw invalid_argument("Coloana introdusa nu exista!");
		}
		int inregistrariSterse = 0;
		for (int i = 0; i < this->nrInregistrari; i++) {
			if (this->inregistrari[i][indexColoana] == valoare) {
				this->inregistrari.erase(this->inregistrari.begin() + i);
				nrInregistrari--;
				inregistrariSterse++;
				i--;
			}
		}

		if (inregistrariSterse == 0)
			cout << "Nu a fost stearsa nicio inregistrare!" << endl;
		else if (inregistrariSterse == 1)
			cout << "A fost steara o inregistrare!" << endl;
		else
			cout << "Au fost sterse " << inregistrariSterse << " inregistrari!" << endl;
	}
	void stergereInregistrari() {
		this->nrInregistrari = 0;
		this->inregistrari.clear();
		cout << "Toate inregistrarile au fost sterse cu succes!" << endl;
	}

	//SELECT
	void afisareInregistrari(const int& nrColoane, const vector<string>& numeColoane) const {
		vector<int> indexColoane(nrColoane);
		for (int i = 0; i < nrColoane; i++) {
			indexColoane[i] = -1;
			for (int j = 0; j < this->nrColoane; j++) {
				if (this->numeColoana[j] == numeColoane[i]) {
					indexColoane[i] = j;
					break;
				}
			}
			if (indexColoane[i] == -1) {
				throw invalid_argument("O coloana nu exista!");
			}
		}

		vector<int> dimensiuneColoane(nrColoane);
		for (int i = 0; i < nrColoane; i++) {
			dimensiuneColoane[i] = (int)this->numeColoana[indexColoane[i]].length();
		}
		for (int i = 0; i < this->nrInregistrari; i++) {
			for (int j = 0; j < nrColoane; j++) {
				if (this->inregistrari[i][indexColoane[j]].length() > dimensiuneColoane[j]) {
					dimensiuneColoane[j] = (int)this->inregistrari[i][indexColoane[j]].length();
				}
			}
		}
		for (int i = 0; i < nrColoane; i++) {
			dimensiuneColoane[i]++;
		}
		cout << "=";
		for (int i = 0; i < nrColoane; i++) {
			cout << left << setw(dimensiuneColoane[i]) << setfill('=') << "" << "==";
		}
		cout << endl;
		cout << "| ";
		for (int i = 0; i < nrColoane; i++) {
			cout << left << setw(dimensiuneColoane[i]) << setfill(' ') << numeColoana[indexColoane[i]] << "| ";
		}
		cout << endl;
		cout << "=";
		for (int i = 0; i < nrColoane; i++) {
			cout << left << setw(dimensiuneColoane[i]) << setfill('=') << "" << "==";
		}
		cout << endl;

		for (int i = 0; i < this->nrInregistrari; i++) {
			cout << "| ";
			for (int j = 0; j < nrColoane; j++) {
				cout << left << setw(dimensiuneColoane[j]) << setfill(' ') << this->inregistrari[i][indexColoane[j]] << "| ";
			}
			cout << endl;
		}
		cout << "=";
		for (int i = 0; i < nrColoane; i++) {
			cout << left << setw(dimensiuneColoane[i]) << setfill('=') << "" << "==";
		}
		cout << endl;
	}
	void afisareInregistrariWHERE(const int& nrColoane, const vector<string>& numeColoane, const string& whereNumeColoana, const string& valoare) const {

		int* indexColoane = new int[nrColoane];
		for (int i = 0; i < nrColoane; i++) {
			indexColoane[i] = -1;
			for (int j = 0; j < this->nrColoane; j++) {
				if (this->numeColoana[j] == numeColoane[i]) {
					indexColoane[i] = j;
					break;
				}
			}
			if (indexColoane[i] == -1) {
				throw invalid_argument("O coloana nu exista!");
			}
		}
		int indexColoanaWhere = -1;
		for (int i = 0; i < this->nrColoane; i++) {
			if (this->numeColoana[i] == whereNumeColoana) {
				indexColoanaWhere = i;
				break;
			}
		}
		if (indexColoanaWhere == -1) {
			throw invalid_argument("Coloana din WHERE nu exista!");
		}

		int* dimensiuneColoane = new int[nrColoane];
		for (int i = 0; i < nrColoane; i++) {
			dimensiuneColoane[i] = (int)numeColoana[indexColoane[i]].length();
		}

		for (int i = 0; i < this->nrInregistrari; i++) {
			if (this->inregistrari[i][indexColoanaWhere] == valoare) {
				for (int j = 0; j < nrColoane; j++) {
					if (this->inregistrari[i][indexColoane[j]].length() > dimensiuneColoane[j]) {
						dimensiuneColoane[j] = (int)this->inregistrari[i][indexColoane[j]].length();
					}
				}
			}
		}

		for (int i = 0; i < nrColoane; i++) {
			dimensiuneColoane[i]++;
		}
		cout << "=";
		for (int i = 0; i < nrColoane; i++) {
			cout << left << setw(dimensiuneColoane[i]) << setfill('=') << "" << "==";
		}
		cout << endl;
		cout << "| ";
		for (int i = 0; i < nrColoane; i++) {
			cout << left << setw(dimensiuneColoane[i]) << setfill(' ') << numeColoana[indexColoane[i]] << "| ";
		}
		cout << endl;
		cout << "=";
		for (int i = 0; i < nrColoane; i++) {
			cout << left << setw(dimensiuneColoane[i]) << setfill('=') << "" << "==";
		}
		cout << endl;
		for (int i = 0; i < this->nrInregistrari; i++) {
			if (this->inregistrari[i][indexColoanaWhere] == valoare) {
				cout << "| ";
				for (int j = 0; j < nrColoane; j++) {
					cout << left << setw(dimensiuneColoane[j]) << setfill(' ') << this->inregistrari[i][indexColoane[j]] << "| ";
				}
				cout << endl;
			}
		}
		cout << "=";
		for (int i = 0; i < nrColoane; i++) {
			cout << left << setw(dimensiuneColoane[i]) << setfill('=') << "" << "==";
		}
		cout << endl;
	}
	void afisareInregistrariALL() const {
		int* dimensiuneColoane = new int[this->nrColoane];
		for (int i = 0; i < this->nrColoane; i++) {
			dimensiuneColoane[i] = (int)this->numeColoana[i].length();
		}
		for (int i = 0; i < this->nrInregistrari; i++) {
			for (int j = 0; j < this->nrColoane; j++) {
				if (this->inregistrari[i][j].length() > dimensiuneColoane[j]) {
					dimensiuneColoane[j] = (int)this->inregistrari[i][j].length();
				}
			}
		}
		for (int i = 0; i < this->nrColoane; i++) {
			dimensiuneColoane[i]++;
		}
		cout << "=";
		for (int i = 0; i < this->nrColoane; i++) {
			cout << left << setw(dimensiuneColoane[i]) << setfill('=') << "" << "==";
		}
		cout << endl;
		cout << "| ";
		for (int i = 0; i < this->nrColoane; i++) {
			cout << left << setw(dimensiuneColoane[i]) << setfill(' ') << this->numeColoana[i] << "| ";
		}
		cout << endl;
		cout << "=";
		for (int i = 0; i < this->nrColoane; i++) {
			cout << left << setw(dimensiuneColoane[i]) << setfill('=') << "" << "==";
		}
		cout << endl;
		for (int i = 0; i < this->nrInregistrari; i++) {
			cout << "| ";
			for (int j = 0; j < this->nrColoane; j++) {
				cout << left << setw(dimensiuneColoane[j]) << setfill(' ') << this->inregistrari[i][j] << "| ";
			}
			cout << endl;
		}
		cout << "=";
		for (int i = 0; i < this->nrColoane; i++) {
			cout << left << setw(dimensiuneColoane[i]) << setfill('=') << "" << "==";
		}
		cout << endl;
	}
	void afisareInregistrariWHEREALL(const string& whereNumeColoana, const string& valoare) const {
		int indexColoanaWhere = -1;
		for (int i = 0; i < this->nrColoane; i++) {
			if (this->numeColoana[i] == whereNumeColoana) {
				indexColoanaWhere = i;
				break;
			}
		}
		if (indexColoanaWhere == -1) {
			throw invalid_argument("Coloana din WHERE nu exista!");
		}

		int* dimensiuneColoane = new int[this->nrColoane];
		for (int i = 0; i < this->nrColoane; i++) {
			dimensiuneColoane[i] = (int)this->numeColoana[i].length();
		}
		for (int i = 0; i < this->nrInregistrari; i++) {
			if (this->inregistrari[i][indexColoanaWhere] == valoare) {
				for (int j = 0; j < this->nrColoane; j++) {
					if (this->inregistrari[i][j].length() > dimensiuneColoane[j]) {
						dimensiuneColoane[j] = (int)this->inregistrari[i][j].length();
					}
				}
			}
		}
		for (int i = 0; i < this->nrColoane; i++) {
			dimensiuneColoane[i]++;
		}
		cout << "=";
		for (int i = 0; i < nrColoane; i++) {
			cout << left << setw(dimensiuneColoane[i]) << setfill('=') << "" << "==";
		}
		cout << endl;
		cout << "| ";
		for (int i = 0; i < nrColoane; i++) {
			cout << left << setw(dimensiuneColoane[i]) << setfill(' ') << numeColoana[i] << "| ";
		}
		cout << endl;
		cout << "=";
		for (int i = 0; i < nrColoane; i++) {
			cout << left << setw(dimensiuneColoane[i]) << setfill('=') << "" << "==";
		}
		cout << endl;

		for (int i = 0; i < this->nrInregistrari; i++) {
			if (this->inregistrari[i][indexColoanaWhere] == valoare) {
				cout << "| ";
				for (int j = 0; j < this->nrColoane; j++) {
					cout << left << setw(dimensiuneColoane[j]) << setfill(' ') << this->inregistrari[i][j] << "| ";
				}
				cout << endl;
			}
		}
		cout << "=";
		for (int i = 0; i < nrColoane; i++) {
			cout << left << setw(dimensiuneColoane[i]) << setfill('=') << "" << "==";
		}
		cout << endl;
	}

	//UPDATE
	void actualizareInregistrari(const string& numeColoana, const string& valoareNoua, const string& whereNumeColoana, const string& valoareWhere) {
		int indexColoana = -1;
		for (int i = 0; i < this->nrColoane; i++) {
			if (this->numeColoana[i] == numeColoana) {
				indexColoana = i;
				break;
			}
		}
		if (indexColoana == -1) {
			throw invalid_argument("Coloana nu exista!");
		}
		int indexColoanaWhere = -1;
		for (int i = 0; i < this->nrColoane; i++) {
			if (this->numeColoana[i] == whereNumeColoana) {
				indexColoanaWhere = i;
				break;
			}
		}
		if (indexColoanaWhere == -1) {
			throw invalid_argument("Coloana din WHERE nu exista!");
		}

		if (this->tip[indexColoana] == INT) {
			if (valoareNoua.find_first_not_of("0123456789-") != string::npos) {
				throw invalid_argument("Valoarea nu este de tipul specificat!");
			}
		}
		if (this->tip[indexColoana] == FLOAT) {
			if (valoareNoua.find_first_not_of("0123456789.-") != string::npos) {
				throw invalid_argument("Valoarea nu este de tipul specificat!");
			}
		}
		if (valoareNoua.length() > this->dimensiune[indexColoana])
			throw length_error("Valoarea noua are dimensiunea mai mare decat cea specificata!");

		int nrInregistrariModificate = 0;
		for (int i = 0; i < this->nrInregistrari; i++) {
			if (this->inregistrari[i][indexColoanaWhere] == valoareWhere) {
				this->inregistrari[i][indexColoana] = valoareNoua;
				nrInregistrariModificate++;
			}
		}
		cout << "S-au modificat " << nrInregistrariModificate << " inregistrari." << endl;
	}

	//EXPORT STRUCTURA
	void exportStructura(ofstream& f) const {
		int len;

		len = (int)this->nume.length() + 1;
		f.write((char*)&len, sizeof(int));
		f.write(this->nume.data(), len);

		f.write((char*)&this->nrColoane, sizeof(int));

		for (int i = 0; i < this->nrColoane; i++) {
			len = (int)this->numeColoana[i].length() + 1;
			f.write((char*)&len, sizeof(int));
			f.write(this->numeColoana[i].data(), len);

			f.write((char*)&this->tip[i], sizeof(int));

			f.write((char*)&this->dimensiune[i], sizeof(int));

			len = (int)this->valoareImplicita[i].length() + 1;
			f.write((char*)&len, sizeof(int));
			f.write(this->valoareImplicita[i].data(), len);
		}
		lf.adaugareFisier(nume);
	}
	//IMPORT STRUCTURA
	void importStructura(ifstream& f) {
		int len;

		f.read((char*)&len, sizeof(int));
		char* buffer = new char[len];
		f.read(buffer, len);
		this->nume = buffer;
		delete[] buffer;

		f.read((char*)&this->nrColoane, sizeof(int));

		for (int i = 0; i < this->nrColoane; i++) {
			f.read((char*)&len, sizeof(int));
			buffer = new char[len];
			f.read(buffer, len);
			numeColoana.emplace_back(buffer);
			delete[] buffer;

			tipColoana tip_temp;
			f.read((char*)&tip_temp, sizeof(int));
			tip.push_back(tip_temp);

			int dimensiune_temp;
			f.read((char*)&dimensiune_temp, sizeof(int));
			dimensiune.push_back(dimensiune_temp);

			f.read((char*)&len, sizeof(int));
			buffer = new char[len];
			f.read(buffer, len);
			valoareImplicita.emplace_back(buffer);
			delete[] buffer;
		}
	}

	//EXPORT INREGISTRARI
	void exportInregistrari(const string& numeFisier) const {
		if (this->nrInregistrari == 0) {
			throw invalid_argument("Nu exista inregistrari!");
		}
		ofstream f(inregistrariFolder + numeFisier, ios::out);
		for (int i = 0; i < this->nrInregistrari; i++) {
			for (int j = 0; j < this->nrColoane; j++) {
				f << this->inregistrari[i][j];
				if (j < this->nrColoane - 1)
					f << ",";
			}
			f << endl;
		}
		f.close();
		
		if (this->nrInregistrari == 1)
			cout << "S-a exportat o inregistrare." << endl;
		else
			cout << "S-au exportat " << this->nrInregistrari << " inregistrari." << endl;
	}
	//IMPORT INREGISTRARI
	void importInregistrari(const string& numeFisier) {
		ifstream f(inregistrariFolder + numeFisier);
		if (f.is_open()) {
			string linie;
			
			int nrInregistrariImportate = 0;
			vector<vector<string>> inregistrariTemp;
			
			while (getline(f, linie)) {
				vector<string> inregistrare;
				stringstream ss(linie);
				string valoare;
				while (getline(ss, valoare, ',')) {
					inregistrare.push_back(valoare);
				}
				if (inregistrare.size() != this->nrColoane) {
					throw invalid_argument("Numarul de coloane din fisierul de import nu corespunde cu numarul de coloane din tabela!");
				}
				for (int i = 0; i < this->nrColoane; i++) {
					if (this->tip[i] == INT) {
						if (inregistrare[i].find_first_not_of("0123456789-") != string::npos) {
							throw invalid_argument("Valoarea nu este de tipul specificat!");
						}
					}
					if (this->tip[i] == FLOAT) {
						if (inregistrare[i].find_first_not_of("0123456789.-") != string::npos) {
							throw invalid_argument("Valoarea nu este de tipul specificat!");
						}
					}
					if (inregistrare[i].length() > this->dimensiune[i])
						throw length_error("Valoarea are dimensiunea mai mare decat cea specificata!");
				}
				inregistrariTemp.push_back(inregistrare);
				nrInregistrariImportate++;
			}
			f.close();
			for (int i = 0; i < nrInregistrariImportate; i++) {
				this->inregistrari.push_back(inregistrariTemp[i]);
			}
			this->nrInregistrari += nrInregistrariImportate;
			
			if (nrInregistrariImportate == 0)
				cout << "Nu s-a importat nicio inregistrare." << endl;
			else if (nrInregistrariImportate == 1)
				cout << "S-a importat o inregistrare." << endl;
			else
				cout << "S-au importat " << nrInregistrariImportate << " inregistrari." << endl;
		}
		else {
			throw invalid_argument("Fisierul nu exista!");
		}
	}
};

// Sistem gestionare tabele
class GestionareTabele {
	static int nrTabele;
	vector<Tabela> tabele;
public:
	//Getteri
	int getNrColoane(const string& nume) const {
		for (int i = 0; i < nrTabele; i++)
			if (this->tabele[i].getNume() == nume)
				return this->tabele[i].getNrColoane();
		throw invalid_argument("Nu exista o tabela cu acest nume!");
	}

	//Verificare existenta tabela
	bool existaTabela(const string& nume) const {
		for (int i = 0; i < nrTabele; i++)
			if (this->tabele[i].getNume() == nume)
				return true;
		return false;
	}

	//CREATE TABLE
	void adaugareTabela(const string& nume, const int& nrColoane, const vector<string>& numeColoana, const vector<string>& tip, const vector<int>& dimensiune, const vector<string>& valoareImplicita) {
		if (existaTabela(nume))
			throw invalid_argument("O tabela cu acest nume exista deja!\n");
		this->tabele.emplace_back(nume, nrColoane, numeColoana, tip, dimensiune, valoareImplicita);
		nrTabele++;

		if (autoSave) exportStructura(nume);
	}

	//DISPLAY TABLE
	void displayTabele() {
		if (nrTabele == 0)
			throw logic_error("Nu exista nicio tabela.");

		for (int i = 0; i < nrTabele; i++)
			cout << tabele[i];
	}
	void displayTabela(const string& nume) {
		for (int i = 0; i < nrTabele; i++)
			if (this->tabele[i].getNume() == nume) {
				cout << tabele[i];
				return;
			}
		throw invalid_argument("Nu exista o tabela cu acest nume!");
	}

	//DROP TABLE
	void stergereTabela(const string& nume) {
		for (int i = 0; i < nrTabele; i++)
			if (this->tabele[i].getNume() == nume) {
				this->tabele.erase(this->tabele.begin() + i);
				nrTabele--;
				cout << "Tabela " << nume << " a fost stearsa cu succes!" << endl;

				if (autoSave)
					lf.deleteFisier(nume);

				return;
			}
		throw invalid_argument("Nu exista o tabela cu acest nume!");
	}
	void stergereTabele() {
		for (int i = nrTabele - 1; i >= 0; i--) {
			if (autoSave)
				lf.deleteFisier(this->tabele[i].getNume());

			this->tabele.erase(this->tabele.begin() + i);

			nrTabele--;
		}

		nrTabele = 0;
		this->tabele.clear();

		cout << "Toate tabelele au fost sterse cu succes!" << endl;
	}

	//INSERT INTO
	void adaugareInregistrare(const string& nume, const vector<string>& valori) {
		for (int i = 0; i < nrTabele; i++)
			if (this->tabele[i].getNume() == nume) {
				this->tabele[i].adaugareInregistrare(valori);
				cout << "Inregistrarea a fost adaugata cu succes!" << endl;
				return;
			}
		throw invalid_argument("Nu exista o tabela cu acest nume!");
	}

	//DELETE FROM
	void stergereInregistrare(const string& nume, const string& numeColoana, const string& valoare) {
		for (int i = 0; i < nrTabele; i++)
			if (this->tabele[i].getNume() == nume) {
				this->tabele[i].stergereInregistrare(numeColoana, valoare);
				return;
			}
		throw invalid_argument("Nu exista o tabela cu acest nume!");
	}
	void stergereInregistrari(const string& nume) {
		for (int i = 0; i < nrTabele; i++)
			if (this->tabele[i].getNume() == nume) {
				this->tabele[i].stergereInregistrari();
				return;
			}
		throw invalid_argument("Nu exista o tabela cu acest nume!");
	}

	//SELECT
	void afisareInregistrariALL(const string& nume) const {
		for (int i = 0; i < nrTabele; i++)
			if (this->tabele[i].getNume() == nume) {
				this->tabele[i].afisareInregistrariALL();
				return;
			}
		throw invalid_argument("Nu exista o tabela cu acest nume!");
	}
	void afisareInregistrari(const string& nume, const int& nrColoane, const vector<string>& numeColoana) const {
		for (int i = 0; i < nrTabele; i++)
			if (this->tabele[i].getNume() == nume) {
				this->tabele[i].afisareInregistrari(nrColoane, numeColoana);
				return;
			}
		throw invalid_argument("Nu exista o tabela cu acest nume!");
	}
	void afisareInregistrariWHERE(const string& nume, const int& nrColoane, const vector<string>& numeColoana, const string& whereNumeColoana, const string& whereValoare) const {
		for (int i = 0; i < nrTabele; i++)
			if (this->tabele[i].getNume() == nume) {
				this->tabele[i].afisareInregistrariWHERE(nrColoane, numeColoana, whereNumeColoana, whereValoare);
				return;
			}
		throw invalid_argument("Nu exista o tabela cu acest nume!");
	}
	void afisareInregistrariWHEREALL(const string& nume, const string& whereNumeColoana, const string& whereValoare) const {
		for (int i = 0; i < nrTabele; i++)
			if (this->tabele[i].getNume() == nume) {
				this->tabele[i].afisareInregistrariWHEREALL(whereNumeColoana, whereValoare);
				return;
			}
		throw invalid_argument("Nu exista o tabela cu acest nume!");
	}

	//UPDATE
	void actualizareInregistrari(const string& nume, const string& numeColoana, const string& valoare, const string& whereNumeColoana, const string& whereValoare) {
		for (int i = 0; i < nrTabele; i++)
			if (this->tabele[i].getNume() == nume) {
				this->tabele[i].actualizareInregistrari(numeColoana, valoare, whereNumeColoana, whereValoare);
				return;
			}
		throw invalid_argument("Nu exista o tabela cu acest nume!");
	}

	//EXPORT STRUCTURA
	void exportStructura(const string& numeTabela) const {
		for (int i = 0; i < nrTabele; i++)
			if (this->tabele[i].getNume() == numeTabela) {
				ofstream f(autoSaveFolder + numeTabela + ".bin", ios::binary);
				this->tabele[i].exportStructura(f);
				f.close();
			}
	}
	//IMPORT STRUCTURA
	void importStructura(const int& nrTabele, const vector<string>& numeTabele) {
		for (int i = 0; i < nrTabele; i++) {
			ifstream f(autoSaveFolder + numeTabele[i] + ".bin", ios::binary);
			this->tabele.emplace_back();
			this->tabele[i].importStructura(f);
			GestionareTabele::nrTabele++;

			f.close();
		}
	}

	//EXPORT INREGISTRARI
	void exportInregistrari(const string& numeTabela, const string& numeFisier) const {
		for (int i = 0; i < nrTabele; i++)
			if (this->tabele[i].getNume() == numeTabela) {
				this->tabele[i].exportInregistrari(numeFisier);
				return;
			}
		throw invalid_argument("Nu exista o tabela cu acest nume!");
	}
	//IMPORT INREGISTRARI
	void importInregistrari(const string& numeTabela, const string& numeFisier) {
		for (int i = 0; i < nrTabele; i++)
			if (this->tabele[i].getNume() == numeTabela) {
				this->tabele[i].importInregistrari(numeFisier);
				return;
			}
		throw invalid_argument("Nu exista o tabela cu acest nume!");
	}
};

extern GestionareTabele gt;
