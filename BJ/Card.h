#ifndef CARD_H
#define CARD_H
#include <iostream>

using namespace std;

enum e_suit {hearts, spades, diamonds, clubs};
enum e_value {ace = 1, two, three, four, five, six, seven,
	eight, nine, ten, jack, queen, king};

class Card
{
private:
	enum e_suit suit;
	enum e_value value;
	bool side;
public:
	Card() ;
	Card(enum e_suit suit, enum e_value value, bool side);
	void Flip();
	int GetValue() const;
	friend ostream& operator<< (ostream &out, const Card &card);
	~Card();
};


#endif
