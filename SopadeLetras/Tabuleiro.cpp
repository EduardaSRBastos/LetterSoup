#include "Tabuleiro.h"



Tabuleiro::Tabuleiro(void)
{
	SetDimX(0);
	SetDimY(0);
	letras = NULL;
	numPalavras = 0;
}


Tabuleiro::~Tabuleiro()
{
}

void Tabuleiro::Inicio(int x, int y)
{
	SetDimX(x);
	SetDimY(y);
}

void Tabuleiro::Ver(void)
{
}
