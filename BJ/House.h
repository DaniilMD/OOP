#ifndef HOUSE_H
#define HOUSE_H

#include "GenericPlayer.h"

class House : public GenericPlayer
{
public:
	House();
	virtual bool IsHitting() const override;
	void FlipFirstCard();
};


#endif
