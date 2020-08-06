#ifndef DECK_H
#define DECK_H

#include"Hand.h"
#include <algorithm>
#include "GenericPlayer.h"

class Deck : public Hand
{
public:
	Deck ();
	~Deck();

	void Populate();

	void Shuffle();

	void Deal (Hand& aHand);

	void AdditionalCards (GenericPlayer& aGenerlcPlayer);
};

#endif
