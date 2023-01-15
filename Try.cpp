#include "Functions.h"

int _stateMenu;
void Menu() {
	cout << "Выберите действие:" << endl
		<< "(0) Выход из программы." << endl
		<< "(1) Ввод данных." << endl
		<< "(2) Вывод данных." << endl
		<< "(3) Изменение данных." << endl
		<< "(4) Удаление данных." << endl
		<< "(5) Добавление данных." << endl
		<< "(6) Сохранение данных." << endl
		<< "Ваш выбор: ";
	cin >> _stateMenu;
}

/*
			Данные:
			Фамилия
			Замеры
			Изделие
*/

int main() {
	////русификация консоли ввода/вывода
	SetConsoleCP(1251);	//установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода

	DataInitialization();

	Menu();

	int _actions;
	string fileName;

	while (_stateMenu != 0) 
	{
		switch (_stateMenu)
		{
		case 1:
			system("cls");//очистка консоли

			cout << "Ввод вручную или из файла?(1 либо 2): ";
			cin >> _actions;

			system("cls");//очистка консоли

			if (_actions == 1) {
				//ввод вручную
				DataEntry();
			}
			else
			{
				//чтение из файла
				cout << "Введите название файла(С его разрешением. Пример: .txt ): ";
				cin >> fileName;

				DataReading(fileName);
			}

			system("pause");//задержка консоли
			system("cls");//очистка консоли
			Menu();
			break;
		/////////////////////////////////////////
		case 2:
			system("cls");//очистка консоли

			Print();

			system("pause");//задержка консоли
			system("cls");//очистка консоли
			Menu();
			break;
		/////////////////////////////////////////
		case 3:
			system("cls");//очистка консоли

			DataChange();

			system("pause");//задержка консоли
			system("cls");//очистка консоли
			Menu();
			break;
		/////////////////////////////////////////
		case 4:
			system("cls");//очистка консоли

			DeleteData();

			system("pause");//задержка консоли
			system("cls");//очистка консоли
			Menu();
			break;
		/////////////////////////////////////////
		case 5:
			system("cls");//очистка консоли

			AddData();

			system("pause");//задержка консоли
			system("cls");//очистка консоли
			Menu();
			break;
		/////////////////////////////////////////
		case 6:
			system("cls");//очистка консоли

			//запись в файл
			cout << "Введите название файла(С его разрешением. Пример: .txt ): ";
			cin >> fileName;

			system("cls");//очистка консоли

			SaveData(fileName);

			system("pause");//задержка консоли
			system("cls");//очистка консоли
			Menu();
			break;
		/////////////////////////////////////////
		default:
			cout << "Неправильно выбран пункт в меню" << endl;
			system("pause");//задержка консоли
			system("cls");//очистка консоли
			return main();
		}
	}

	system("cls"); 
	if (DataCleaning())
		cout << "Данные очищены!" << endl;
	else
		cout << "Данные HE очищены!" << endl;

	cout << "Работа завершена." << endl;
	system("pause");

	return 0;
}
