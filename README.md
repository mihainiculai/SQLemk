# SQLemk

**SQLemk** este un proiect care **simulează limbajul SQL în C++**.
Acesta permite utilizatorilor să **execute comenzi SQL în C++**, cum ar fi crearea tabelelor, a insera, actualiza și interoga înregistrări și multe altele.

Aceasta este o **versiune LIMITATĂ** de SQL și **sintaxa poate să difere față de standardul SQL.**

Acest este un proiect școlar făcut la **Facultatea de Cibernetică, Statistică și Informatică Economică (CSIE)** din cadrul **ASE București** la materia **Programare Orientată pe Obiecte (POO)**.

# Funcționalitățile aplicației 💪
## Comenzi disponibile ✅

 - CREATE TABLE - Creeaza o tabela in baza de date
 - DROP TABLE - Sterge o tabela existanta in baza de data
 - DISPLAY TABLE - Descrie structura unei tabele existente in baza de date
 - INSET INTO - Insereaza inregistrari noi intr-o tabela existenta in baza de date
 - DELETE FROM - Sterge inregistrari dintr-o tabela existenta in baza de date
 - SELECT - Selecteaza inregistrari dintr-o tabela existenta in baza de date
 - UPDATE - Modifica inregistrari dintr-o tabela existenta in baza de date
 - IMPORT - Importa inregistrari dintr-un fisier CSV in baza de date
 - EXPORT - Exporta inregistrari din baza de date in fisier CSV
 - PRESETS - Afiseaza lista de preseturi
 - CLEAR - Curata ecranul consolei
 - PRINT - Activeaza/dezactiveaza mesajele si erorile
 - EXIT - Iesire din aplicatie

Pentru mai multe detalii despre fiecare comanda, tastați în consolă:

    HELP [nume comanda]

## Preseturi 🏢
Este inplementat un meniu de preseturi ce conține 5 baze de date pentru gestionarea unor entități economice:

 - Firmă (angajați, departamente, proiecte)
 - Școală (elevi, profesori, clase)
 - Bibliotecă (cărți, abonați, împrumuturi)
 - Magazin (produse, clienți, comenzi)
 - Joc (jucători, obiecte, inventar)

## Parametrii la executarea programului 🖥️
Aplicația poate executa fișiere script de tip .sql precum cele incluse în codul sursă ca parametrii la executarea programului.
Acestea se pot executa la rularea programului astfel:

    SQLemk.exe script1.sql [script2.sql] ...
Aplicația rulează și fără astfel de scripturi primite ca parametru.

## Auto-Save-ul tabelelor 😊
Structura tabelelor se poate auto-salva, iar la următoarea execuție a programului, acestea să fie importate automat.

## Importarea / Exportarea înregistrărilor 📁
Înregistrările aflate în tabele se pot importa și exporta cu ajutorul fișierelor de tip .csv
## Generarea de log-uri 📄
Aplicația salvează loguri cu absolut toate comenzile executate de utilizator, cu momentul în care au fost folosite și dacă s-a generat o eroare în urma executării ei.

## Mesaje de welcome și goodbye 👋
La pornirea aplicației se afișează o mini-animație cu un text art SQLemk.

## Fișier de configurare ⚙️
De acolo se pot modifica diverși parametrii ce țin de configurația proiectului.
Se poate porni / opri auto-save-ul, mesajele de welcome și goodbye, se pot modifica fișierele în care se salvează structurile și înregistrările tabelelor etc.

# Caracteristici 📜
Aplicația folosește:
- implementarea claselor
	- Toate atributele sunt definite în parte privată a clasei
	- Folosirea atributelor constante și statice
	- Diferite tipuri de constructori (default, cu parametrii, de copiere)
	- Funții accesor (get și set)
	- Diverși operatori (operatorul =, <<, >> etc.)
	- Relații între clase de tip has-a și is-a
- Implementarea fișierelor
	- de tip .txt
	- de tip .csv (comma-separated values)
	- de tip .bin (fișiere binare)
- Implementarea de STL-uri (vector, set)

Programul aruncă excepții pentru toate cazurile posibile.
exemplu: format invalid al comenzii, parametrii eroanți, date neconforme etc.

# Intalare 📝

 1. Descarcați sursa proiectului de pe Github
 2. Utilizați un compilator C++ pentru a compila și a genera un fișier executabil. Folosiți un IDE precum Visual Studio 2022 sau CLion 2023
 3. Rulați programul

# Compatibilitate 💻

Programul funcționează atât pe Winows, Linux cât și pe MacOS.
Este nevoie de un compilator ce suportă minim C++14.

