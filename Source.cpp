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
	void print_data();
	void set_data();
	void write_file(vector<inventory>& arr, string path);
	void read_file(vector<inventory>& arr, string path);
	void delete_obj(vector<inventory>& arr);
	void search_data(vector<inventory>& arr);
	void search_min(vector<inventory>& arr);
	void search_max(vector<inventory>& arr);
	void sort_field(vector<inventory>& arr);
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
	int count = 0;
	bool exit = false;
	invent.read_file(arr, path);
	invent.print_info();
	while (!exit)
	{
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
			if (arr.empty())
			{
				cout << "В векторе нет элементов" << endl;
			}
			else
			{
				invent.delete_obj(arr);
				cout << "=============================================" << endl;
			}
			break;
		case 5:
			if (arr.empty())
			{
				cout << "В векторе нет элементов" << endl;
			}
			else
			{
				invent.search_data(arr);
				cout << "=============================================" << endl;
			}
			break;
		case 6:
			if (arr.empty())
			{
				cout << "В векторе нет элементов" << endl;
			}
			else
			{
				invent.search_min(arr);
				cout << "=============================================" << endl;
			}
			break;
		case 7:
			if (arr.empty())
			{
				cout << "В векторе нет элементов" << endl;
			}
			else
			{
				invent.search_max(arr);
				cout << "=============================================" << endl;
			}
			break;
		case 8:
			if (arr.empty())
			{
				cout << "В векторе нет элементов" << endl;
			}
			else
			{
				invent.sort_field(arr);
				cout << "=============================================" << endl;
			}
			break;
		case 9:
			if (arr.empty())
			{
				cout << "В векторе нет элементов" << endl;
			}
			else
			{
				count = 0;
				for (auto& el : arr)
				{
					cout << "Объект " << count << endl;
					el.print_data();
					count++;
				}
			}
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
	cout << "1 - Кадастровый номер" << endl;
	cout << "2 - Адрес" << endl;
	cout << "3 - Год постройки" << endl;
	cout << "4 - Площадь участка" << endl;
	cout << "5 - Площадь застройки" << endl;
	cout << "6 - Процент износа" << endl;
	cout << "7 - Инвентаризационная стоимсть" << endl;
}

void inventory::print_mm()
{
	cout << "Доступные поля: " << endl;
	cout << "1 - Кадастровый номер" << endl;
	cout << "2 - Год постройки" << endl;
	cout << "3 - Площадь участка" << endl;
	cout << "4 - Площадь застройки" << endl;
	cout << "5 - Процент износа" << endl;
	cout << "6 - Инвентаризационная стоимсть" << endl;
}

void inventory::print_data()
{
	cout << "Кадастровый номер : " << this->number << endl;
	cout << "Адрес : " << this->adres << endl;
	cout << "Год постройки : " << this->year << endl;
	cout << "Площадь уччастка : " << this->area_region << endl;
	cout << "Площадь застройки : " << this->area_build << endl;
	cout << "Процент износа : " << this->wear << endl;
	cout << "Инвентаризационная стоимость : " << this->price << endl;
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
				el.print_data();
				check = true;
			}
		}
		break;
	case 2:
		for (auto& el : arr)
		{
			if (el.adres == data)
			{
				el.print_data();
				check = true;
			}
		}
		break;
	case 3:
		for (auto& el : arr)
		{
			if (el.year == stoi(data))
			{
				el.print_data();
				check = true;
			}
		}
		break;
	case 4:
		for (auto& el : arr)
		{
			if (el.area_region == stoi(data))
			{
				el.print_data();
				check = true;
			}
		}
		break;
	case 5:
		for (auto& el : arr)
		{
			if (el.area_build == stoi(data))
			{
				el.print_data();
				check = true;
			}
		}
		break;
	case 6:
		for (auto& el : arr)
		{
			if (el.wear == stoi(data))
			{
				el.print_data();
				check = true;
			}
		}
		break;
	case 7:
		for (auto& el : arr)
		{
			if (el.price == stoi(data))
			{
				el.print_data();
				check = true;
			}
		}
		break;
	default:
		cout << "Некорректный ввод" << endl;
		break;
	}
	if (!check)
	{
		cout << "Данные не найдены" << endl;
	}
}

