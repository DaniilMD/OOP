#ifndef GENERICPLAYER_H
#define GENERICPLAYER_H

#include "Hand.h"

class GenericPlayer : public Hand
{
protected:
	string m_Name;
public:
	GenericPlayer();
	GenericPlayer(string str);
	virtual bool IsHitting() const = 0;
	bool isBoosted() const;
	void Busted() const;
	friend ostream& operator<< (ostream &out, const GenericPlayer &gp);
	~GenericPlayer ();
};

#endif
