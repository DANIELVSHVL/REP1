#include "Function.h"
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

//correct
void DataEntry(Data* (&d), int& n){
	cout << "Введите количество данных: ";
	cin >> n;
	// Выделяем память
	d = new Data[n];

	for (int i = 0; i < n; i++) {
		cout << "Введите ФИО: ";
		cin >> d[i]._initial.surname;
		cin >> d[i]._initial.patronymic;
		cin >> d[i]._initial.name;

		cout << "Введите дату: ";
		cin >> d[i]._date.day;
		cin >> d[i]._date.month;
		cin >> d[i]._date.year;

		cout << "Введите адрес: ";
		cin >> d[i]._adress.city;
		cin >> d[i]._adress.home;

		cout << "___________________________" << endl;

	}
}
//correct
void ReadingData(Data* (&d), int& n, string fileName)
{
	ifstream reading(fileName);

	if (reading) {

		reading >> n;

		d = new Data[n];

		for (int i = 0; i < n; i++) {
			reading >> d[i]._initial.surname;
			reading >> d[i]._initial.patronymic;
			reading >> d[i]._initial.name;

			reading >> d[i]._date.day;
			reading >> d[i]._date.month;
			reading >> d[i]._date.year;

			reading >> d[i]._adress.city;
			reading >> d[i]._adress.home;
		}
        cout << "Данные считаны! " << endl;
	}
	else
	cout << "Ошибка открытия файла!" << endl;
	reading.close();
}
//correct
void Print(Data* d, int n){
	for (int i = 0; i < n; i++) {
		cout << "Данные N: " << i + 1 << ":" << endl;

		cout << "ФИО: " << d[i]._initial.surname << " " << d[i]._initial.patronymic << " " << d[i]._initial.name << endl;
		cout << "Дата: " << d[i]._date.day << " " << d[i]._date.month << " " << d[i]._date.year << endl;
		cout << "Адрес: " << d[i]._adress.city << " " << d[i]._adress.home << endl;

		cout << "___________________________" << endl;
	}
}
//correct
void DataChange(Data* (&d), int n)
{
	int _n;
	cout << " Введите номер элемента (от 1 до " << n << "): ";
	cin >> _n;
	_n--;

	system("cls");

	if (_n >= 0 && _n < n) {
		cout << "Введите ФИО: ";
		cin >> d[_n]._initial.surname;
		cin >> d[_n]._initial.patronymic;
		cin >> d[_n]._initial.name;

		cout << "Введите дату: ";
		cin >> d[_n]._date.day;
		cin >> d[_n]._date.month;
		cin >> d[_n]._date.year;

		cout << "Введите адрес: ";
		cin >> d[_n]._adress.city;
		cin >> d[_n]._adress.home;

		system("cls");

		cout << "Данные изменены!" << endl;
	}
//else
	
}  //correct
//correct
void DeleteData(Data* (&d), int& n) {
	int _n;
	cout << " Введите номер элемента (от 1 до " << n << "): ";
	cin >> _n;
	_n--;

	system("cls");

	if (_n >= 0 && _n < n) {
		Data* buf = new Data[n];

		Copy(buf, d, n);

		--n;
		d = new Data[n];
		int q = 0;

		for (int i = 0; i <= n; i++) {
			if (i != _n) {
				d[q] = buf[i];
				++q;
			}
		}
		system("cls");
		delete[]buf;

		cout << "Данные удалены!" << endl;
	}
	else
		cout << "Номер введен неверно!" << endl;
}
//correct
void Copy(Data* (&d_n), Data* (&d_o), int n) {
	for (int i = 0; i < n; i++) {
		d_n[i] = d_o[i];
	}
}
//correct
void Copy(Data& d_n, Data& d_o) 
{
	d_n._initial.surname = d_o._initial.surname;
	d_n._initial.patronymic = d_o._initial.patronymic;
	d_n._initial.name = d_o._initial.name;

	d_n._date.day = d_o._date.day;
	d_n._date.month = d_o._date.month;
	d_n._date.year = d_o._date.year;

	d_n._adress.city = d_o._adress.city;
	d_n._adress.home = d_o._adress.home;
}
void AddDate(Data* (&d), int& n){ //date or data
	Data* buf;
	buf = new Data[n];

	Copy(buf, d, n);

	n++;
	d = new Data[n];

	Copy(d, buf, --n);

	cout << "Введите ФИО: ";
	cin >> d[n]._initial.surname >> d[n]._initial.name >> d[n]._initial.patronymic;

	cout << "Введите дату: ";
	cin >> d[n]._date.day >> d[n]._date.month>>d[n]._date.year;

	cout << "Введите адрес: ";
	cin >> d[n]._adress.city >> d[n]._adress.home;

	system("cls");

	cout << "Данные добавлены!" << endl;

	delete[]buf;
}
void DataSorting(Data* d, int n)
{
	//временная переменная
	Data buf;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++){
		    if (d[i]._initial.surname > d[j]._initial.surname) {
			Copy(buf, d[j]);
			Copy(d[j], d[i]);
			Copy(d[i], d[i]);
		    }
		}
	}
	cout << "Данные отсортированны! " << endl;
}
void SavingData(Data* d, int n, string fileName) {

	ofstream record(fileName);

	if (record) {
		record << n << endl;

		for (int i = 0; i < n; i++) {
			record << d[i]._initial.surname << endl;
			record << d[i]._initial.name << endl;
			record << d[i]._initial.patronymic << endl;

			record << d[i]._date.day << " ";
			record << d[i]._date.month << " ";
			record << d[i]._date.year << endl;

			record << d[i]._adress.city << " ";
			if (i < n - 1)
				record << d[i]._adress.home << endl;
			else
				record << d[i]._adress.home;
		}
	}
	else
		cout << "Ошибка открытия файла! " << endl;
	record.close();
}
			
			