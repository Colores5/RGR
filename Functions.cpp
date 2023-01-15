#include "Functions.h"

void DataInitialization()
{
	//создадим временный файл, в котором будет храниться актуальная информация. Т.е. создадим буфер
	ofstream _buf("Buffer.txt");

	if (!_buf)
		cout << "Ошибка создания буферного файла!" << endl;

	_buf.close();
}

void DataEntry()
{
	//ввод данных вручную

	//временные переменные
	string _surname;
	int _measurements;
	string _product;
	int n;

	cout << "Введите количество заказов(Целые числа): ";
	cin >> n;

	//открываем буферный файл и записываем в него данные
	ofstream record("Buffer.txt", ios::app);

	if (record) {
		record << n << endl;

		for (int i = 0; i < n; i++) {
			cout << "Введите Фамилию: ";
			cin >> _surname;

			cout << "Введите замеры (в мм): ";
			cin >> _measurements;

			cout << "Введите тип изделия: ";
			cin >> _product;

			record << _surname << endl;
			record << _measurements << endl;
			if (i < n - 1)
				record << _product << endl;
			else
				record << _product;

			cout << "_____________________________" << endl;
		}
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	record.close();
}

void DataReading(string fileName)
{
	//чтение данных из файла

	ifstream reading(fileName);
	ofstream record("Buffer.txt", ios::out);

	if (reading) {
		if (record) {

			//временные переменные
			string _surname;
			int _measurements;
			string _product;
			int n;

			//считываем данные из файла

			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++) {
				reading >> _surname;

				reading >> _measurements;

				reading >> _product;

				record << _surname << endl;
				record << _measurements << endl;
				if (i < n - 1)
					record << _product << endl;
				else
					record << _product;
			}

			cout << "Данные считаны!" << endl;
		}
		else
			cout << "Ошибка открытия буфера!" << endl;
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	//закрытие файла
	reading.close();
	record.close();

}

void Print()
{
	ifstream reading("Buffer.txt");

	if (reading) {

		//временные переменные
		string _surname;
		int _measurements;
		string _product;
		int n;

		//выводим данные об указзаной единице
		reading >> n; 
		cout << "Количесство данных: " << n << endl << endl;

		for (int i = 0; i < n; i++) {
			cout << "Данные об заказе №" << i + 1 << endl;

			reading >> _surname;
			cout << "Фамилия: " << _surname << endl;

			reading >> _measurements;
			cout << "Замеры (в мм): " << _measurements << endl;

			reading >> _product;
			cout << "Тип изделия: " << _product << endl;

			cout << "_________________________________________________" << endl;
		}
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	//закрываем файл
	reading.close();
}

bool DataCleaning()
{
	//очистка буфера

	bool clear = false;

	//открываем файл
	fstream _buf("Buffer.txt", ios::out);

	if (!_buf)
		cout << "Ошибка открытия буферного файла" << endl;

	//очищаем
	_buf.clear();

	//проверка, что файл чист
	if (_buf.peek() == EOF)
		clear = true;
	else
		clear = false;

	_buf.close();

	return clear;
}

void DataChange()
{
	//изменение данных

	//сохраним еще раз данные
	//очистим буфер и снова начнем записывать данные в него
	//дойдем до необходимого и изменим его данные

	Copy();

	ifstream reading("Buffer_.txt");
	ofstream record("Buffer.txt", ios::out);

	if (reading) {
		if (record) {
			//временные переменные
			string _surname;
			int _measurements;
			string _product;
			int n, _n;

			//считываем из буферного файла в новый
			reading >> n;

			cout << "Выберите номер изменяемого элемента (от 1 до " << n << "): ";
			cin >> _n;
			_n--;

			system("cls");

			record << n << endl;

			if (_n >= 0 && _n < n) {

				for (int i = 0; i < n; i++) {
					if (i != _n) {
						reading >> _surname;
						record << _surname << endl;

						reading >> _measurements;
						record << _measurements << endl;

						reading >> _product;
						if (i < n - 1)
							record << _product << endl;
						else
							record << _product;
					}
					else {
						cout << "Введите фамилию: ";
						cin >> _surname;

						cout << "Введите замеры (в мм): ";
						cin >> _measurements;

						cout << "Введите тип изделия: ";
						cin >> _product;

						record << _surname << endl;
						record << _measurements << endl;
						if (i < n - 1)
							record << _product << endl;
						else
							record << _product;

						reading >> _surname;
						reading >> _measurements;
						reading >> _product;

					}
				}

				cout << "Данные изменены!" << endl;
			}
			else
				cout << "Номер введен не верно!" << endl;
		}
		else
			cout << "Ошибка открытия файла!" << endl;
	}
	else
		cout << "Ошибка открытия буферного файла!" << endl;

	record.close();
	reading.close();

	remove("Buffer_.txt");
}

void Copy() {
	//копирование в новый файл

	ifstream reading("Buffer.txt");
	ofstream record("Buffer_.txt", ios::out);

	if (reading) {
		if (record) {
			//временные переменные
			string _surname;
			int _measurements;
			string _product;
			int n;

			//считываем из буферного файла в новый
			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++) {
				reading >> _surname;
				record << _surname << endl;

				reading >> _measurements;
				record << _measurements << endl;

				reading >> _product;
				if (i < n - 1)
					record << _product << endl;
				else
					record << _product;
			}
		}
		else
			cout << "Ошибка открытия файла!" << endl;
	}
	else
		cout << "Ошибка открытия буферного файла!" << endl;

	record.close();
	reading.close();

}

int AmountOfData()
{
	//выводит количество данных из файла
	ifstream _buf("Buffer.txt");
	int n;

	if (_buf) {
		_buf >> n;
	}
	else
		cout << "Ошибка открытия буферного файла!" << endl;

	_buf.close();

	return n;
}

void DeleteData()
{
	//удаление данных

	//запоминаем данные
	//перезаписываем в исходный буфер
	//кроме удаляемого

	Copy();

	ifstream reading("Buffer_.txt");
	ofstream record("Buffer.txt", ios::out);

	if (reading) {
		if (record) {
			//временные переменные
			string _surname;
			int _measurements;
			string _product;
			int n, _n;

			//считываем из буферного файла в новый
			reading >> n;
			int b = n - 1;

			cout << "Выберите номер удаляемого элемента (от 1 до " << n << "): ";
			cin >> _n;
			_n--;

			system("cls");

			record << b << endl;

			if (_n >= 0 && _n < n) {

				for (int i = 0; i < n; i++) {
					if (i != _n) {
						reading >> _surname;
						record << _surname << endl;
						reading >> _measurements;
						record << _measurements << endl;
						reading >> _product;
						if (i < n - 1)
							record << _product << endl;
						else
							record << _product;
					}
					else {
						reading >> _surname;
						reading >> _measurements;
						reading >> _product;
					}
				}
				cout << "Данные удалены!" << endl;
			}
			else
				cout << "Номер введен не верно!" << endl;
		}
		else
			cout << "Ошибка открытия файла!" << endl;
	}
	else
		cout << "Ошибка открытия буферного файла!" << endl;

	record.close();
	reading.close();

	remove("Buffer_.txt");

}

void AddData()
{
	//добавить данные

	//временные переменные
	string _surname;
	int _measurements;
	string _product;
	int n = AmountOfData() + 1;

	//открываем буферный файл
	ofstream record("Buffer.txt", ios::app);
	ofstream record_("Buffer.txt", ios::out | ios::in);

	if (record_) {
		record_ << n << endl;
	}
	else
		cout << "Ошибка открытия буферного файла!" << endl;

	if (record) {
		record << endl;

		cout << "Введите фамилию: ";
		cin >> _surname;

		cout << "Введите замеры (в мм): ";
		cin >> _measurements;

		cout << "Введите тип изделия: ";
		cin >> _product;

		record << _surname << endl;
		record << _measurements << endl;
		record << _product;
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	record.close();
	record_.close();
}

void SaveData(string fileName)
{
	//сохранение данных

	ifstream reading("Buffer.txt");
	ofstream record(fileName, ios::out);

	if (reading) {
		if (record) {

			//временные переменные
			string _surname;
			int _measurements;
			string _product;
			int n;

			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++) {
				reading >> _surname;
				record << _surname << endl;

				reading >> _measurements;
				record << _measurements << endl;

				reading >> _product;
				if (i < n - 1)
					record << _product << endl;
				else
					record << _product;
			}

			cout << "Данные сохранены в файле " << fileName << endl;

		}
		else
			cout << "Ошибка открытия буферного файла " << endl;
	}
	else
		cout << "Ошыбка открытия файла" << endl;

	record.close();
	reading.close();

}
