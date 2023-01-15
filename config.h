#pragma once

//Main Path
string filePath(__FILE__);
size_t pos = filePath.find_last_of("/\\");
string mainPath = filePath.substr(0, pos) + "/";

//AutoSave structura tabele
bool autoSave = true;
string autoSaveFolder = mainPath + "Tabele/";
string autoSaveFile = "Lista Tabele.txt";

//Inregistari
string inregistrariFolder = mainPath + "Inregistrari/";

//Scripts
bool showScripts = true;

//WelcomeScreen
bool welcomeScreen = true;

//ExitScreen
bool exitScreen = true;

//Logger
bool logger = true;
string loggerFolder = mainPath + "Logs.txt";

//Printing
void stopPrinting() {
	cout.setstate(ios_base::failbit);
}
void startPrinting() {
	cout.clear();
}
void clear() {
#if defined (_WIN32) || defined(_WIN64)
	system("cls");
#else
	system("clear");
#endif
}
void pressAnyKey() {
#if defined (_WIN32) || defined(_WIN64)
	system("pause > nul");
#else
	system("read");
#endif
}