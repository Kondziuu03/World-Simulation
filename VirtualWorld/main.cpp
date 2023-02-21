#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "World.h"

using namespace std;

int main() {
	srand(time(NULL));
	
	int height, width;
	char command;

	cout << "Autor: Konrad Kolka 180440" << endl << endl;
	cout << "Podaj wymiary swiata: ";
	cin >> height >> width;
	cout << endl;
	World world(height, width);
	world.GenerateOrganisms();

	world.DrawWorld();
	while (true) {
		cout << "t - next turn ||| s - save world  ||| l - load world" << endl;
		cin >> command;
		system("cls");
		world.DrawWorld();
		cout << endl;
		if (command == 't') {
			world.NextTurn();
			cout << endl;
			world.DrawWorld();
			continue;
		}
		else if (command == 's') world.SaveWorld();
		else if (command == 'l') {
			system("cls");
			world.LoadWorld();
			world.DrawWorld();
			continue;
		}
		else break;
	}

	return 0;
}