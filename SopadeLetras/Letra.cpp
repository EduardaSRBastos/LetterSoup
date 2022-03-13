#include "Letra.h"
#include <iostream>
using namespace std;
Letra::Letra()
{
	letra = 'A';
	p.SetX(0);
	p.SetY(0);
	codigoAscii = 65;
	tipo = 1;
}

Letra::Letra(char l)
{
	letra = l;
}

Letra::~Letra()
{
}

void Letra::Show(void)
{
	cout << endl << "Letra = " << GetLetra() << endl;
}