void inventory::search_min(vector<inventory>& arr)
{
	int min = 1000000;
	int var = 0;
	inventory obj;
	obj.print_mm();
	cout << "Выберите нужное поле" << endl;
	cin >> var;
	if (var >= 0 && var < arr.size())
	{
		switch (var)
		{
		case 1:
			for (auto& el : arr)
			{
				if (el.number < min)
				{
					min = el.number;
				}
			}
			cout << "Минимальный элемент = " << min << endl;
			break;
		case 2:
			for (auto& el : arr)
			{
				if (el.year < min)
				{
					min = el.year;
				}
			}
			cout << "Минимальный элемент = " << min << endl;
			break;
		case 3:
			for (auto& el : arr)
			{
				if (el.area_region < min)
				{
					min = area_region;
				}
			}
			cout << "Минимальный элемент = " << min << endl;
			break;
		case 4:
			for (auto& el : arr)
			{
				if (el.area_build < min)
				{
					min = el.area_build;
				}
			}
			cout << "Минимальный элемент = " << min << endl;
			break;
		case 5:
			for (auto& el : arr)
			{
				if (el.wear < min)
				{
					min = el.wear;
				}
			}
			cout << "Минимальный элемент = " << min << endl;
			break;
		case 6:
			for (auto& el : arr)
			{
				if (el.price < min)
				{
					min = el.price;
				}
			}
			cout << "Минимальный элемент = " << min << endl;
			break;
		default:
			cout << "Некорректный ввод" << endl;
			break;
		}
	}
	else
	{
		cout << "Некорректный ввод" << endl;
	}
}

void inventory::search_max(vector<inventory>& arr)
{
	int max = 0;
	int var = 0;
	inventory obj;
	obj.print_mm();
	cout << "Выберите нужное поле" << endl;
	cin >> var;
	if (var >= 0 && var < arr.size())
	{
		switch (var)
		{
		case 1:
			for (auto& el : arr)
			{
				if (el.number > max)
				{
					max = el.number;
				}
			}
			cout << "Минимальный элемент = " << max << endl;
			break;
		case 2:
			for (auto& el : arr)
			{
				if (el.year > max)
				{
					max = el.year;
				}
			}
			cout << "Минимальный элемент = " << max << endl;
			break;
		case 3:
			for (auto& el : arr)
			{
				if (el.area_region > max)
				{
					max = area_region;
				}
			}
			cout << "Минимальный элемент = " << max << endl;
			break;
		case 4:
			for (auto& el : arr)
			{
				if (el.area_build > max)
				{
					max = el.area_build;
				}
			}
			cout << "Минимальный элемент = " << max << endl;
			break;
		case 5:
			for (auto& el : arr)
			{
				if (el.wear > max)
				{
					max = el.wear;
				}
			}
			cout << "Минимальный элемент = " << max << endl;
			break;
		case 6:
			for (auto& el : arr)
			{
				if (el.price > max)
				{
					max = el.price;
				}
			}
			cout << "Минимальный элемент = " << max << endl;
			break;
		default:
			cout << "Некорректный ввод" << endl;
			break;
		}
	}
	else
	{
		cout << "Некорректный ввод" << endl;
	}
}

void inventory::sort_field(vector<inventory>& arr)
{
	inventory obj;
	int var = 0;
	obj.print_field();
	cout << "Выберите нужное поле" << endl;
	cin >> var;
	if (var >= 0 && var < arr.size())
	{
		switch (var)
		{
		case 1:
			sort(arr.begin(), arr.end(), [](const inventory i1, const inventory i2) {return i1.number < i2.number;});
			break;
		case 2:
			sort(arr.begin(), arr.end(), [](const inventory i1, const inventory i2) {return i1.adres < i2.adres;});
			break;
		case 3:
			sort(arr.begin(), arr.end(), [](const inventory i1, const inventory i2) {return i1.year < i2.year;});
			break;
		case 4:
			sort(arr.begin(), arr.end(), [](const inventory i1, const inventory i2) {return i1.area_region < i2.area_region;});
			break;
		case 5:
			sort(arr.begin(), arr.end(), [](const inventory i1, const inventory i2) {return i1.area_build < i2.area_build;});
			break;
		case 6:
			sort(arr.begin(), arr.end(), [](const inventory i1, const inventory i2) {return i1.wear < i2.wear;});
			break;
		case 7:
			sort(arr.begin(), arr.end(), [](const inventory i1, const inventory i2) {return i1.price < i2.price;});
			break;
		}
	}
}
