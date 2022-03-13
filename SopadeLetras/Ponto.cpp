#include "Ponto.h"
#include <iostream>

using namespace std;

Ponto::Ponto()
{
	x = 0;
	y = 0;
}

Ponto::~Ponto()
{
}

Ponto::Ponto(int mx, int my)
{
	x = mx;
	y = my;
}

bool Ponto::SetX(int mx)
{
	if (mx >= 0) {
		x = mx;
		return true;
	}
	else
		return false;
}

bool Ponto::SetY(int my)
{
	if (my >= 0) {
		y = my;
		return true;
	}
	else
		return false;
}

bool Ponto::IsValid()
{
	if ((x >= 0) && (y>=0))
		return true;
	else
		return false;
}

bool Ponto::Ask2Set()
{
	cout << "Insira o valor de 'X':";
	cin >> x;
	cout << "Insira o valor de 'Y':";
	cin >> y;

	return IsValid();
}

void Ponto::Show()
{
	cout << endl << "X = " << GetX() << endl;
	cout << "Y = " << GetY() << endl;
}

bool Ponto:: operator == (const Ponto P) const
{
	if ((this->GetX() == P.GetX()) && (this->GetY() == P.GetY()))
		return true;
	else
		return false;
}