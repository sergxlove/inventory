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
	int number;//����������� �����
	string adres;//�����
	int year;//��� ���������
	int area_region;//������� �������
	int area_build;//������� ���������
	int wear;//������� �����
	int price;//������������������ ���������
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
		cout << "�������� �����: " << endl;
		cin >> var_switch;
		switch (var_switch)
		{
		case 1:
			invent.set_data();
			arr.push_back(invent);
			cout << "������ ������ �������" << endl;
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
			cout << "��������� ���������" << endl;
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
	cout << "��������� ������ : " << endl;
	cout << "1 - ���� ������" << endl;
	cout << "2 - ���������� ������ � ����" << endl;
	cout << "3 - ������ ������ �� �����" << endl;
	cout << "4 - �������� �������" << endl;
	cout << "5 - ����� ������ �� �����" << endl;
	cout << "6 - ����� ������������ ��������" << endl;
	cout << "7 - ����� ������������� ��������" << endl;
	cout << "8 - ���������� �� ����" << endl;
	cout << "9 - ����� ���������" << endl;
	cout << "10 - ����� �� ���������" << endl;
}

void inventory::set_data()
{
	cout << "������� ����������� ����� :\t";
	cin >> this->number;
	cout << "������� ����� :\t";
	cin >> this->adres;
	cout << "������� ��� ��������� :\t";
	cin >> this->year;
	cout << "������ ������� ������� :\t";
	cin >> this->area_region;
	cout << "������� ������� ��������� :\t";
	cin >> this->area_build;
	cout << "������� ������� ������ :\t";
	cin >> this->wear;
	cout << "������� ������������������ ��������� :\t";
	cin >> this->price;
}

void inventory::write_file(vector<inventory>& arr, string path)
{
}
