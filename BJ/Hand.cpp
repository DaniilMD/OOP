#include "Hand.h"


void Hand::Add(Card* pCard)
{
	m_Cards.push_back(pCard);
}

void Hand::Clear()
{
	m_Cards.clear();
}
int Hand::GetTotal() const
{
	int sum = 0;
	int aces = 0;

	for (unsigned int i = 0; i < m_Cards.size(); i++)
	{
		int value = m_Cards[i]->GetValue();

		if (value >= two && value <= nine)
			sum += value;
		else if (value >= jack && value <= king)
			sum += 10;
		else if (value == ace)
		{
			aces++;
			sum += 1;
		}
	}
	if (sum + aces * 10 <= 21)
		sum += aces * 10;
	return  (sum);
}
Hand::~Hand()
{
	m_Cards.clear();
}
