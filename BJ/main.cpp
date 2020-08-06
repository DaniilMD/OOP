#include <iostream>

using namespace std;

#include "Game.h"

int main()
{
	vector<string> players = {"Misha", "Sasha", "Kolya", "Artem", "Masha"};

	while (1)
	{
		Game game(players);
		game.play();
		cout << endl << endl << "Do you want to play another game?" << endl;

		string answ;
		getline(cin, answ);
		if (strcmp(answ.c_str(), "yes") == 0)
			continue ;
		else
			break ;
	}
	return 0;
}
