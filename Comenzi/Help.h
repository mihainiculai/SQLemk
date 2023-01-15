#pragma once

class Help {
	int dimensiuneMax = 20;
public:
	void run(const vector<string>& camp, const int& nrCampuri) const {
		if (nrCampuri == 1) {
			cout << endl << "Pentru mai multe informatii despre o comanda, tasteaza HELP [nume comanda]" << endl << endl;

			cout << left << setw(dimensiuneMax) << setfill(' ') << "CREATE TABLE";
			cout << "Creeaza o tabela in baza de date" << endl;

			cout << left << setw(dimensiuneMax) << setfill(' ') << "DROP TABLE";
			cout << "Sterge o tabela existanta in baza de data" << endl;

			cout << left << setw(dimensiuneMax) << setfill(' ') << "DISPLAY TABLE";
			cout << "Descrie structura unei tabele existente in baza de date" << endl;

			cout << left << setw(dimensiuneMax) << setfill(' ') << "INSERT INTO";
			cout << "Insereaza inregistrari noi intr-o tabela existenta in baza de date" << endl;

			cout << left << setw(dimensiuneMax) << setfill(' ') << "DELETE FROM";
			cout << "Sterge inregistrari dintr-o tabela existenta in baza de date" << endl;

			cout << left << setw(dimensiuneMax) << setfill(' ') << "SELECT";
			cout << "Selecteaza inregistrari dintr-o tabela existenta in baza de date" << endl;

			cout << left << setw(dimensiuneMax) << setfill(' ') << "UPDATE";
			cout << "Modifica inregistrari dintr-o tabela existenta in baza de date" << endl;

			cout << left << setw(dimensiuneMax) << setfill(' ') << "IMPORT";
			cout << "Importa inregistrari dintr-un fisier CSV in baza de date" << endl;

			cout << left << setw(dimensiuneMax) << setfill(' ') << "EXPORT";
			cout << "Exporta inregistrari din baza de date in fisier CSV" << endl;

			cout << left << setw(dimensiuneMax) << setfill(' ') << "PRESETS";
			cout << "Afiseaza lista de preseturi" << endl;

			cout << left << setw(dimensiuneMax) << setfill(' ') << "CLEAR";
			cout << "Curata ecranul consolei" << endl;

			cout << left << setw(dimensiuneMax) << setfill(' ') << "PRINT";
			cout << "Activeaza/dezactiveaza mesajele si erorile" << endl;

			cout << left << setw(dimensiuneMax) << setfill(' ') << "EXIT";
			cout << "Iesire din aplicatie" << endl << endl;
		}
		else if (nrCampuri == 3) {
			if (camp[1] == "CREATE" && camp[2] == "TABLE") {
				cout << "Comanda creeaza o tabela in baza de date" << endl;
				cout << endl << "Sintaxa:" << endl;
				cout << "CREATE TABLE nume_tabela (nume_coloana1, tip_coloana1, dimensiunea_maxima1, valoarea_implicita1), (nume_coloana2, ...)" << endl;
				cout << endl << "Exemplu:" << endl;
				cout << "CREATE TABLE studenti (nume, CHAR, 30, anonim), (media, FLOAT, 5, 0), (varsta, INT, 2, 18)" << endl;

				cout << endl << "Detalii:" << endl;

				cout << left << setw(dimensiuneMax) << setfill(' ') << "nume_tabela";
				cout << "trebuie sa fie un cuvant / mai multe cuvinte separate prin '_'" << endl;

				cout << left << setw(dimensiuneMax) << setfill(' ') << "nume_coloana";
				cout << "trebuie sa fie un cuvant / mai multe cuvinte separate prin '_'" << endl;

				cout << left << setw(dimensiuneMax) << setfill(' ') << "tip_coloana";
				cout << "poate fi CHAR, INT sau FLOAT" << endl;

				cout << left << setw(dimensiuneMax) << setfill(' ') << "dimensiunea_maxima";
				cout << "trebuie sa fie un numar intreg pozitiv" << endl;
				cout << left << setw(dimensiuneMax) << setfill(' ') << "";
				cout << "valoarea maxima este de 255 de caractere";
			}
			else if (camp[1] == "DROP" && camp[2] == "TABLE") {
				cout << "Comanda sterge o tabela existenta in baza de data" << endl;
				cout << endl << "Sintaxa:" << endl;
				cout << "DROP TABLE nume_tabela" << endl;
				cout << endl << "Exemplu:" << endl;
				cout << "DROP TABLE studenti" << endl;

				cout << endl << "Detalii:" << endl;
				cout << "Pentru a sterge toate tabelele din baza de date, foloseste comanda DROP TABLE *" << endl;
				cout << left << setw(dimensiuneMax) << setfill(' ') << "nume_tabela";
				cout << "trebuie sa fie un cuvant / mai multe cuvinte separate prin '_'" << endl;
			}
			else if (camp[1] == "DISPLAY" && camp[2] == "TABLE") {
				cout << "Comanda descrie structura unei tabele existente in baza de date" << endl;
				cout << endl << "Sintaxa:" << endl;
				cout << "DISPLAY TABLE nume_tabela" << endl;
				cout << endl << "Exemplu:" << endl;
				cout << "DISPLAY TABLE studenti" << endl;

				cout << endl << "Detalii:" << endl;
				cout << left << setw(dimensiuneMax) << setfill(' ') << "nume_tabela";
				cout << "trebuie sa fie un cuvant / mai multe cuvinte separate prin '_'" << endl;
			}
			else if (camp[1] == "INSERT" && camp[2] == "INTO") {
				cout << "Comanda insereaza inregistrari noi intr-o tabela existenta in baza de date" << endl;
				cout << endl << "Sintaxa:" << endl;
				cout << "INSERT INTO nume_tabela (valoare1, valoare2, ...)" << endl;
				cout << endl << "Exemplu:" << endl;
				cout << "INSERT INTO studenti (Ion, 9.5, 20)" << endl;

				cout << endl << "Detalii:" << endl;
				cout << left << setw(dimensiuneMax) << setfill(' ') << "nume_tabela";
				cout << "trebuie sa fie un cuvant / mai multe cuvinte separate prin '_'" << endl;
				cout << left << setw(dimensiuneMax) << setfill(' ') << "valoare";
				cout << "trebuie sa fie un numar / cuvant / mai multe cuvinte separate prin '_'" << endl;
			}
			else if (camp[1] == "DELETE" && camp[2] == "FROM") {
				cout << "Comanda sterge inregistrari dintr-o tabela existenta in baza de date" << endl;
				cout << endl << "Sintaxa:" << endl;
				cout << "DELETE FROM nume_tabela WHERE nume_coloana = valoare" << endl;
				cout << endl << "Exemplu:" << endl;
				cout << "DELETE FROM studenti WHERE nume = Ion" << endl;

				cout << endl << "Detalii:" << endl;
				cout << left << setw(dimensiuneMax) << setfill(' ') << "nume_tabela";
				cout << "trebuie sa fie un cuvant / mai multe cuvinte separate prin '_'" << endl;
				cout << left << setw(dimensiuneMax) << setfill(' ') << "nume_coloana";
				cout << "trebuie sa fie un cuvant / mai multe cuvinte separate prin '_'" << endl;
				cout << left << setw(dimensiuneMax) << setfill(' ') << "valoare";
				cout << "trebuie sa fie un numar / cuvant / mai multe cuvinte separate prin '_'" << endl;
			}
			else throw invalid_argument("Comanda nu exista!");
			cout << endl;
		}
		else if (nrCampuri == 2) {
			if (nrCampuri == 2 && camp[1] == "SELECT") {
				cout << "Comanda afiseaza inregistrari dintr-o tabela existenta in baza de date" << endl;
				cout << endl << "Sintaxa:" << endl;
				cout << "SELECT nume_coloana1, numecoloana2... FROM nume_tabela WHERE nume_coloana = valoare" << endl;
				cout << endl << "Exemplu:" << endl;
				cout << "SELECT nume, medie, varsta FROM studenti WHERE nume = Ion" << endl;

				cout << endl << "Detalii:" << endl;
				cout << "Pentru a afisa toate coloanele dintr-o tabela, se foloseste comanda SELECT * FROM nume_tabela" << endl;
				cout << left << setw(dimensiuneMax) << setfill(' ') << "nume_tabela";
				cout << "trebuie sa fie un cuvant / mai multe cuvinte separate prin '_'" << endl;
				cout << left << setw(dimensiuneMax) << setfill(' ') << "nume_coloana";
				cout << "trebuie sa fie un cuvant / mai multe cuvinte separate prin '_'" << endl;
				cout << left << setw(dimensiuneMax) << setfill(' ') << "valoare";
				cout << "trebuie sa fie un numar / cuvant / mai multe cuvinte separate prin '_'" << endl;
			}
			else if (nrCampuri == 2 && camp[1] == "UPDATE") {
				cout << "Comanda modifica inregistrari dintr-o tabela existenta in baza de date" << endl;
				cout << endl << "Sintaxa:" << endl;
				cout << "UPDATE nume_tabela SET nume_coloana = valoare WHERE nume_coloana = valoare" << endl;
				cout << endl << "Exemplu:" << endl;
				cout << "UPDATE studenti SET medie = 10 WHERE nume = Ion" << endl;

				cout << endl << "Detalii:" << endl;
				cout << left << setw(dimensiuneMax) << setfill(' ') << "nume_tabela";
				cout << "trebuie sa fie un cuvant / mai multe cuvinte separate prin '_'" << endl;
				cout << left << setw(dimensiuneMax) << setfill(' ') << "nume_coloana";
				cout << "trebuie sa fie un cuvant / mai multe cuvinte separate prin '_'" << endl;
				cout << left << setw(dimensiuneMax) << setfill(' ') << "valoare";
				cout << "trebuie sa fie un numar / cuvant / mai multe cuvinte separate prin '_'" << endl;
			}
			else if (nrCampuri == 2 && camp[1] == "IMPORT") {
				cout << "Comanda importa inregistrari dintr-un fisier CSV in baza de date" << endl;
				cout << endl << "Sintaxa:" << endl;
				cout << "IMPORT nume_tabela nume_fisier.csv" << endl;
				cout << endl << "Exemplu:" << endl;
				cout << "IMPORT studenti studenti.csv" << endl;

				cout << endl << "Detalii:" << endl;
				cout << left << setw(dimensiuneMax) << setfill(' ') << "nume_tabela";
				cout << "trebuie sa fie un cuvant / mai multe cuvinte separate prin '_'" << endl;
				cout << left << setw(dimensiuneMax) << setfill(' ') << "nume_fisier.csv";
				cout << "trebuie sa fie un cuvant / mai multe cuvinte separate prin '_'" << endl;
				cout << left << setw(dimensiuneMax) << setfill(' ') << "";
				cout << "Fisierul CSV trebuie sa fie in formatul: nume_coloana1, nume_coloana2, nume_coloana3, ..." << endl;
			}
			else if (nrCampuri == 2 && camp[1] == "EXPORT") {
				cout << "Comanda exporta inregistrari dintr-o tabela existenta in baza de date in format CSV" << endl;
				cout << endl << "Sintaxa:" << endl;
				cout << "EXPORT nume_tabela nume_fisier.csv" << endl;
				cout << endl << "Exemplu:" << endl;
				cout << "EXPORT studenti studenti.csv" << endl;

				cout << endl << "Detalii:" << endl;
				cout << left << setw(dimensiuneMax) << setfill(' ') << "nume_tabela";
				cout << "trebuie sa fie un cuvant / mai multe cuvinte separate prin '_'" << endl;
				cout << left << setw(dimensiuneMax) << setfill(' ') << "nume_fisier.csv";
				cout << "trebuie sa fie un cuvant / mai multe cuvinte separate prin '_'" << endl;
				cout << left << setw(dimensiuneMax) << setfill(' ') << "";
				cout << "Fisierul CSV trebuie sa fie in formatul: nume_coloana1, nume_coloana2, nume_coloana3, ..." << endl;
			}
			else if (nrCampuri == 2 && camp[1] == "PRESETS") {
				cout << "Comanda deschide un meniu de selectare a unui preset." << endl;
				cout << "Comanda sterge toate tabelele din baza de date." << endl;
				cout << endl << "Sintaxa:" << endl;
				cout << "PRESETS" << endl;
			}
			else if (nrCampuri == 2 && camp[1] == "PRINT") {
				cout << "Comanda activeaza / dezactiveaza mesajele si erorile de la consola." << endl;
				cout << endl << "Sintaxa:" << endl;
				cout << "PRINT on/off" << endl;
			}
			else throw invalid_argument("Comanda nu exista!");
			cout << endl;
		}
		else {
			throw invalid_argument("Comanda nu exista!");
		}
	}
};