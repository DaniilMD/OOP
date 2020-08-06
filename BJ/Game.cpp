#include "Game.h"


// Конструктор класса принимает в качестве параметра вектор имен игроков и создает объекты самих игроков.
Game::Game(vector<string> &player_names)
{
	for(int i = 0; i < (int)player_names.size(); i++)
	{
		m_Players.push_back(Player(player_names[i]));
	}
	m_Deck.Populate();
	srand(time(0));
	m_Deck.Shuffle();
}

// Также класс имеет один метод play().
void Game::play()
{
	// В этом методе раздаются каждому игроку по две стартовые карты,
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < (int)m_Players.size(); j++)
		{
			m_Deck.Deal(m_Players[j]);
		}
		m_Deck.Deal(m_House);
	}

	// а первая карта дилера прячется.
	m_House.FlipFirstCard();

	// Далее выводится на экран информация о картах каждого игра, в т.ч. и для дилера.
	for (int i = 0; i < (int)m_Players.size(); i++)
	{
		cout << m_Players[i] << endl;
	}
	cout << m_House << endl;

	// Затем раздаются игрокам дополнительные карты.
	for (int i = 0; i < (int)m_Players.size(); i++)
	{
		m_Deck.AdditionalCards(m_Players[i]);
	}

	// Потом показывается первая карта дилера и дилер набирает карты, если ему надо.
	m_House.FlipFirstCard();
	cout << m_House;
	m_Deck.AdditionalCards(m_House);

	// После этого выводится сообщение, кто победил, а кто проиграл.
	if (m_House.isBoosted())
	{
		cout << "House is busted" << endl;
		for (int i = 0; i < (int)m_Players.size(); i++)
		{
			if (!(m_Players[i].isBoosted()))
			{
				m_Players[i].Win();
			}
		}
	}
	else
	{
		cout << "House is not busted" << endl;
		for (int i = 0; i < (int)m_Players.size(); i++)
		{
			if (!(m_Players[i].isBoosted()))
			{
				if (m_Players[i].GetTotal() > m_House.GetTotal())
				{
					m_Players[i].Win();
				}
				else if (m_Players[i].GetTotal() < m_House.GetTotal())
				{
					m_Players[i].Lose();
				}
				else
				{
					m_Players[i].Push();
				}
			}
		}
	}

	//В конце руки всех игроков очищаются.
	for (int i = 0; i < (int)m_Players.size(); i++)
	{
		m_Players[i].Clear();
	}
	m_House.Clear();
}
Game::~Game() {}
