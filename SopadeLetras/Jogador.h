#pragma once
#include <iostream>
#include <string>

using namespace std;
class Jogador
{
private:
	string nome;
	int idade, pontos;
public:
	Jogador();
	Jogador(string, int, int);
	string GetNome() const { return nome; }
	void SetNome(string _nome) { nome = _nome; }
	int GetIdade() const { return idade; }
	void SetIdade(int _idade) { idade = _idade; }
	int GetPontos() const { return pontos; }
	void SetPontos(int _pontos) { pontos = _pontos; }
	~Jogador();
};

