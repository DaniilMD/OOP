#include "House.h"

House::House()
{
	m_Name = "House";
}
bool House::IsHitting() const
{
	if (GetTotal() <= 16)
		return (true);
	else
		return (false);
}
void House::FlipFirstCard()
{
	if (m_Cards.size() > 0)
		m_Cards[0]->Flip();
	else
		cout << "No cards in deck!" << endl;
}
