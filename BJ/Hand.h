#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include <vector>

class Hand
{
protected:
	vector<Card*> m_Cards;
public:
	void Add(Card* pCard);
	void Clear();
	int GetTotal() const;
	~Hand();
};

#endif
