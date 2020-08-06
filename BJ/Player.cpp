#include "Player.h"


Player::Player(string name)
{
	m_Name = name;
}
bool Player::IsHitting() const
{
	cout << "Player " << m_Name << ", do you want to take another card? (print \"yes/no\")" << endl;
	string answ;
	getline(cin, answ);
	if (strcmp(answ.c_str(), "yes") == 0)
		return (true);
	else
		return (false);
}
void Player::Win() const
{
	cout << "Player " << m_Name << " wins!!!" << endl;
}
void Player::Lose() const
{
	cout << "Player " << m_Name << " loses!!!" << endl;
}
void Player::Push() const
{
	cout << "Player " << m_Name << " pushes!!!" << endl;
}
