#include <iostream>
#include <string.h>

using namespace std;

/*
1. Создать класс Person (человек) с полями: имя, возраст, пол и вес.
    Определить методы переназначения имени, изменения возраста и веса.
    Создать производный класс Student (студент), имеющий поле года обучения.
    Определить методы переназначения и увеличения этого значения.
    Создать счетчик количества созданных студентов.
    В функции main() создать несколько студентов.
По запросу вывести определенного человека.
*/

class  Person
{
private:
	string	name;
	int		age;
	char	gender;
	int		weight;
public:
	Person() : name("Ivan"), age(0), gender('m'), weight(0) {}
	Person (string name, int age, char gender, int weight)
	{
		changePerson(name, age, gender, weight);
	}
	void changePerson(string name, int age, char gender, int weight)
	{
		this->name = name;
		this->age = age;
		this->gender = gender;
		this->weight = weight;
	}
	void changePersonName(string name)
	{
		this->name = name;
	}
	void changePersonAge(int age)
	{
		this->age = age;
	}
	void changePersonWeight(int weight)
	{
		this->weight = weight;
	}
	void getPerson() const
	{
		cout << "Person info: " << name << " " << age << " " << gender << " " << weight << endl;
	}
};

class  Student : public Person
{
private:
	int grade;
public:
	static int n_students;
	Student() : grade(1)
	{
		n_students++;
	}
	Student(string name, int age, char gender, int weight, int grade) : grade(1)
	{
		changePerson(name, age, gender, weight);
		this->grade = grade;
		n_students++;
	}
	void changeGrade(int grade)
	{
		this->grade = grade;
	}
	void increaseGrade()
	{
		grade++;
	}
	void printStudentData()
	{
		getPerson();
		cout << "Grade: " << grade << endl;
	}
};

int Student::n_students = 0;

/*
2. Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс Fruit (фрукт).
У Fruit есть две переменные-члена: name (имя) и color (цвет).
Добавить новый класс GrannySmith, который наследует класс Apple.

int main()
{
Apple a("red");
Banana b;
GrannySmith c;

std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

return 0;
}

Код, приведенный выше, должен давать следующий результат:
My apple is red.
My banana is yellow.
My Granny Smith apple is green.
*/

class Fruit
{
protected:
	string  name;
	string  color;
public:
	string getName() const
	{
		return name;
	}
	string getColor() const
	{
		return color;
	}
};

class Apple : public Fruit
{
public:
	Apple()
	{
		color = "red";
		name = "apple";
	}
	Apple(string color)
	{
		this->color = color;
		name = "apple";
	}
};

class Banana : public Fruit
{
public:
	Banana()
	{
		color = "yellow";
		name = "banana";
	}
	Banana(string color)
	{
		this->color = color;
		name = "banana";
	}
};

class  GrannySmith : public Fruit
{
public:
	GrannySmith()
	{
		color ="green";
		name = "GrannySmith apple";
	}
};

/*
3.Изучить правила игры в Blackjack. Подумать, как написать данную игру на С++, используя
объектно-ориентированное программирование. Сколько будет классов в программе? Какие
классы будут базовыми, а какие производными? Продумать реализацию игры с помощью
классов и записать результаты.



Должен быть класс карты (напр. Card), указвающий на то, какая она, сколько очков стоит.
Возможно стоит выделить карты стоимостью в 10 очков в отдельную группу.

Должен быть класс участника (Participant) с указанием того, какие у него карты (напр. массив класса Card),
    сколько у него очков.
От класса Participant можно наследовать классы Игрока (напр. Player) и дилера (напр. Dealer).
У них будут разные возможности и задачи.

Должен быть класс колоды (напр. Deck), наследующий класс Card, где хранятся имеющиеся карты и те,
    что уже вышли.

Возможно должен быть некий класс с правилами (напр. Rules).

*/

int main()
{
	//1 Task
	Student stud1;
	cout << stud1.n_students << endl;

	Student stud2;
	cout << stud2.n_students << endl;
	cout << stud1.n_students << endl;

	Student stud3("Nikolai", 20, 'm', 60, 2);
	stud3.printStudentData();
	stud3.increaseGrade();
	stud3.printStudentData();
	cout << endl;


	//2 Task
	Apple a("red");
	Banana b;
	GrannySmith c;

	cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
	cout << endl;


	//3 Task

	return (0);
}
