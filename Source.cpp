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
	void print_field();
	void print_mm();
	void set_data();
	void write_file(vector<inventory>& arr, string path);
	void read_file(vector<inventory>& arr, string path);
	void delete_obj(vector<inventory>& arr);
	void search_data(vector<inventory>& arr);
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
			invent.write_file(arr, path);
			cout << "Данные успешно записаны" << endl;
			cout << "=============================================" << endl;
			break;
		case 3:
			invent.read_file(arr, path);
			cout << "Данные успешно считаны" << endl;
			cout << "=============================================" << endl;
			break;
		case 4:
			invent.delete_obj(arr);
			cout << "=============================================" << endl;
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

void inventory::print_field()
{
	cout << "Доступные поля:" << endl;
	cout << "1 - кадастровый номер" << endl;
	cout << "2 - адрес" << endl;
	cout << "3 - год постройки" << endl;
	cout << "4 - площадь участка" << endl;
	cout << "5 - площадь застройки" << endl;
	cout << "6 - процент износа" << endl;
	cout << "7 - инвентаризационная стоимсть" << endl;
}

void inventory::print_mm()
{
	cout << "Доступные поля: " << endl;
	cout << "1 - кадастровый номер" << endl;
	cout << "2 - год постройки" << endl;
	cout << "3 - площадь участка" << endl;
	cout << "4 - площадь застройки" << endl;
	cout << "5 - процент износа" << endl;
	cout << "6 - инвентаризационная стоимсть" << endl;
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
	fstream file;
	file.open(path, fstream::out);
	if (file.is_open())
	{
		file.clear();
		file << arr.size()<<"\n";
		for (auto& el : arr)
		{
			file << el.number << "\n";
			file << el.adres << "\n";
			file << el.year << "\n";
			file << el.area_region << "\n";
			file << el.area_build << "\n";
			file << el.wear << "\n";
			file << el.price << "\n";
		}
		file.close();
	}
	else
	{
		cout << "Ошибка открытия файла" << endl;
	}
}

void inventory::read_file(vector<inventory>& arr, string path)
{
	fstream file;
	string data;
	int size = 0;
	inventory obj;
	file.open(path, fstream::in);
	if (file.is_open())
	{
		arr.clear();
		getline(file, data);
		size = stoi(data);
		for (int i = 0; i < size;i++)
		{
			getline(file, data);
			obj.number = stoi(data);
			getline(file, obj.adres);
			getline(file, data);
			obj.year = stoi(data);
			getline(file, data);
			obj.area_region = stoi(data);
			getline(file, data);
			obj.area_build = stoi(data);
			getline(file, data);
			obj.wear = stoi(data);
			getline(file, data);
			obj.price = stoi(data);
			arr.push_back(obj);
		}
		file.close();
	}
	else
	{
		cout << "Ошибка открытия файла" << endl;
	}
}

void inventory::delete_obj(vector<inventory>& arr)
{
	int count = 0;
	int var = 0;
	cout << "Доступные объекты для удаления:" << endl;
	for (auto& el : arr)
	{
		cout << "Объект - " << count << endl;
		count++;
	}
	cout << "Выберите объект для удаления" << endl;
	cin >> var;
	if (var >= 0 && var < arr.size())
	{
		arr.erase(arr.begin() + var);
		cout << "Объект успешно удален" << endl;
	}
	else
	{
		cout << "Некорректный ввод" << endl;
	}
}

void inventory::search_data(vector<inventory>& arr)
{
	inventory obj;
	string data;
	int var = 0;
	bool check = false;
	obj.print_field();
	cout << "Выберите нужное поле : " << endl;
	cin >> var;
	cout << "Введите данные для поиска : " << endl;
	cin >> data;
	switch (var)
	{
	case 1:
		for (auto& el : arr)
		{
			if (el.number == stoi(data))
			{

			}
		}
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
	default:
		cout << "Некорректный ввод" << endl;
		break;
	}
}
