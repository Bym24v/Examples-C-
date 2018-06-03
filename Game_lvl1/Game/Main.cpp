#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

int vida = 100;
int oro = 100;
int diamantes = 50;

int main() {

	SetConsoleTitle(TEXT("Game lvl 1"));

	system("cls");

	printf("Vida: %d\t Oro: %d\t Diamantes: %d\n", vida, oro, diamantes);

	string cli;
	
	cout << "\n1: Vida -25\n2: Oro - 10\n3: Diamantes - 15\n\n"; 
	cin >> cli;
	

	if (cli == "1")
	{
		printf("Vida - 25");
		vida -= 25;

		if (vida <= 0)
		{
			vida = 0;
		}
	}

	if (cli == "2")
	{
		printf("Oro - 10");
		oro -= 10;

		if (oro <= 0)
		{
			oro = 0;
		}
	}

	if (cli == "3")
	{
		printf("Diamantes - 15");
		diamantes -= 15;

		if (diamantes <= 0)
		{
			diamantes = 0;
		}
	}

	Sleep(300);

	main();
	return 0;
}