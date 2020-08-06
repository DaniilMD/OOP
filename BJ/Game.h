#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include "Deck.h"
#include "Player.h"
#include "House.h"
#include <time.h>

class Game
{
private:
	Deck			m_Deck;
	House			m_House;
	vector<Player>	m_Players;
public:
	// Конструктор класса принимает в качестве параметра вектор имен игроков и создает объекты самих игроков.
	Game(vector<string> &player_names);

	// Также класс имеет один метод play().
	void play();
	~Game();
};

#endif
