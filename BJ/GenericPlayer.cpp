#include "GenericPlayer.h"


GenericPlayer::GenericPlayer() : m_Name("Unknown") {}
GenericPlayer::GenericPlayer(string str)
{
	m_Name = str;
}
bool GenericPlayer::isBoosted() const
{
	if (GetTotal() > 21)
		return (true);
	else
		return (false);
}
void GenericPlayer::Busted() const
{
	cout << "Player " << m_Name << " is boosted!" << endl;
}
ostream& operator<< (ostream &out, const GenericPlayer &gp)
{
	out << "Name: " << gp.m_Name << endl << "Cards:" << endl;
	if (gp.m_Cards.size() == 0)
		out << "	No cards " << endl;
	else
	{
		for(int i = 0; i < (int)gp.m_Cards.size(); i++)
		{
			out << *(gp.m_Cards[i]);
		}
	}
	out << "Total points: " << gp.GetTotal() << endl << "-----------------" << endl;
	return (out);
}
GenericPlayer::~GenericPlayer ()
{
	m_Name.clear();
}
