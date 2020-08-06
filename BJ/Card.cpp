#include "Card.h"


Card::Card() {}
Card::Card(enum e_suit suit, enum e_value value, bool side)
{
	this->suit = suit;
	this->value = value;
	this->side = side;
}
void Card::Flip()
{
	if (side == true)
		side = false;
	else
		side = true;
}
int Card::GetValue() const
{
	if (side == true)
		return (value);
	else
		return (0);
}
ostream& operator<< (ostream &out, const Card &card)
{
	string suits[]{"hearts", "spades", "diamonds", "clubs"};
	string values[]{"ace", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "jack", "queen", "king"};

	if (card.side == false)
		out << "XX ";
	else
		out << "	Suit - " << suits[card.suit] << "	Value - " << values[card.value - 1] << endl;
	return (out);
}
Card::~Card() { }
