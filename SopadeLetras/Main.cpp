#include <iostream>
#include "Function.h"
#include "Ponto.h"
#include "Letra.h"
#include "Palavra.h"
#include "Jogo.h"
#include "Tabuleiro.h"
#include "Jogador.h"
#include <time.h>
#include <fstream>
#include <string>
#include <locale>
#include <windows.h>
#include <algorithm>
#include <cstdio>
#include <ctime>
#include <iomanip>

using namespace std;
char tabuleiro[20][20];
string jog1="jog1";
int temas = 0;
int nivel = 1;
int verm = 0;

int main(void)
{
	setlocale(LC_ALL, "");
	srand(static_cast<unsigned int>(time(NULL)));
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ifstream is; // objecto is para abrir o ficheiro em modo de leitura INPUT
	ofstream os;
	Ponto inicio(2, 2), finalPrincipiante;
	finalPrincipiante.SetX(20); finalPrincipiante.SetY(20);
	tabuleiro[finalPrincipiante.GetX()][finalPrincipiante.GetY()];
	Letra l('A');
	Palavra palavra("");
	Palavra list[10];
	char tema[10] = "";
	char palavras[14] = "";
	string nome="";
	string letras[10];
	string resultado = "";
	string lista[10];
	locale loc;
	string tem = "";
	Ponto local(0, 0);
	clock_t iniciar;
	double duracao=0;

	menu(&jog1,&temas,&nivel,&verm);
	//verificar erros a abrir o ficheiro
	
	if (verm == 1)
	{
		is.open("palavras.tex");
		if (!is) {
			cout << "ERRO: não é possível abrir o ficheiro palavras.tex" << '\n';
			system("pause");
			exit(1);
		}
		//tabuleiro com letras random
		for (int i = 0; i < finalPrincipiante.GetX(); i++)
		{
			for (int j = 0; j < finalPrincipiante.GetY(); j++)
			{
				l.SetLetra('A' + rand() % 26);
				tabuleiro[i][j] = { l.GetLetra() };
			}
		}

		int nr = 0;
		do
		{
			//tema
			is.getline(tema, sizeof(tema), ':');
			palavra.SetPalavra(tema);
			tem = palavra.GetPalavra();
			tem.erase(remove(tem.begin(), tem.end(), '\n'), tem.end());
			//palavras
			for (int a = 0; a < 9; a++)
			{
				is.getline(palavras, sizeof(palavras), ',');
				palavra.SetPalavra(palavras);
				letras[a] = palavra.GetPalavra();
			}
			is.getline(palavras, sizeof(palavras), '.');
			palavra.SetPalavra(palavras);
			letras[9] = palavra.GetPalavra();
			nr++;
		} while (nr != temas);
		is.close();

		int x[10], y[10], total, total2;

		//inserir as palavras na matriz
		for (int a = 0; a < 10; a++)
		{
			bool flag = true;
			do
			{
				flag = false;
				x[a] = rand() % finalPrincipiante.GetX();
				total = x[a] + letras[a].length();
				y[a] = rand() % finalPrincipiante.GetY();
				total2 = y[a] + letras[a].length();

				/*for (int r = 0; r < 10; r++)
				{
					for (size_t d = 1; d < letras[r].length(); d++)
					{
						if (a % 2 == 0)
						{
							for (size_t d = 1; d < letras[r].length(); d++)
							{
								if ((x[r]) == (x[a]) && (y[r] + d) == (y[a]))
									flag = true;
							}
						}
						else
						{
							for (size_t d = 1; d < letras[r].length(); d++)
							{
								if ((x[r] + d) == (x[a]) && (y[r]) == (y[a]))
									flag = true;
							}
						}
					}
				}*/
			} while (total >= finalPrincipiante.GetX() || total2 >= finalPrincipiante.GetY() || flag == true);

			if (a % 2 == 0)
			{
				for (size_t p = 1; p < letras[a].length(); p++)
				{
					tabuleiro[y[a] + p][x[a]] = letras[a][p];
					list[a].SetPalavra(letras[a]);
					list[a].SetOrientacao(1);
					local.SetX(x[a] + p);
					local.SetY(y[a]);
					list[a].SetPonto(local);
				}
			}
			else
			{
				for (size_t p = 1; p < letras[a].length(); p++)
				{
					tabuleiro[y[a]][x[a] + p] = letras[a][p];
					list[a].SetPalavra(letras[a]);
					list[a].SetOrientacao(0);
					local.SetX(x[a]);
					local.SetY(y[a] + p);
					list[a].SetPonto(local);
				}
			}
		}
		//anular espaco antes das palavras
		for (int s = 0; s < 10; s++)
		{
			x[s]++;
		}
		//imprimir tema e tabuleiro
		SetConsoleTextAttribute(hConsole, 6);
		cout << endl << "             Tema: " << tem << endl;
		SetConsoleTextAttribute(hConsole, 15);

		for (int i = 0; i < finalPrincipiante.GetX(); i++)
		{
			cout << "  " << tabuleiro[i][0] << " ";

			for (int j = 1; j < finalPrincipiante.GetY(); j++)
			{
				cout << tabuleiro[i][j] << " ";
			}
			cout << endl;
		}

		cout << endl;
		//lista de palavras encontradas
		for (int k = 0; k < 10; k++)
		{
			letras[k].erase(remove(letras[k].begin(), letras[k].end(), ' '), letras[k].end());
		}

		gotoxy(50, 1);
		SetConsoleTextAttribute(hConsole, 11);
		cout << "Lista:";
		SetConsoleTextAttribute(hConsole, 15);
		gotoxy(0, 23);

		//predefinir nome jog1
		int check = 0, t = 0;
		while (jog1[t])
		{
			if (check == 0)
			{
				jog1[t] = toupper(jog1[t], loc);
				check = 1;
			}
			else if (isspace(jog1[t]))
				check = 0;
			t++;
		}
		if (nivel == 1)
			cout << endl << "Bem-vindo " << jog1 << ", nível Jogador Principiante." << endl;
		else if (nivel == 2)
			cout << endl << "Bem-vindo " << jog1 << ", nível Jogador Experiente." << endl;
		cout << "Se desejar iniciar um novo jogo, insira a palavra 'SAIR'." << endl;
		cout << "Se desejar guardar o jogo, insira a palavra 'GUARDAR'." << endl;
		iniciar = clock();
		//verificar palavras
		int i = 0, j = 0;
		if (nivel == 1)
		{
			for (int k = 0; k < 10; k++)
			{
				gotoxy(50, 3 + k);
				lista[k] = letras[k];
				cout << lista[k];
			}
			gotoxy(0, 27);
		}
		do
		{
			bool flag = false;
			bool ver = false;
			cout << endl << "Insira a palavra encontrada: ";
			cin >> resultado;
			for (size_t c = 0; c < resultado.length(); c++)
			{
				resultado[c] = toupper(resultado[c], loc);
			}
			if (resultado == "SAIR")
			{
				printf("\nA sair...\n");
				Sleep(1200);
				exit(0);
			}
			if (resultado == "GUARDAR")
			{
				os.open("guardado.tex");
				if (!os) {
					cout << "ERRO: não é possível abrir o ficheiro guardado.tex" << '\n';
					system("pause");
					exit(1);
				}
				duracao = (clock() - iniciar) / (double)CLOCKS_PER_SEC;
				//nome jog, num tema, num nivel, num duracao
				os << jog1 << "," << temas << "," << nivel << "," << duracao << "," << endl;

				for (int i = 0; i < finalPrincipiante.GetX(); i++)
				{
					os << "  " << tabuleiro[i][0] << " ";

					for (int j = 1; j < finalPrincipiante.GetY(); j++)
					{
						os << tabuleiro[i][j] << " ";
					}
					os << endl;
				}

				for (int k = 0; k < 10; k++)
				{
					if (list[k].GetEstado() == true)
						os << endl << lista[k];
				}
				os.close();

				printf("\nA guardar e sair...\n");
				Sleep(1200);
				exit(0);
			}
			int g = 0;
			for (int k = 0; k < 10; k++)
			{
				if (resultado == letras[k])
				{
					if (list[k].GetEstado() == true)
						ver = true;
					lista[k] = letras[k];
					list[k].SetEstado(true);
					flag = true;
					gotoxy(50, 3 + k);

					SetConsoleTextAttribute(hConsole, 12);
					cout << lista[k];
					SetConsoleTextAttribute(hConsole, 15);
					for (size_t z = 0; z < letras[k].length(); z++)
					{
						if (list[k].GetOrientacao() == 0)
						{
							gotoxy((x[k] * 2) + g + 2, 2 + y[k]);
							SetConsoleTextAttribute(hConsole, 12);
							cout << lista[k][z];
							SetConsoleTextAttribute(hConsole, 15);
							g += 2;
						}
						else if (list[k].GetOrientacao() == 1)
						{
							gotoxy(x[k] * 2, (y[k] + 3) + g);
							SetConsoleTextAttribute(hConsole, 12);
							cout << lista[k][z];
							SetConsoleTextAttribute(hConsole, 15);
							g++;
						}
						else
							cout << "Erro a obter a orientação da palavra." << endl;

					}
				}
			}
			gotoxy(0, 29 + i);
			if (flag)
			{
				if (ver)
				{
					cout << "A palavra já foi encontrada.\n";
					j++;
				}
				else
					cout << "Certo\n";
			}
			else
				cout << "A palavra não existe na sopa de letras.\n";
			i = i + 3;
		} while (j != 10);
		SetConsoleTextAttribute(hConsole, 12);
		cout << endl << "Parabéns! Encontrou as palavras todas." << endl;
		SetConsoleTextAttribute(hConsole, 15);
		Sleep(1500);
		duracao = (clock() - iniciar) / (double)CLOCKS_PER_SEC;
		cout.setf(ios::fixed, ios::floatfield);
		cout.precision(3);
		cout << "Tempo: " << duracao << "s.\n";
		if (nivel == 2)
		{
			int tem = 0;
			double dur = 0, aux = duracao;
			string nomed = "";
			os.open("recordes.tex", ios_base::app);
			if (!os) {
				cout << "ERRO: não é possível abrir o ficheiro recordes.tex" << '\n';
				system("pause");
				exit(1);
			}
			//nome jog, num tema, num duracao
			os << jog1 << " " << temas << " " << duracao << endl;
			os.close();

			is.open("recordes.tex");
			if (!is) {
				cout << "ERRO: não é possível abrir o ficheiro recordes.tex" << '\n';
				system("pause");
				exit(1);
			}
			do
			{
				is >> nomed >> tem >> dur;
				if (aux > dur)
					aux = dur;
			} while (!is.eof());

			if (duracao <= aux && tem == temas)
			{
				SetConsoleTextAttribute(hConsole, 12);
				cout << "Parabéns. Novo recorde para este tema!\n";
				SetConsoleTextAttribute(hConsole, 15);
			}
			is.close();
		}
	}

	if (verm == 2)
	{
		is.open("guardado.tex");
		if (!is) {
			cout << "ERRO: não é possível abrir o ficheiro palavras.tex" << '\n';
			system("pause");
			exit(1);
		}
		//imprimir tema e tabuleiro
		char jog[40];
		is.getline(jog, sizeof(jog), ',');
		palavra.SetPalavra(jog);
		jog1 = palavra.GetPalavra();

		is.getline(tema, sizeof(tema), ',');
		palavra.SetPalavra(tema);
		tem = palavra.GetPalavra();

		if (tem == "1")
			tem = "Animais";
		else if (tem == "2")
			tem = "Frutas";
		else if (tem == "3")
			tem = "Países";
		else if (tem == "4")
			tem = "Cores";
		else if (tem == "5")
			tem = "Empregos";
		else
			cout << "Erro a obter tema.\n";

		SetConsoleTextAttribute(hConsole, 6);
		cout << endl << "             Tema: " << tem << endl;
		SetConsoleTextAttribute(hConsole, 15);
		char nive[10];
		is.getline(nive, sizeof(nive), ',');
		if (*nive == '1')
			nivel = 1;
		else if (*nive == '2')
			nivel = 2;
		else
			cout << "Erro a obter o nivel.\n";

		char ini[10];
		is.getline(ini, sizeof(ini), ',');
		const char *str = ini;
		float in = atof(ini);
		iniciar = clock();

		char tabela[20][20];
		for (int t = 0; t < 20; t++)
		{
			for (int g = 0; g < 20; g++)
			{
				is>>tabela[t][g];
				cout << tabela[t][g] << " ";
			}
			cout << endl;
		}
		
		is.close();
		cout << endl;
		gotoxy(50, 1);
		SetConsoleTextAttribute(hConsole, 11);
		cout << "Lista:";
		SetConsoleTextAttribute(hConsole, 15);
		gotoxy(0, 23);
		
		if (nivel == 1)
			cout << endl << "Bem-vindo de volta, " << jog1 << ", nível Jogador Principiante." << endl;
		else if (nivel == 2)
			cout << endl << "Bem-vindo de volta, " << jog1 << ", nível Jogador Experiente." << endl;
		cout << "Se desejar iniciar um novo jogo, insira a palavra 'SAIR'." << endl;
		cout << "Se desejar guardar o jogo, insira a palavra 'GUARDAR'." << endl;
		
		is.open("palavras.tex");
		if (!is) {
			cout << "ERRO: não é possível abrir o ficheiro palavras.tex" << '\n';
			system("pause");
			exit(1);
		}
		
		int nr = 0;
		int n = stoi(tema);
		
		do
		{
			//tema
			is.getline(tema, sizeof(tema), ':');
			palavra.SetPalavra(tema);
			tem = palavra.GetPalavra();
			tem.erase(remove(tem.begin(), tem.end(), '\n'), tem.end());
			//palavras
			for (int a = 0; a < 9; a++)
			{
				is.getline(palavras, sizeof(palavras), ',');
				palavra.SetPalavra(palavras);
				letras[a] = palavra.GetPalavra();
			}
			is.getline(palavras, sizeof(palavras), '.');
			palavra.SetPalavra(palavras);
			letras[9] = palavra.GetPalavra();
			nr++;
			
		} while (nr != n);
		
		is.close();

		//verificar palavras
		int i = 0, j = 0;
		if (nivel == 1)
		{
			for (int k = 0; k < 10; k++)
			{
				gotoxy(50, 3 + k);
				letras[k].erase(remove(letras[k].begin(), letras[k].end(), ' '), letras[k].end());
				cout << letras[k];
			}
			gotoxy(0, 27);
		}
		for (int k = 0; k < 10; k++)
		{
			letras[k].erase(remove(letras[k].begin(), letras[k].end(), ' '), letras[k].end());
		}
		int x[10], y[10];
		//anular espaco antes das palavras
		for (int s = 0; s < 10; s++)
		{
			x[s]++;
		}
		do
		{
			bool flag = false;
			bool ver = false;
			cout << endl << "Insira a palavra encontrada: ";
			cin >> resultado;
			for (size_t c = 0; c < resultado.length(); c++)
			{
				resultado[c] = toupper(resultado[c], loc);
			}
			if (resultado == "SAIR")
			{
				printf("\nA sair...\n");
				Sleep(1200);
				exit(0);
			}
			if (resultado == "GUARDAR")
			{
				os.open("guardado.tex");
				if (!os) {
					cout << "ERRO: não é possível abrir o ficheiro guardado.tex" << '\n';
					system("pause");
					exit(1);
				}
				duracao = (clock() - (iniciar+in)) / (double)CLOCKS_PER_SEC;
				//nome jog, num tema, num nivel, num duracao
				os << jog1 << "," << temas << "," << nivel << "," << duracao << "," << endl;

				for (int i = 0; i < finalPrincipiante.GetX(); i++)
				{
					os << "  " << tabuleiro[i][0] << " ";

					for (int j = 1; j < finalPrincipiante.GetY(); j++)
					{
						os << tabuleiro[i][j] << " ";
					}
					os << endl;
				}

				for (int k = 0; k < 10; k++)
				{
					if (list[k].GetEstado() == true)
						os << endl << lista[k];
				}
				os.close();

				printf("\nA guardar e sair...\n");
				Sleep(1200);
				exit(0);
			}

			int g = 0;
			
			for (int k = 0; k < 10; k++)
			{
				if (resultado == letras[k])
				{
					if (list[k].GetEstado() == true)
						ver = true;
					lista[k] = letras[k];
					list[k].SetEstado(true);
					flag = true;
					gotoxy(50, 3 + k);

					SetConsoleTextAttribute(hConsole, 12);
					cout << lista[k];
					SetConsoleTextAttribute(hConsole, 15);
					for (size_t z = 0; z < letras[k].length(); z++)
					{
						if (k % 2 != 0)
						{
							gotoxy((x[k] * 2) + g + 2, 2 + y[k]);
							SetConsoleTextAttribute(hConsole, 12);
							cout << lista[k][z];
							SetConsoleTextAttribute(hConsole, 15);
							g += 2;
						}
						else if (k % 2 == 0)
						{
							gotoxy(x[k] * 2, (y[k] + 3) + g);
							SetConsoleTextAttribute(hConsole, 12);
							cout << lista[k][z];
							SetConsoleTextAttribute(hConsole, 15);
							g++;
						}
						else
							cout << "Erro a obter a orientação da palavra." << endl;

					}
				}
			}
			gotoxy(0, 29 + i);
			if (flag)
			{
				if (ver)
				{
					cout << "A palavra já foi encontrada.\n";
					j++;
				}
				else
					cout << "Certo\n";
			}
			else
				cout << "A palavra não existe na sopa de letras.\n";
			i = i + 3;
		} while (j != 10);

		SetConsoleTextAttribute(hConsole, 12);
		cout << endl << "Parabéns! Encontrou as palavras todas." << endl;
		SetConsoleTextAttribute(hConsole, 15);
		Sleep(1500);
		duracao = (clock() - (iniciar+in)) / (double)CLOCKS_PER_SEC;
		cout.setf(ios::fixed, ios::floatfield);
		cout.precision(3);
		cout << "Tempo: " << duracao << "s.\n";
		if (nivel == 2)
		{
			int tem = 0;
			double dur = 0, aux = duracao;
			string nomed = "";
			os.open("recordes.tex", ios_base::app);
			if (!os) {
				cout << "ERRO: não é possível abrir o ficheiro recordes.tex" << '\n';
				system("pause");
				exit(1);
			}
			//nome jog, num tema, num duracao
			os << jog1 << ", " << temas << " " << duracao << endl;
			os.close();

			is.open("recordes.tex");
			if (!is) {
				cout << "ERRO: não é possível abrir o ficheiro recordes.tex" << '\n';
				system("pause");
				exit(1);
			}
			do
			{
				is >> nomed >> tem >> dur;
				if (aux > dur)
					aux = dur;
			} while (!is.eof());

			if (duracao <= aux && tem == temas)
			{
				SetConsoleTextAttribute(hConsole, 12);
				cout << "Parabéns. Novo recorde para este tema!\n";
				SetConsoleTextAttribute(hConsole, 15);
			}
			is.close();
		}
	}
	system("pause");
	return 0;
}