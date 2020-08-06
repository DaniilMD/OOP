#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

/*
2. Создать собственный манипулятор endll для стандартного потока вывода, который выводит два перевода строки и сбрасывает буфер.
*/

ostream &endll(ostream &out)
{
	out << "\n\n";
	out << flush;
	return out;
}

/*
5. Написать перегрузку оператора вывода для класса Card.
Если карта перевернута рубашкой вверх (мы ее не видим),
	вывести ХХ, если мы ее видим, вывести масть и номинал карты.
Также для класса GenericPlayer написать перегрузку оператора вывода,
	который должен отображать имя игрока и его карты, а также общую сумму очков его карт.
*/

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
	Card() {}
	Card(enum e_suit suit, enum e_value value, bool side)
	{
		this->suit = suit;
		this->value = value;
		this->side = side;
	}
	void Flip()
	{
		if (side == true)
			side = false;
		else
			side = true;
	}
	int GetValue() const
	{
		return (value);
	}
	friend ostream& operator<< (ostream &out, const Card &card);
	~Card() { }
};

//
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
//

class Hand
{
protected:
	vector<Card*> m_Cards;
public:
	void Add(Card* pCard)
	{
		m_Cards.push_back(pCard);
	}

	void Clear()
	{
		m_Cards.clear();
	}
	int GetTotal() const
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
	~Hand()
	{
		m_Cards.clear();
	}
};

/*
Также для класса GenericPlayer написать перегрузку оператора вывода,
	который должен отображать имя игрока и его карты, а также общую сумму очков его карт.
*/

class GenericPlayer : public Hand
{
protected:
	string m_Name;
public:
	GenericPlayer() : m_Name("Unknown") {}
	GenericPlayer(string str) : m_Name(str) {}
	virtual bool isHitting() = 0;
	bool isBoosted() const
	{
		if (GetTotal() > 21)
			return (true);
		else
			return (false);
	}
	void Busted() const
	{
		cout << "Player " << m_Name << " is boosted!" << endl;
	}
	friend ostream& operator<< (ostream &out, const GenericPlayer &gp);
	~GenericPlayer ()
	{
		m_Name.clear();
	}
};

ostream& operator<< (ostream &out, const GenericPlayer &gp)
{
	out << "Name: " << gp.m_Name << " " << "Cards: ";
	if (gp.m_Cards.size() == 0)
		out << "No cards";
	else
	{
		for(int i = 0; i < (int)gp.m_Cards.size(); i++)
		{
			out << *(gp.m_Cards[i]);
		}
	}
	out << " Total points: " << gp.GetTotal() << endl;
	return (out);
}

/*
3. Реализовать класс Player, который наследует от класса GenericPlayer. У этого класса будет 4 метода:
	* virtual bool IsHitting() const - реализация чисто виртуальной функции базового класса.
	*	Метод спрашивает у пользователя, нужна ли ему еще одна карта и возвращает ответ пользователя в виде true или false.
	* void Win() const - выводит на экран имя игрока и сообщение, что он выиграл.
	* void Lose() const - выводит на экран имя игрока и сообщение, что он проиграл.
	* void Push() const - выводит на экран имя игрока и сообщение, что он сыграл вничью.
*/

class Player : public GenericPlayer
{
public:
	virtual bool IsHitting() const
	{
		cout << "Do you want to take another card? (print \"yes/no\")" << endl;
		string answ;
		getline(cin, answ);
		if (strcmp(answ.c_str(), "yes") == 0)
			return (true);
		else
			return (false);
	}
	void Win() const
	{
		cout << "Player " << m_Name << "wins!!!" << endl;
	}
	void Lose() const
	{
		cout << "Player " << m_Name << "loses!!!" << endl;
	}
	void Push() const
	{
		cout << "Player " << m_Name << "pushes!!!" << endl;
	}
};

/*
4. Реализовать класс House, который представляет дилера. Этот класс наследует от класса GenericPlayer. У него есть 2 метода:
	* virtual bool IsHitting() const - метод указывает, нужна ли дилеру еще одна карта. Если у дилера не больше 16 очков, то он берет еще одну карту.
	* void FlipFirstCard() - метод переворачивает первую карту дилера.
*/

class House : public GenericPlayer
{
public:
	virtual bool IsHitting() const
	{
		if (GetTotal() <= 16)
			return (true);
		else
			return (false);
	}
	void FlipFirstCard()
	{
		if (m_Cards.size() > 0)
			m_Cards[0]->Flip();
		else
			cout << "No cards in deck!" << endl;
	}
};

bool		inputIsInteger(string str)
{
	if (str.size() < 1)
		return (false);
	for(int i = 0; i < (int)str.size(); i++)
	{
		if (i == 0)
		{
			if (!isdigit(str[i]) && str[i] != '-')
				return  (false);
		}
		else if (!isdigit(str[i]))
			return  (false);
	}
	return (true);
}

int main()
{
	/*
	1. Создать программу, которая считывает целое число типа int.
	И поставить «защиту от дурака»: если пользователь вводит что-то кроме одного целочисленного значения,
	нужно вывести сообщение об ошибке и предложить ввести число еще раз.
	*/
	// Task 1
	cout << "Task 1" << endl;
	string str;
	while (1)
	{
		cout << "Enter an integer:" << endl;
		getline(cin, str);
		if (inputIsInteger(str) == true)
		{
			cout << "It IS an integer, good" << endl;
			break;
		}
		cout << "Incorrect input" << endl;
	}
	cout << endl;

	// Task 2
	cout << "Task 2" << endl;
	cout << "Some random text" << endll;
	cout << "Some more random text" << endll;
	cout << "Even more random text" << endll;
	return 0;
}
