#include <iostream>
#include <cassert>
#include <vector>
#include <math.h>

using namespace std;

/*
1. Добавить в контейнерный класс, который был написан в этом уроке, методы:
для добавления нового элемента в произвольное место
для добавления нового элемента на последнее место
для удаления последнего элемента массива (аналог функции pop_back() в векторах)
для сортировки массива.
*/

class ArrayInt
{
private:
	int m_length;
	int *m_data;

public:
	ArrayInt(): m_length(0), m_data(nullptr)
	{ }

	ArrayInt(int length):
	m_length(length)
	{
		assert(length >= 0);

		if (length > 0)
			m_data = new int[length];
		else
			m_data = nullptr;
	}

	~ArrayInt()
	{
		delete[] m_data;
	}
	void erase()
	{
		delete[] m_data;

		m_data = nullptr;
		m_length = 0;
	}
	int getLength() { return m_length; }
	int& operator[](int index)
	{
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}
	void resize(int newLength)
	{
		if (newLength == m_length)
			return;

		if (newLength <= 0)
		{
			erase();
			return;
		}

		int *data = new int[newLength];

		if (m_length > 0)
		{
			int elementsToCopy = (newLength > m_length) ? m_length : newLength;

			for (int index=0; index < elementsToCopy ; ++index)
			data[index] = m_data[index];
		}

		delete[] m_data;

		m_data = data;
		m_length = newLength;
	}
	void insertBefore(int value, int index)
	{

		assert(index >= 0 && index <= m_length);

		int *data = new int[m_length+1];

		for (int before=0; before < index; ++before)
			data[before] = m_data[before];

		data [index] = value;

		for (int after=index; after < m_length; ++after)
			data[after+1] = m_data[after];

		delete[] m_data;
		m_data = data;
		++m_length;
	}

	void push_back(int value) { insertBefore(value, m_length); }
	//Homework
	void pop_back()
	{
		resize(getLength() - 1);
	}
	void sort_arr(bool side)
	{
		for(int i = 0; i < getLength(); i++)
		{
			for(int j = i; j < getLength(); j++)
			{
				if (side == true ? (m_data[j] < m_data[i]) : (m_data[j] > m_data[i]))
				{
					int tmp;
					tmp = m_data[j];
					m_data[j] = m_data[i];
					m_data[i] = tmp;
				}
			}
		}
	}
	// Additional
	void printArr()
	{
		for(int i = 0; i < getLength(); i++)
		{
			cout << m_data[i] << " ";
		}
		cout << endl;
	}
	void push_front(int value) { insertBefore(value, 0); }
	void pop_front()
	{
		assert(getLength() > 0);

		if (getLength() == 1)
		{
			erase();
			return;
		}
		int *data = new int[getLength() - 1];

		for (int index = 1; index < getLength() ; ++index)
		data[index - 1] = m_data[index];

		delete[] m_data;

		m_data = data;
		m_length = getLength() - 1;
	}

};

/*
3. Реализовать класс Hand, который представляет собой коллекцию карт.
В классе будет одно поле: вектор указателей карт (удобно использовать вектор, т.к. это по сути динамический массив,
а тип его элементов должен быть - указатель на объекты класса Card). Также в классе Hand должно быть 3 метода:
	* метод Add, который добавляет в коллекцию карт новую карту, соответственно он принимает в качестве параметра указатель на новую карту
	* метод Clear, который очищает руку от карт
	* метод GetValue, который возвращает сумму очков карт руки (здесь предусмотреть возможность того, что туз может быть равен 11).
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
};

class Hand
{
private:
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
4. *Разработать функцию, принимающую два числа в виде списка (вектора) цифр в одной системе счисления,
* и возвращающую число — результат сложения.в виде списка (вектора) цифр в другой системе счисления.
*/

vector<int> vec_plus(const vector<int> &A, int baseA,
	const vector<int> &B, int baseB, int baseResult)
{
	int left = 0;
	int right = 0;
	int sum;
	vector<int> result;

	for(int i = 0; i < (int)A.size(); i++)
	{
		left += A[i] * pow(baseA, (int)A.size() - i - 1);
	}

	for(int i = 0; i < (int)B.size(); i++)
	{
		right += B[i] * pow(baseB, (int)B.size() - i - 1);
	}

	sum = left + right;
	while (sum >= baseResult)
	{
		result.insert ( result.begin() , sum % baseResult);
		sum /= baseResult;
	}
	result.insert ( result.begin() , sum % baseResult);
	return (result);
}

void	printVec(vector<int> &vec)
{
	for(int i = 0; i < (int)vec.size(); i++)
	{
		cout << vec[i];
	}
	cout << endl;
}

/*
2. Дан вектор чисел (числа вводятся с клавиатуры), требуется выяснить, сколько среди них различных.
Постараться использовать максимально быстрый алгоритм.
*/

void unique_elements_in_vec()
{
	cout << "Task 2" << endl;
	cout << "Enter the amount of numbers in vector:" << endl;

	int len;
	cin >> len;

	int num;
	int flag;
	vector<int> array;

	for(int i = 0; i < len; i++)
	{
		cin >> num;
		int z = 0;
		flag = 0;
		while (z < (int)array.size())
		{
			if (array[z] == num)
				flag = 1;;
			z++;
		}
		if (flag == 0)
			array.push_back(num);
	}
	printVec(array);
	cout << "Number of unique elements: " << array.size() << endl;

}




int main()
{
	// Task 1
	cout << "Task 1" << endl;
	ArrayInt arr;

	arr.push_back(0);
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);
	arr.push_back(6);
	arr.push_back(7);
	arr.push_back(8);
	arr.push_back(9);

	arr.printArr();

	arr.insertBefore(20, 5);
	arr.insertBefore(10, 2);
	arr.insertBefore(20, 1);
	arr.insertBefore(40, 8);
	arr.insertBefore(800, 10);
	arr.printArr();

	arr.pop_back();
	arr.pop_back();
	arr.printArr();

	arr.sort_arr(true);
	arr.printArr();
	arr.sort_arr(false);
	arr.printArr();

	arr.pop_back();
	arr.printArr();
	arr.pop_front();
	arr.printArr();
	cout << endl;


	// Task 2
	unique_elements_in_vec();

	// Task 4

	enum e_letters {A = 10, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z};

	cout << "Task 4" << endl;
	vector<int> A_num = {16, 16};
	int baseA = 16;
	vector<int> B_num = {H, E, L, L, O};
	int baseB = 36;
	vector<int> result;
	result = vec_plus(A_num, baseA, B_num, baseB, 2);
	printVec(result);

	return 0;
}
