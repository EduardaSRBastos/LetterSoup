#pragma once
#include "Ponto.h"
#include <iostream>
#include <string>

using namespace std;
class Palavra
{
private:
	string palavra;
	int orientacao; //1=vertical 0=horizontal
	bool estado; //true=visto false=não encontrado
	Ponto p;

public:
	Palavra(void);
	Palavra(string);
	Palavra(string, Ponto);
	~Palavra();
	string GetPalavra() const { return palavra; }
	void SetPalavra(string _palavra) { palavra = _palavra; }
	void SetPonto(Ponto _p) { p = _p; }
	Ponto GetPonto(void) const { return p; };
	void SetEstado(bool _estado) { estado=_estado; }
	bool GetEstado(void) const { return estado; }
	void SetOrientacao(int _orientacao) { orientacao = _orientacao; }
	int GetOrientacao(void) const { return orientacao; };
	void ShowPalavra(void);
	int LengthPalavra() { return palavra.length()-1; }
};

