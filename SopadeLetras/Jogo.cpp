#include "Jogo.h"



Jogo::Jogo()
{
}

Jogo::Jogo(int x, int y)
{
	jogador.SetPontos(0);
	jogo.Inicio(x, y);
}

void Jogo::Iniciar()
{
	int a = 10;
	while (a > 0)
	{
		cout << a-- << "  -----------------" << endl << endl;
		Jogar();
	}
}

int Jogo::Jogar()
{
	jogo.Ver();
	return 0;
}


Jogo::~Jogo()
{
}
