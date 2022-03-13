#pragma once
#include <iostream>
#include "Letra.h"
#include "Palavra.h"

using namespace std;
class Tabuleiro
{
private:
	Palavra* palavras;
	int dimX, dimY, numPalavras;
	Letra** letras;

public:
	Tabuleiro(void);
	~Tabuleiro();
	void Inicio(int, int);
	void Ver(void);
	void SetDimX(int x) { dimX = x; }
	void SetDimY(int y) { dimY = y; }
};

