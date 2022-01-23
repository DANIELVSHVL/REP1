#include "Function.h"
int _stateMenu;
void Menu() {
	cout << "Выберите действие: " << endl
		<< "0- Выход из программы" << endl
		<< "1- Ввод данных" << endl
		<< "2- Вывод" << endl
		<< "3- Изменение" << endl
		<< "4- Удаление" << endl
		<< "5- Добавление" << endl
		<< "6- Сортировка" << endl
		<< "7- Сохранение" << endl;
	cout << "Ваш выбор: ";
	cin >> _stateMenu;
}
void main() {
	//Руссификация ввода и вывода
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Menu(); //Вызываем главную функцию- меню

	int _actions, amountofData = 0;
	string fileName;

	Data* d = new Data[amountofData];

	while (_stateMenu != 0)
	{
		switch (_stateMenu)
		{
		case 1:
			system("cls");

			cout << "Ввод вручную или из файла? ";
			cin >> _actions;

			system("cls");

			if (_actions == 1) {
				DataEntry(d, amountofData);
			}
			else {
				ReadingData(d, amountofData, "Input.txt");
			}
			system("pause");
			system("cls");
			Menu();
			break;
		case 2:
			system("cls");

			if (amountofData != 0) {
				Print(d, amountofData);
			}
			else
				cout << "Данные пусты" << endl;
			system("pause");
			system("cls");
			Menu();
			break;
		case 3:
			system("cls");

			if (amountofData != 0) {
				DataChange(d, amountofData);
			}
			else
				cout << "Данные пусты!" << endl;
			system("pause");
			system("cls");
			Menu();
			break;
		case 4:
			system("cls");

			if (amountofData != 0) {
				DeleteData(d, amountofData);
			}
			else
				cout << "Данные пусты!" << endl;
			system("pause");
			system("cls");
			Menu();
			break;

		case 5:
			system("cls");
			if (amountofData != 0) {
				DeleteData(d, amountofData);
			}
			else
				cout << "Данные пусты!" << endl;
			system("pause");
			system("cls");
			Menu();
			break;
		case 6:
			system("cls");
			if (amountofData != 0) {
				DataSorting(d, amountofData);
			}
			else
				cout << "Данные пусты!" << endl;
			system("pause");
			system("cls");
			Menu();
			break;
		case 7:
			system("cls");

			cout << "Введите название файла: ";
			cin >> fileName;

			if (amountofData != 0) {
				SavingData(d, amountofData, fileName);
			}
			else
				cout << "Данные пусты!" << endl;
			system("pause");
			system("cls");
			Menu();
			break;
		default:
			cout << "Неверно введен номер действия!" << endl;
		}
	}
}