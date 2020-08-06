#include <iostream>
#include <memory>

using namespace std;

/*
1. Создайте класс Date с полями день, месяц, год и методами доступа к этим полям.
Перегрузите оператор вывода для данного класса.
Создайте два "умных" указателя today и date.
Первому присвойте значение сегодняшней даты.
Для него вызовите по отдельности методы доступа к полям класса Date,
	а также выведите на экран данные всего объекта с помощью перегруженного оператора вывода.
Затем переместите ресурс, которым владеет указатель today в указатель date.
Проверьте, являются ли нулевыми указатели today и date и выведите соответствующую информацию об этом в консоль.
*/

class Date
{
private:
	int		day;
	int		month;
	int		year;
public:
	Date() : day(0), month(0), year(0) { }
	Date(int d, int m, int y) : day(d), month(m), year(y) { }
	~Date () {}
	int getDay() const
	{
		return (day);
	}
	int getMonth() const
	{
		return (month);
	}
	int getYear() const
	{
		return (year);
	}
	friend ostream& operator<< (ostream &out, const Date &date);
};

ostream& operator<< (ostream &out, const Date &date)
{
	out << "Day: " << date.day << " Month: " << date.month << " Year: " << date.year << endl;
	return (out);
}

// Task 2
unique_ptr<Date> &compare_dates(unique_ptr<Date> &date1, unique_ptr<Date> &date2)
{
	if (date1->getYear() > date2->getYear())
		return (date1);
	if (date2->getYear() > date1->getYear())
		return (date2);
	if (date1->getMonth() > date2->getMonth())
		return (date1);
	if (date2->getMonth() > date1->getMonth())
		return (date2);
	if (date1->getDay() > date2->getDay())
		return (date1);
	else
		return (date2);
}

void			swap_data(unique_ptr<Date> &date1, unique_ptr<Date> &date2)
{
	unique_ptr<Date> tmp;

	tmp = move(date1);
	date1 = move(date2);
	date2 = move(tmp);
}

int main()
{
	// Task 1
	cout << "Task 1" << endl;
	unique_ptr<Date> today = make_unique<Date>(1, 8, 2020);
	unique_ptr<Date> date;

	cout << today->getDay() << " " << today->getMonth() << " " << today->getYear() << endl;
	cout << *today;

	date = move(today);
	if (today)
		cout << "today is not null" << endl;
	else
		cout << "today is null" << endl;
	cout << endl;
	if (date)
		cout << "date is not null" << endl;
	else
		cout << "date is null" << endl;
	cout << endl;

/*
2. По условию предыдущей задачи создайте два умных указателя date1 и date2.
Создайте функцию, которая принимает в качестве параметра два умных указателя типа Date
	и сравнивает их между собой (сравнение происходит по датам).
Функция должна вернуть более позднюю дату.
Создайте функцию, которая обменивает ресурсами (датами) два умных указателя,
	переданных в функцию в качестве параметров.
*/

	// Task 2
	cout << "Task 2" << endl;

	unique_ptr<Date> date1 = make_unique<Date>(13, 7, 1998);
	unique_ptr<Date> date2 = make_unique<Date>(6, 5, 2005);
	unique_ptr<Date> date3 = make_unique<Date>(1, 8, 2020);
	unique_ptr<Date> date4 = make_unique<Date>(2, 8, 2020);

	cout << *compare_dates(date1, date2);
	cout << *compare_dates(date3, date4);
	cout << endl;
	cout << *date1;
	cout << *date2;
	cout << *date3;
	cout << *date4;

	cout << endl;

	cout << *date1;
	cout << *date2;
	swap_data(date1, date2);
	cout << endl;
	cout << *date1;
	cout << *date2;
	return 0;
}
