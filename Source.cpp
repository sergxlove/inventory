#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
class inventory
{
public:
	inventory();
	inventory(int number, string adres, int year, int area_region, int area_build, int wear, int price);
	~inventory();
	void print_info();
	void set_data();
	void write_file(vector<inventory>& arr, string path);
private:
	int number;//кадастровый номер
	string adres;//адрес
	int year;//год постройки
	int area_region;//площадь участка
	int area_build;//площадь застройки
	int wear;//процент износ
	int price;//инвентаризационная стоимость
};
int main()
{
	setlocale(LC_ALL, "rus");
	inventory invent;
	vector<inventory> arr;
	string path = "data.txt";
	int var_switch = 0;
	bool exit = false;
	while (!exit)
	{
		invent.print_info();
		cout << "Выберите режим: " << endl;
		cin >> var_switch;
		switch (var_switch)
		{
		case 1:
			invent.set_data();
			arr.push_back(invent);
			cout << "Объект создан успешно" << endl;
			cout << "=============================================" << endl;
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			exit = true;
			cout << "=============================================" << endl;
			cout << "Программа завершена" << endl;
			cout << "=============================================" << endl;
			break;
		default:
			break;
		}
	}
	return 0;
}

inventory::inventory()
{
	this->number = 0;
	this->adres = "";
	this->year = 0;
	this->area_region = 0;
	this->area_build = 0;
	this->wear = 0;
	this->price = 0;
}

inventory::inventory(int number, string adres, int year, int area_region, int area_build, int wear, int price)
{
	this->number = number;
	this->adres = adres;
	this->year = year;
	this->area_region = area_region;
	this->area_build = area_build;
	this->wear = wear;
	this->price = price;
}

inventory::~inventory()
{
	this->number = 0;
	this->adres = "";
	this->year = 0;
	this->area_region = 0;
	this->area_build = 0;
	this->wear = 0;
	this->price = 0;
}

void inventory::print_info()
{
	cout << "Доступные режимы : " << endl;
	cout << "1 - Ввод данных" << endl;
	cout << "2 - Сохранение данных в файл" << endl;
	cout << "3 - Чтение данных из файла" << endl;
	cout << "4 - Удаление объекта" << endl;
	cout << "5 - Поиск данных по полям" << endl;
	cout << "6 - Поиск минимального элемента" << endl;
	cout << "7 - Поиск максимального элемента" << endl;
	cout << "8 - Сортировка по полю" << endl;
	cout << "9 - Вывод элементов" << endl;
	cout << "10 - Выход из программы" << endl;
}

void inventory::set_data()
{
	cout << "Введите кадастровый номер :\t";
	cin >> this->number;
	cout << "Введите адрес :\t";
	cin >> this->adres;
	cout << "Введите год постройки :\t";
	cin >> this->year;
	cout << "Введит площадь участка :\t";
	cin >> this->area_region;
	cout << "Введите площадь застройки :\t";
	cin >> this->area_build;
	cout << "Введите процент износа :\t";
	cin >> this->wear;
	cout << "Введите инвентаризационную стоимость :\t";
	cin >> this->price;
}

void inventory::write_file(vector<inventory>& arr, string path)
{
}
