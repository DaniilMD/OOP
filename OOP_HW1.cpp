#include <iostream>
#include <math.h>
#include <cstdint>

using namespace std;

/*
1. Создать класс Power, который содержит два вещественных числа.
Этот класс должен иметь две переменные-члена для хранения этих вещественных чисел.
Еще создать два метода: один с именем set, который позволит присваивать значения переменным, второй — calculate,
который будет выводить результат возведения первого числа в степень второго числа. Задать значения этих двух чисел по умолчанию.
*/

class   Power
{
private:
    double num;
    double power;
public:
    Power()
    {
        num = 2;
        power = 3;
    }
    void setNumPow(double n, double p)
    {
        num = n;
        power = p;
    }
	void calculate() const
    {
        cout << pow(num, power) << endl;
    }
};

/*
2. Написать класс с именем RGBA, который содержит 4 переменные-члена типа std::uint8_t: m_red, m_green, m_blue и m_alpha (#include cstdint для доступа к этому типу).
Задать 0 в качестве значения по умолчанию для m_red, m_green, m_blue и 255 для m_alpha.
Создать конструктор со списком инициализации членов, который позволит пользователю передавать значения для m_red, m_blue, m_green и m_alpha.
Написать функцию print(), которая будет выводить значения переменных-членов
*/

class   RGBA
{
private:
    uint8_t m_red;
    uint8_t m_green;
    uint8_t m_blue;
    uint8_t m_alpha;
public:
    RGBA()
    {
        m_red = 0;
        m_green = 0;
        m_blue = 0;
        m_alpha = 255;
    }
    RGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : m_red(r), m_green(g), m_blue(b), m_alpha(a)
    {
    }
	void print() const
    {
        cout << "red: " << (int)m_red << " green: " << (int)m_green << " blue: " << (int)m_blue << " alpha: " << (int)m_alpha << endl;
    }
};

/*
3/ Написать класс, который реализует функциональность стека. Класс Stack должен иметь:
    private-массив целых чисел длиной 10;
    private целочисленное значение для отслеживания длины стека;
    public-метод с именем reset(), который будет сбрасывать длину и все значения элементов на 0;
    public-метод с именем push(), который будет добавлять значение в стек. push() должен возвращать значение false, если массив уже заполнен, и true в противном случае;
    public-метод с именем pop() для вытягивания и возврата значения из стека. Если в стеке нет значений, то должно выводиться предупреждение;
    public-метод с именем print(), который будет выводить все значения стека.
*/

class   Stack
{
private:
	int		nums[10];
	int		nums_len;
public:
	Stack()
	{
		reset();
	}
	void reset()
	{
		for (int i = 0; i < nums_len; i++)
		{
			nums[i] = 0;
		}
		nums_len = 0;
	}
	bool push(int num)
	{
		if (nums_len == 10)
			return (false);
		else
		{
			nums[nums_len] = num;
			nums_len++;
			return (true);
		}
	}
	void pop()
	{
		if (nums_len == 0)
		{
			cout << "Stack is empty" << endl;
			return ;
		}
		else
		{
			nums[nums_len] = 0;
			nums_len--;
		}
	}
	void print() const
	{
		cout << "( ";
		for (int i = 0; i < nums_len; i++)
		{
			cout << nums[i] << " ";
		}
		cout << ")" << endl;
	}
};

int main()
{
	//1 Task
	Power a;
	a.calculate();
	a.setNumPow(3,5);
	a.calculate();

	//2 Task
	RGBA col1;
	col1.print();
	RGBA col2(100, 200, 50, 70);
	col2.print();

	//3 Task
	Stack stack;
	stack.reset();
	stack.print();

	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();
	stack.print();

	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();

	stack.reset();
	stack.print();
	return (0);
}
