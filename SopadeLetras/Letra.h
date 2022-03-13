#pragma once
#include "Ponto.h"
class Letra
{
private:
	char letra;
	Ponto p;
	int codigoAscii;
	int tipo; //Maiuscula=1, Minuscula=0
public:
	Letra();
	Letra(char);
	~Letra();
	char GetLetra() const { return letra; }
	void SetLetra(int l) { letra = l; }
	void SetPonto(Ponto _p) { p = _p; }
	void SetCodigo(int c) { codigoAscii = c; }
	void SetTipo(int t) { tipo = t; }
	void Show(void);
};

