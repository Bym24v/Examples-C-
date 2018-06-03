#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

struct Player
{
	int vida;
	int oro;
	int diamantes;
};

Player *pl = new Player();
bool logic = true;

void init() {

	pl->vida = 100;
	pl->oro = 100;
	pl->diamantes = 50;
	
}

int main() {

	if (logic)
	{
		init();
		logic = false;
	}

	SetConsoleTitle(TEXT("Game lvl 2"));
	system("cls");

	printf("Vida: %d\t Oro: %d\t Diamantes: %d\n", pl->vida, pl->oro, pl->diamantes);

	string cli;

	cout << "\n1: Vida -10\n2: Oro - 10\n3: Diamantes - 15\n\n";
	cin >> cli;


	if (cli == "1")
	{
		printf("Vida - 10");
		pl->vida -= 10;

		if (pl->vida <= 0)
		{
			pl->vida = 0;
		}
	}

	if (cli == "2")
	{
		printf("Oro - 10");
		pl->oro -= 10;

		if (pl->oro <= 0)
		{
			pl->oro = 0;
		}
	}

	if (cli == "3")
	{
		printf("Diamantes - 15");
		pl->diamantes -= 15;

		if (pl->diamantes <= 0)
		{
			pl->diamantes = 0;
		}
	}

	Sleep(300);

	main();
	return 0;
}