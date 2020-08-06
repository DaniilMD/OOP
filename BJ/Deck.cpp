#include "Deck.h"


Deck::Deck () {}
Deck::~Deck() {}

void Deck::Populate()
{
	Clear();
	for (int i = hearts; i <= clubs; i++)
	{
		for (int j = ace; j <= king; j++)
		{
			Add(new Card((enum e_suit)i, (enum e_value)j, true));
		}
	}
}

void Deck::Shuffle()
{
	random_shuffle(m_Cards.begin(), m_Cards.end());
}

void Deck::Deal (Hand& aHand)
{
	if (m_Cards.size() <= 0)
	{
		cout << "Deck is empty" << endl;
		return ;
	}
	aHand.Add(m_Cards.back());
	(m_Cards.pop_back());
}

void Deck::AdditionalCards (GenericPlayer& aGenerlcPlayer)
{
	if (aGenerlcPlayer.isBoosted())
	{
		aGenerlcPlayer.Busted();
		return ;
	}
	while (aGenerlcPlayer.IsHitting())
	{
		Deal(aGenerlcPlayer);
	}
}

