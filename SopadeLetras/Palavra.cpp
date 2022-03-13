#include "Palavra.h"
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

Palavra::Palavra(void)
{
}

Palavra::Palavra(string _palavra)
{
	palavra = _palavra;
}

Palavra::Palavra(string _palavra, Ponto _p)
{
	palavra = _palavra;
	p = _p;
}

Palavra::~Palavra()
{
}

void Palavra::ShowPalavra(void)
{
	cout << endl << " Palavra: " << GetPalavra() << endl;
}
