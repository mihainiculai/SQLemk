#pragma once

class InterpretatorComanda {
private:
	int nrCampuri = 0;
	vector<string> campuri;
public:
	void splitComanda(const string& comanda) {
		string cuvant;
		int cuvantCurent = 0;
		for (auto x : comanda) {
			if (x == ' ' && !cuvant.empty()) {
				campuri.push_back(cuvant);
				cuvantCurent++;
				cuvant = "";
			}
			else if (!((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x >= '0' && x <= '9') || x == '_' || x == ' ' || x == '*' || x == '.' || x == '-' || x == '@' || x == '/'))  {
				if (cuvant.empty()) {
					cuvant = x;
					campuri.push_back(cuvant);
					cuvantCurent++;
					cuvant = "";
				}
				else {
					campuri.push_back(cuvant);
					cuvant = x;
					campuri.push_back(cuvant);
					cuvantCurent += 2;
					cuvant = "";
				}
			}
			else if (x != ' ') {
				cuvant += x;
			}
		}
		if (!cuvant.empty()) {
			campuri.push_back(cuvant);
			cuvantCurent++;
		}
		nrCampuri = cuvantCurent;
	}
	void rulare(const string& comanda) {
		campuri.clear();
		campuri.reserve(25);
		this->nrCampuri = 0;
		
		if (comanda.empty())
			return;
		if (comanda == "CLEAR") {
			clear();
			return;
		}
		if (comanda == "EXIT") {
			leaveMessage();
			exit(0);
		}
		
		splitComanda(comanda);
		
		if (campuri[0] == "HELP") {
			Help h;
			h.run(campuri, nrCampuri);
			return;
		}
		
		if (nrCampuri < 2) {
			throw logic_error("Comanda invalida!");
		}
		
		if (campuri[0] == "CREATE" && campuri[1] == "TABLE") {
			CreateTable ct;
			ct.run(campuri, nrCampuri);
		}
		else if (campuri[0] == "DROP" && campuri[1] == "TABLE") {
			DropTable dt;
			dt.run(campuri, nrCampuri);
		}
		else if (campuri[0] == "DISPLAY" && campuri[1] == "TABLE") {
			DisplayTable dt;
			dt.run(campuri, nrCampuri);
		}
		else if (campuri[0] == "INSERT" && campuri[1] == "INTO") {
			InsertInto ii;
			ii.run(campuri, nrCampuri);
		}
		else if (campuri[0] == "DELETE" && campuri[1] == "FROM") {
			DeleteFrom df;
			df.run(campuri, nrCampuri);
		}
		else if (campuri[0] == "SELECT") {
			Select s;
			s.run(campuri, nrCampuri);
		}
		else if (campuri[0] == "UPDATE") {
			Update u;
			u.run(campuri, nrCampuri);
		}
		else if (campuri[0] == "EXPORT") {
			Export e;
			e.run(campuri, nrCampuri);
		}
		else if (campuri[0] == "IMPORT") {
			Import i;
			i.run(campuri, nrCampuri);
		}
		else if (campuri[0] == "PRINT") {
			if (campuri[1] == "off")
				stopPrinting();
			else if (campuri[1] == "on")
				startPrinting();
			else
				cout << "Comanda invalida!" << endl;
		}
		else {
			cout << "Comanda invalida!" << endl;
		}
		cout << endl;
	}
};

extern InterpretatorComanda ic;