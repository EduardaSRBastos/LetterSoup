#include "Jogador.h"



Jogador::Jogador()
{
	nome = "";
	idade = 0;
	pontos = 0;
}

Jogador::Jogador(string _nome, int _idade, int _pontos)
{
	nome = _nome;
	idade = _idade;
	pontos = _pontos;
}


Jogador::~Jogador()
{
}
