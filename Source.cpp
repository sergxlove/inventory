//подключение библиотек
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;//подключение пространства имен
class inventory//класс
{
public://паблик секция
	inventory();//конструктор по умолчанию
	inventory(int number, string adres, int year, int area_region, int area_build, int wear, int price);//конструктор с параметрами
	~inventory();//деструктор
	void print_info();//метод, выводящий информацию о консольном меню
	void print_field();//метод, выводящий наименование доступных полей
	void print_mm();//метод, выводящий наименование доступных полей 
	void print_data();//метод, выводящий данные полей объекта
	void set_data();//метод, осуществляющий ввод данных в объект
	void write_file(vector<inventory>& arr, string path);//метод, осуществляющиий запись данных в файл
	void read_file(vector<inventory>& arr, string path);//метод, осуществляюющий чтение данных из файла 
	void delete_obj(vector<inventory>& arr);//метод, осуществляющий удаление объекта
	void search_data(vector<inventory>& arr);//метод, производящий поиск данных
	void search_min(vector<inventory>& arr);//метод, отвечающий за нахождение минимального элемента
	void search_max(vector<inventory>& arr);//метод, отвечающий за нахождение максимального объекта
	void sort_field(vector<inventory>& arr);//метод, производящий сортировку по полю
private://приват секция
	int number;//кадастровый номер
	string adres;//адрес
	int year;//год постройки
	int area_region;//площадь участка
	int area_build;//площадь застройки
	int wear;//процент износ
	int price;//инвентаризационная стоимость
};
int main()//основная программа
{
	setlocale(LC_ALL, "rus");
	inventory invent;//создание объекта
	vector<inventory> arr;//создание вектора объектов
	//объявление переменных
	string path = "data.txt";
	int var_switch = 0;
	int count = 0;
	bool exit = false;
	invent.read_file(arr, path);//чтение данных из файла
	invent.print_info();//вывод информации о консольном меню
	while (!exit)
	{
		cout << "Выберите режим: " << endl;
		cin >> var_switch;//навигация по консольному меню
		switch (var_switch)//консольное меню
		{
		case 1://режим 1
			invent.set_data();//ввод данных
			arr.push_back(invent);//добавление объекта в конец вектора
			cout << "Объект создан успешно" << endl;
			cout << "=============================================" << endl;
			break;
		case 2://режим 2
			invent.write_file(arr, path);//запись данных в файл
			cout << "Данные успешно записаны" << endl;
			cout << "=============================================" << endl;
			break;
		case 3://режим 3
			invent.read_file(arr, path);//чтение данных из файла
			cout << "Данные успешно считаны" << endl;
			cout << "=============================================" << endl;
			break;
		case 4://режим 4
			if (arr.empty())//проверка вектора на пустоту
			{
				cout << "В векторе нет элементов" << endl;
			}
			else
			{
				invent.delete_obj(arr);//удаление объекта
				cout << "=============================================" << endl;
			}
			break;
		case 5://режим 5
			if (arr.empty())//проверка вектора на пустоту
			{
				cout << "В векторе нет элементов" << endl;
			}
			else
			{
				invent.search_data(arr);//поиск данных по полям
				cout << "=============================================" << endl;
			}
			break;
		case 6://режим 6
			if (arr.empty())//проверка вектора на пустоту
			{
				cout << "В векторе нет элементов" << endl;
			}
			else
			{
				invent.search_min(arr);//определение минимального значения
				cout << "=============================================" << endl;
			}
			break;
		case 7://режим 7
			if (arr.empty())//проверка вектора на пустоту
			{
				cout << "В векторе нет элементов" << endl;
			}
			else
			{
				invent.search_max(arr);//определение максимального значения
				cout << "=============================================" << endl;
			}
			break;
		case 8://режим 8
			if (arr.empty())//проверка вектора на пустоту
			{
				cout << "В векторе нет элементов" << endl;
			}
			else
			{
				invent.sort_field(arr);//сортировка вектора по полю
				cout << "=============================================" << endl;
			}
			break;
		case 9://режим 9
			if (arr.empty())//проверка вектора на пустоту
			{
				cout << "В векторе нет элементов" << endl;
			}
			else
			{
				count = 0;
				for (auto& el : arr)//перебор объектов вектора с помощью цикла фор ич
				{
					cout << "Объект " << count << endl;
					el.print_data();//вывод данных полей
					count++;
				}
				cout << "=============================================" << endl;
			}
			break;
		case 10://режим 10
			exit = true;//выход из программы
			cout << "=============================================" << endl;
			cout << "Программа завершена" << endl;
			cout << "=============================================" << endl;
			break;
		default://на случай неверного ввода
			cout << "Некорректный ввод " << endl;
			break;
		}
	}
	return 0;
}
inventory::inventory()//реализация конструктора по умолчанию
{
	//присвоение полям класса значений
	this->number = 0;
	this->adres = "";
	this->year = 0;
	this->area_region = 0;
	this->area_build = 0;
	this->wear = 0;
	this->price = 0;
}
inventory::inventory(int number, string adres, int year, int area_region, int area_build, int wear, int price)//реализация конструктора с параметрами
{
	//присвоение полям класса значений
	this->number = number;
	this->adres = adres;
	this->year = year;
	this->area_region = area_region;
	this->area_build = area_build;
	this->wear = wear;
	this->price = price;
}
inventory::~inventory()//реализация деструктора
{
	this->number = 0;
	this->adres = "";
	this->year = 0;
	this->area_region = 0;
	this->area_build = 0;
	this->wear = 0;
	this->price = 0;
}
void inventory::print_info()//реализация метода, отвечающего за вывод иформации о консольном меню
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
void inventory::print_field()//реализация метода, отвечающего за вывод доступных полей
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
void inventory::print_mm()//реализация метода, отвечающего за вывод полей для нахождения минимального или максимального значения
{
	cout << "Доступные поля: " << endl;
	cout << "1 - Кадастровый номер" << endl;
	cout << "2 - Год постройки" << endl;
	cout << "3 - Площадь участка" << endl;
	cout << "4 - Площадь застройки" << endl;
	cout << "5 - Процент износа" << endl;
	cout << "6 - Инвентаризационная стоимсть" << endl;
}
void inventory::print_data()//реализация метода, отвечающего за вывод данных
{
	cout << "Кадастровый номер : " << this->number << endl;
	cout << "Адрес : " << this->adres << endl;
	cout << "Год постройки : " << this->year << endl;
	cout << "Площадь уччастка : " << this->area_region << endl;
	cout << "Площадь застройки : " << this->area_build << endl;
	cout << "Процент износа : " << this->wear << endl;
	cout << "Инвентаризационная стоимость : " << this->price << endl;
}
void inventory::set_data()//реализация метода, отвечающего за ввод данных
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
void inventory::write_file(vector<inventory>& arr, string path)//реализация метода, отвечающего за запись данных в файл
{
	fstream file;//объявление переменной класса фстрим
	file.open(path, fstream::out);//открытие файла
	if (file.is_open())//проверка открытия файла
	{
		file.clear();//очистка файла
		file << arr.size()<<"\n";//запись в файл количества объектов
		for (auto& el : arr)//перебор объектов с помощью цикла фор ич
		{
			//запись данных в файл
			file << el.number << "\n";
			file << el.adres << "\n";
			file << el.year << "\n";
			file << el.area_region << "\n";
			file << el.area_build << "\n";
			file << el.wear << "\n";
			file << el.price << "\n";
		}
		file.close();//закрытие файла
	}
	else
	{
		cout << "Ошибка открытия файла" << endl;
	}
}
void inventory::read_file(vector<inventory>& arr, string path)//реализация метода, отвечающего за чтение данных из файла
{
	fstream file;//создание переменной класса фстрим
	string data;
	int size = 0;
	inventory obj;//создание объекта
	file.open(path, fstream::in);//открытие файла
	if (file.is_open())//проверка открытия файла
	{
		arr.clear();//очистка вектора
		getline(file, data);//считывание количества объектов в файле
		size = stoi(data);
		for (int i = 0; i < size;i++)
		{
			//считывание данных из файла и присвоение этих данных полям
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
			arr.push_back(obj);//добавление объекта в конец вектора
		}
		file.close();//закрытие файла
	}
	else
	{
		cout << "Ошибка открытия файла" << endl;
	}
}
void inventory::delete_obj(vector<inventory>& arr)//реализация метода, отвечающего за удаление объекта
{
	int count = 0;
	int var = 0;
	cout << "Доступные объекты для удаления:" << endl;
	for (auto& el : arr)//перечисление доступных объектов с помощью цикла фор ич
	{
		cout << "Объект - " << count << endl;
		count++;
	}
	cout << "Выберите объект для удаления" << endl;
	cin >> var;
	if (var >= 0 && var < arr.size())//проверка корректности данных
	{
		arr.erase(arr.begin() + var);//удаление данных
		cout << "Объект успешно удален" << endl;
	}
	else
	{
		cout << "Некорректный ввод" << endl;
	}
}
void inventory::search_data(vector<inventory>& arr)//реализация метода, отвечающего за поиск данных
{
	inventory obj;//создание объекта
	//объявление переменных
	string data;
	int var = 0;
	bool check = false;
	obj.print_field();//вывод доступных полей
	cout << "Выберите нужное поле : " << endl;
	cin >> var;
	cout << "Введите данные для поиска : " << endl;
	cin >> data;
	switch (var)//выбор поля
	{
	case 1:
		for (auto& el : arr)//поиск данных с помощью цикла фор ич
		{
			if (el.number == stoi(data))
			{
				el.print_data();//вывод данных объекта
				check = true;
			}
		}
		break;
	case 2:
		for (auto& el : arr)//поиск данных с помощью цикла фор ич
		{
			if (el.adres == data)
			{
				el.print_data();//вывод данных объекта
				check = true;
			}
		}
		break;
	case 3:
		for (auto& el : arr)//поиск данных с помощью цикла фор ич
		{
			if (el.year == stoi(data))
			{
				el.print_data();//вывод данных объекта
				check = true;
			}
		}
		break;
	case 4:
		for (auto& el : arr)//поиск данных с помощью цикла фор ич
		{
			if (el.area_region == stoi(data))
			{
				el.print_data();//вывод данных объекта
				check = true;
			}
		}
		break;
	case 5:
		for (auto& el : arr)//поиск данных с помощью цикла фор ич
		{
			if (el.area_build == stoi(data))
			{
				el.print_data();//вывод данных объекта
				check = true;
			}
		}
		break;
	case 6:
		for (auto& el : arr)//поиск данных с помощью цикла фор ич
		{
			if (el.wear == stoi(data))
			{
				el.print_data();//вывод данных объекта
				check = true;
			}
		}
		break;
	case 7:
		for (auto& el : arr)//поиск данных с помощью цикла фор ич
		{
			if (el.price == stoi(data))
			{
				el.print_data();//вывод данных объекта
				check = true;
			}
		}
		break;
	default://на случай некорректного ввода
		cout << "Некорректный ввод" << endl;
		break;
	}
	if (!check)//на случай отсутствия данных
	{
		cout << "Данные не найдены" << endl;
	}
}
void inventory::search_min(vector<inventory>& arr)//реализация метода, отвечающего за поиск минимального элемента
{
	int min = 1000000;
	int var = 0;
	inventory obj;//создание объекта
	obj.print_mm();//вывод полей для нахождения минимального
	cout << "Выберите нужное поле" << endl;
	cin >> var;
	if (var >= 0 && var < arr.size())//проверка корректности данных
	{
		switch (var)//выбор поля
		{
		case 1:
			for (auto& el : arr)//определение минимального элемента
			{
				if (el.number < min)
				{
					min = el.number;
				}
			}
			cout << "Минимальный элемент = " << min << endl;
			break;
		case 2:
			for (auto& el : arr)//определение минимального элемента
			{
				if (el.year < min)
				{
					min = el.year;
				}
			}
			cout << "Минимальный элемент = " << min << endl;
			break;
		case 3:
			for (auto& el : arr)//определение минимального элемента
			{
				if (el.area_region < min)
				{
					min = area_region;
				}
			}
			cout << "Минимальный элемент = " << min << endl;
			break;
		case 4:
			for (auto& el : arr)//определение минимального элемента
			{
				if (el.area_build < min)
				{
					min = el.area_build;
				}
			}
			cout << "Минимальный элемент = " << min << endl;
			break;
		case 5:
			for (auto& el : arr)//определение минимального элемента
			{
				if (el.wear < min)
				{
					min = el.wear;
				}
			}
			cout << "Минимальный элемент = " << min << endl;
			break;
		case 6:
			for (auto& el : arr)//определение минимального элемента
			{
				if (el.price < min)
				{
					min = el.price;
				}
			}
			cout << "Минимальный элемент = " << min << endl;
			break;
		default://на случай некорректного ввода
			cout << "Некорректный ввод" << endl;
			break;
		}
	}
	else
	{
		cout << "Некорректный ввод" << endl;
	}
}
void inventory::search_max(vector<inventory>& arr)//реализация метода, отвечающего за определение максимального элемента
{
	int max = 0;
	int var = 0;
	inventory obj;//создание объекта
	obj.print_mm();//вывод полей для нахождения максимального элемента
	cout << "Выберите нужное поле" << endl;
	cin >> var;
	if (var >= 0 && var < arr.size())//проверка корректности данных
	{
		switch (var)//выбор поля
		{
		case 1:
			for (auto& el : arr)//определения максимального элемента
			{
				if (el.number > max)
				{
					max = el.number;
				}
			}
			cout << "Минимальный элемент = " << max << endl;
			break;
		case 2:
			for (auto& el : arr)//определения максимального элемента
			{
				if (el.year > max)
				{
					max = el.year;
				}
			}
			cout << "Минимальный элемент = " << max << endl;
			break;
		case 3:
			for (auto& el : arr)//определения максимального элемента
			{
				if (el.area_region > max)
				{
					max = area_region;
				}
			}
			cout << "Минимальный элемент = " << max << endl;
			break;
		case 4:
			for (auto& el : arr)//определения максимального элемента
			{
				if (el.area_build > max)
				{
					max = el.area_build;
				}
			}
			cout << "Минимальный элемент = " << max << endl;
			break;
		case 5:
			for (auto& el : arr)//определения максимального элемента
			{
				if (el.wear > max)
				{
					max = el.wear;
				}
			}
			cout << "Минимальный элемент = " << max << endl;
			break;
		case 6:
			for (auto& el : arr)//определения максимального элемента
			{
				if (el.price > max)
				{
					max = el.price;
				}
			}
			cout << "Минимальный элемент = " << max << endl;
			break;
		default://на случай некоректного ввода
			cout << "Некорректный ввод" << endl;
			break;
		}
	}
	else
	{
		cout << "Некорректный ввод" << endl;
	}
}
void inventory::sort_field(vector<inventory>& arr)//реализация метода, отвечающего за сортировку полей
{
	inventory obj;//создание объекта
	int var = 0;
	obj.print_field();//вывод доступных полей
	cout << "Выберите нужное поле" << endl;
	cin >> var;
	if (var >= 0 && var < arr.size())//проверка корректности данных
	{
		switch (var)//выбор поля
		{
		case 1:
			sort(arr.begin(), arr.end(), [](const inventory i1, const inventory i2) {return i1.number < i2.number;});//сортировка
			break;
		case 2:
			sort(arr.begin(), arr.end(), [](const inventory i1, const inventory i2) {return i1.adres < i2.adres;});//сортировка
			break;
		case 3:
			sort(arr.begin(), arr.end(), [](const inventory i1, const inventory i2) {return i1.year < i2.year;});//сортировка
			break;
		case 4:
			sort(arr.begin(), arr.end(), [](const inventory i1, const inventory i2) {return i1.area_region < i2.area_region;});//сортировка
			break;
		case 5:
			sort(arr.begin(), arr.end(), [](const inventory i1, const inventory i2) {return i1.area_build < i2.area_build;});//сортировка
			break;
		case 6:
			sort(arr.begin(), arr.end(), [](const inventory i1, const inventory i2) {return i1.wear < i2.wear;});//сортировка
			break;
		case 7:
			sort(arr.begin(), arr.end(), [](const inventory i1, const inventory i2) {return i1.price < i2.price;});//сортировка
			break;
		}
	}
}
