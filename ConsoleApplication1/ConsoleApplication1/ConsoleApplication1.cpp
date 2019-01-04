// ConsoleApplication1.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <time.h>

int Spielen(int Level);
int WaehleLevel(int Level);
int TesteHighscore(int Punkte, int Highscore);
void ZeigeInfos();

int main()
{

	int Level = 5;
	int Highscore = 100;
	char Auswahl;

	do {
		std::cout << "---------------------" << std::endl;
		std::cout << "---zahlenratespiel---" << std::endl;
		std::cout << "---------------------" << std::endl;
		std::cout << "(N)eues Spiel" << std::endl;
		std::cout << "(L)evel" << std::endl;
		std::cout << "(H)ighscore" << std::endl;
		std::cout << "(I)nfo" << std::endl;
		std::cout << "(B)eenden\n\n";
		std::cout << "Auswahl: " << std::endl;
		std::cin >> Auswahl;

		switch (Auswahl) {

		case ('n'):
		case ('N'):
		{
			int Punkte;
			Punkte = Spielen(Level);
			Highscore = TesteHighscore(Punkte, Highscore);
		}break;

		case ('l'):
		case ('L'):
		{
			Level = WaehleLevel(Level);
		}break;

		case ('h'):
		case ('H'):
		{
			std::cout << "der aktuelle Highscore liegt bei " ;
			std::cout << Highscore << " Punkten\n\n";
		}break;

		case ('i'):
		case ('I'):
		{
			ZeigeInfos();
		}break;

		case ('b'):
		case ('B'):
		{
			std::cout << "Spiel beendet" << std::endl;
		}break;

		default:
		{
			std::cout << "falsche Eingabe!\n\n";
		}
		}
	} while (Auswahl != 'b' && Auswahl != 'B');

	std::cout << "Bis zum naechsten Mal" << std::endl;

	return 0;
}


void ZeigeInfos() {
	std::cout << "Zahlenraten V1.0" << std::endl;
}

int WaehleLevel(int Level) {
	int NeuerLevel;

	do {
		std::cout << "Aktueller Level: " << Level << std::endl;
		std::cout << "Neuer Level (1-10)" << std::endl;
		std::cin >> NeuerLevel;

		if (NeuerLevel < 1 || NeuerLevel > 10) {
			std::cout << "ungültig" << std::endl;
		}

		

	} while (NeuerLevel < 1 || NeuerLevel > 10);
	return NeuerLevel;

}



int Spielen(int Level) {

	int zahl_search = 0;
	int Bereich = Level * 10;
	srand(time(NULL));
	int zahl_rnd = (rand() % Bereich)+1;
	int Versuche = 0;
	int Punkte;

	std::cout << "Gib eine Zahl ein, wenn diese der rnd zahl gleicht, hast du gewonnen!" << std::endl;
	   	 

	while (zahl_search != zahl_rnd) {

		std::cin >> zahl_search;
		Versuche++;
		if (zahl_search < zahl_rnd) {
			std::cout << "leider zu klein" << std::endl;
		}
		else if (zahl_search > zahl_rnd) {
			std::cout << "leider zu groß" << std::endl;
		}
		else if (zahl_search == zahl_rnd) {
			std::cout << "gewonnen!" << std::endl;
			std::cout << "nach " << Versuche << " Versuchen erraten!" << std::endl;
		}

	}
	Punkte = Bereich - Versuche + 1;
	Punkte *= Level;
	if (Punkte < 0) {
		Punkte = 0;
	}

	std::cout << "Punkte: " << std::endl;
	return Punkte;
}

int TesteHighscore(int Punkte, int Highscore) {
	if (Punkte > Highscore) {
		std::cout << "Glueckwunsch, Neuer Highscore!" << std::endl;
		Highscore = Punkte;
	}
	else {
		std::cout << "Leider kein neuer Highscore!" << std::endl;
	}

	return Highscore;
}



