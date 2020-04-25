#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class game_of_life {
private:
	static const unsigned int STUPACA = 40;
	static const unsigned int REDAKA = 20;
	bool _generacija[REDAKA][STUPACA];
	bool _sljedeca_generacija[REDAKA][STUPACA];
	bool slucajna_vrijednost();
	int broj_susjeda(int x, int y);
	char Znak(bool stanje);
	void zamjena();
	

public:
	game_of_life();
	void sljedeca_generacija();
	void iscrtaj();
};

#endif
