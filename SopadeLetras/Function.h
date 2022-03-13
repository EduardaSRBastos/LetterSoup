#pragma once
#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <limits>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <ctime>
#include <iomanip>

using namespace std;

void menu(string *jog1,int *temas,int *nivel, int *verm)
{
	system("MODE con cols=156 lines=120");
	system("title Sopa de Letras v1.0");
	setlocale(LC_ALL, "");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 4);  	printf("    S ");	SetConsoleTextAttribute(hConsole, 6);	printf(" o ");	SetConsoleTextAttribute(hConsole, 3);	printf(" p ");
	SetConsoleTextAttribute(hConsole, 2);	printf(" a  ");	SetConsoleTextAttribute(hConsole, 7);	printf("  d ");	SetConsoleTextAttribute(hConsole, 4);	printf(" e  ");
	SetConsoleTextAttribute(hConsole, 4);  	printf("  L ");	SetConsoleTextAttribute(hConsole, 6);	printf(" e ");	SetConsoleTextAttribute(hConsole, 3);	printf(" t ");
	SetConsoleTextAttribute(hConsole, 2);	printf(" r ");	SetConsoleTextAttribute(hConsole, 7);	printf(" a ");	SetConsoleTextAttribute(hConsole, 4);	printf(" s \n\n\n");
	SetConsoleTextAttribute(hConsole, 15);

	printf(" Criado por: 70647- Eduarda Bastos | 70650- Rui Duarte\n\n");
	printf("Clique em alguma tecla para continuar...");
	_getch();

	char escolha[5], ver,tem[5],niv[5];

	printf("\n\nSelecione uma das opções: \n");
	do
	{
		printf("\nA. Começar novo jogo.\n");
		printf("B. Carregar último jogo.\n");
		printf("C. Recorde.\n");
		printf("D. Sair da aplicação.\n");
		cin >> escolha;

		if ((strlen(escolha) != 1))
		{
			escolha[0] = 'e';
		}
		ver = toupper(escolha[0]);
		if ((ver != 'A') && (ver != 'B') && (ver != 'C') && (ver != 'D'))
		{
			printf("Inseriu um valor errado.\n\n");
		}
		if (ver == 'C')
		{
			int tem = 0;
			double dur = 0;
			char nomed[20];
			string nom="";
			string temat = "";
			ifstream is;
			is.open("recordes.tex");
			if (!is) {
				cout << "ERRO: não é possível abrir o ficheiro recordes.tex" << '\n';
				system("pause");
				exit(1);
			}
			while (!is.eof())
			{
				is.getline(nomed, sizeof(nomed), ',');
				is >> tem >> dur;
				nom = nomed;
				nom.erase(remove(nom.begin(), nom.end(), '\n'), nom.end());
				temat = tem;
				if (tem == 1)
					temat = "Animais";
				else if (tem == 2)
					temat = "Frutas";
				else if (tem == 3)
					temat = "Países";
				else if (tem == 4)
					temat = "Cores";
				else if (tem == 5)
					temat = "Empregos";
				else
					cout << "Erro a obter tema.\n";
				cout << " Nome: " << nom << ", tema: " << temat << ", tempo: " << dur <<"s." << endl;
			}
			is.close();
			Sleep(1500);
		}
	} while (ver != 'A' && (ver != 'B') && (ver == 'C' || ver != 'C') && ver != 'D');
	if (ver == 'A')
	{
		*verm = 1;
		//Inserir o nome do jogador
		cout<<("\nInsira o nome do jogador: ");
		getline(cin.ignore(), *jog1);
		cout << "\Escolha o nível do jogador: (Insira a letra correspondente)" << endl;
		do
		{
			cout << "\nA- Principiante\nB- Experiente\n";
			cin >> niv;
			if ((strlen(niv) != 1))
			{
				niv[0] = 'e';
			}
			niv[0] = toupper(niv[0]);
			if (niv[0] != 'A' && niv[0] != 'B')
				cout << "\nInseriu um valor errado. Deve inserir a letra correspondente ao nível desejado.\n";
		} while (niv[0] != 'A' && niv[0] != 'B');

		switch (niv[0])
		{
		case 'A':
		{
			*nivel = 1;
			break;
		}
		case 'B':
		{
			*nivel = 2;
			break;
		}
		default:
			cout << "Erro switch.\n";
			break;
		}

		cout << "\nEscolha o tema: (Insira a letra correspondente)" << endl;
		do
		{
			cout << "\nA- Animais\nB- Frutas\nC- Países\nD- Cores\nE- Empregos\n";
			cin >> tem;
			if ((strlen(tem) != 1))
			{
				tem[0] = 'r';
			}
			tem[0] = toupper(tem[0]);
		
			if (tem[0] != 'A' && tem[0] != 'B' && tem[0] != 'C' && tem[0] != 'D' && tem[0] != 'E')
				cout << "\nInseriu um valor errado. Deve inserir a letra correspondente ao tema desejado.\n";
		} while (tem[0] != 'A' && tem[0] != 'B' && tem[0] != 'C' && tem[0] != 'D' && tem[0] != 'E');

		switch (tem[0])
		{
			case 'A':
				{
				*temas = 1;
				break;
				}
			case 'B':
				{
				*temas = 2;
				break;
				}
			case 'C':
				{
				*temas = 3;
				break;
				}
			case 'D':
				{
				*temas = 4;
				break;
				}
			case 'E':
				{
				*temas = 5;
				break;
				}
			default:
				cout << "Erro switch.\n";
				break;
		}
		printf("\nA iniciar...\n");
		Sleep(1200);
		system("cls");
	}
	if (ver == 'B')
	{
		*verm = 2;
		ifstream is;
		char cstr[40];
		is.open("guardado.tex");
		if (!is) {
			cout << "ERRO: não é possível abrir o ficheiro recordes.tex" << '\n';
			system("pause");
			exit(1);
		}
		is.getline(cstr, sizeof(cstr), ',');
		*jog1 = cstr;
		cout << "Bem-vindo de volta, " << *jog1 << endl;
		is.close();

		printf("\nA iniciar...\n");
		Sleep(1200);
		system("cls");
	}
	if (ver == 'D')
	{
		printf("A sair...");
		Sleep(1200);
		exit(0);
	}
}
void gotoxy(int x, int y)
{
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
