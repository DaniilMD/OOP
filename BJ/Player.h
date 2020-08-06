#ifndef PLAYER_H
#define PLAYER_H

#include "GenericPlayer.h"
#include <string.h>

class Player : public GenericPlayer
{
public:
	Player(string name);
	virtual bool IsHitting() const override;
	void Win() const;
	void Lose() const;
	void Push() const;
};

#endif
