#include <iostream>
#include <string>

using namespace std;

/*
Написать класс «робот», моделирующий перемещения робота по сетке 10x10,
	у которого есть метод, означающий задание переместиться на соседнюю позицию.
Эти методы должны запускать исключение OffTheField, если робот должен уйти с сетки,
	и IllegalCommand, если подана неверная команда (направление не находится в нужном диапазоне).
Объект исключения должен содержать всю необходимую информацию — текущую позицию и направление движения.
Написать функцию main, пользующуюся этим классом и перехватывающую все исключения от его методов,
	а также выводящую подробную информацию о всех возникающих ошибках.
*/

/*
	0123456789

0	0000000000
1	0000000000
2	0000000000
3	0000000000
4	0000000000
5	0000000000
6	0000000000
7	0000000000
8	0000000000
9	0000000000
*/

class OffTheField
{
private:
	char	dir;
	int		new_pos_y;
	int		new_pos_x;

public:
    OffTheField(int y, int x, char direction)
    {
		new_pos_y = y;
		new_pos_x = x;
		dir = direction;
	}
	int get_new_pos_y () const
	{
		return (new_pos_y);
	}
	int get_new_pos_x () const
	{
		return (new_pos_x);
	}
	char get_dir () const
	{
		return (dir);
	}
};

class IllegalCommand
{
private:
    char dir;
public:
    IllegalCommand(char direction)
    {
		dir = direction;
	}
	char get_dir() const
	{
		return (dir);
	}
};



class Robot
{
private:
	int pos_y;
	int	pos_x;
public:
	Robot() : pos_y(0), pos_x(0) {}
	Robot(int y, int x)
	{
		if (y < 0 || y > 9 || x < 0 || x > 9)
		{
			cout << "Wrong pos chosen, pos_y and pos_x set to 0" << endl;
			pos_y = 0;
			pos_x = 0;
		}
		else
		{
			pos_y = y;
			pos_x = x;
		}
	}
	void	move(char dir)
	{
		if (dir != 'u' && dir != 'd' && dir != 'l' && dir != 'r')
			throw IllegalCommand(dir);
		if (dir == 'u')
		{
			if (pos_y - 1 < 0)
				throw OffTheField(pos_y - 1, pos_x, dir);
			else
				pos_y -= 1;
		}
		if (dir == 'd')
		{
			if (pos_y + 1 > 9)
				throw OffTheField(pos_y + 1, pos_x, dir);
			else
				pos_y += 1;
		}
		if (dir == 'l')
		{
			if (pos_x - 1 < 0)
				throw OffTheField(pos_y, pos_x - 1, dir);
			else
				pos_x -= 1;
		}
		if (dir == 'r')
		{
			if (pos_x + 1 > 9)
				throw OffTheField(pos_y, pos_x + 1, dir);
			else
				pos_x += 1;
		}
	}

};





/*
Написать класс Ex, хранящий вещественное число x и имеющий конструктор по вещественному числу,
	инициализирующий x значением параметра.
Написать класс Bar, хранящий вещественное число y (конструктор по умолчанию инициализирует его нулем)
	и имеющий метод set с единственным вещественным параметром a.
Если y + a > 100, возбуждается исключение типа Ex с данными ay,
	иначе в y заносится значение a. 
В функции main завести переменную класса Bar и в цикле в блоке try вводить с клавиатуры целое n.
Использовать его в качестве параметра метода set до тех пор, пока не будет введено 0.
В обработчике исключения выводить сообщение об ошибке, содержащее данные объекта исключения.
*/

class Ex
{
private:
	float x;
public:
	Ex(float flo_num) : x(flo_num) {}
	float get_x() const
	{
		return (x);
	}
};

class Bar
{
private:
	float y;
public:
	Bar() : y(0) {}
	void set(float a)
	{
		if (y + a > 100)
			throw Ex(a * y);
		else
			y = a;
	}
};



/*
1. Написать функцию div, которая должна вычислять результат деления двух целых чисел
	и запускать исключение DivisionByZero, если делитель равен 0.
В функции main ввести два целых числа и вывести их неполное частное,
	если делитель не равен нулю, и сообщение об ошибке, если равен. 
*/

int		Div(int a, int b)
{
	if (b == 0)
		throw "DivisionByZero";
	return (a / b);
}

int main()
{
	// Task 1
	cout << "Task 1" << endl;
	try
	{
		cout << Div(5, 3) << endl;
		//cout << Div(7, 0) << endl;
		cout << Div(20, 7) << endl;
		cout << Div(-10, 2) << endl;
		cout << Div(-15, -5) << endl;
		cout << Div(-10, 0) << endl;
		cout << Div(0, 0) << endl;


	}
	catch(const char *exception)
	{
		cerr << "Error: " << exception << endl;
	}
	cout << endl;


	// Task 2
	cout << "Task 2" << endl;
	Bar bar;

	try
	{
		int n = 1;

		while (n != 0)
		{
			bar.set(n);
			cout << "Enter n:" << endl;
			cin >> n;
		}
	}
	catch(Ex exception_Ex)
	{
		cout << "Error: " << exception_Ex.get_x() << endl;
	}


	// Task 2
	cout << "Task 2" << endl;
	Robot robot_wrong(10, 3);
	Robot robot(1, 3);
	try
	{
		robot.move('r');
		robot.move('l');
		robot.move('u');
		robot.move('d');

		//robot.move('z');
		//robot.move('f');

		// robot.move('d');
		// robot.move('d');
		// robot.move('d');
		// robot.move('d');
		// robot.move('d');
		// robot.move('d');
		// robot.move('d');
		// robot.move('d');
		// robot.move('d');
		// robot.move('d');

		// robot.move('u');
		// robot.move('u');
		// robot.move('u');
		// robot.move('u');
		// robot.move('u');
		// robot.move('u');
		// robot.move('u');
		// robot.move('u');
		// robot.move('u');
		// robot.move('u');
		// robot.move('u');

		// robot.move('l');
		// robot.move('l');
		// robot.move('l');
		// robot.move('l');
		// robot.move('l');
		// robot.move('l');
		// robot.move('l');
		// robot.move('l');
		// robot.move('l');
		// robot.move('l');
		// robot.move('l');

		robot.move('r');
		robot.move('r');
		robot.move('r');
		robot.move('r');
		robot.move('r');
		robot.move('r');
		robot.move('r');
		robot.move('r');
		robot.move('r');
		robot.move('r');
		robot.move('r');
		
		

	}
	catch(IllegalCommand wr_comm)
	{
		cout << "Wrong direction entered: " <<  wr_comm.get_dir() << endl
			<< "You can enter only 'u' - up, 'd' - down, 'l' - left, 'r' - right" << endl;
	}
	catch(OffTheField off_f)
	{
		cout << "You can`t move in '" << off_f.get_dir() << "' direction, cause you will be in wrong "
			<< off_f.get_new_pos_y() << " " << off_f.get_new_pos_x() << " position" << endl;
	}
	


	return 0;
}
