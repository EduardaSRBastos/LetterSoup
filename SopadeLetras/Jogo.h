#pragma once
#include <iostream>
#include "Tabuleiro.h"
#include "Jogador.h"
class Jogo
{
private:
	Tabuleiro jogo;
	Jogador jogador;
public:
	Jogo();
	Jogo(int, int);
	void Iniciar();
	int Jogar();
	~Jogo();
};

