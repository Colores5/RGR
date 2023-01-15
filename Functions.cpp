#include "Functions.h"

void DataInitialization()
{
	//�������� ��������� ����, � ������� ����� ��������� ���������� ����������. �.�. �������� �����
	ofstream _buf("Buffer.txt");

	if (!_buf)
		cout << "������ �������� ��������� �����!" << endl;

	_buf.close();
}

void DataEntry()
{
	//���� ������ �������

	//��������� ����������
	string _surname;
	int _measurements;
	string _product;
	int n;

	cout << "������� ���������� �������(����� �����): ";
	cin >> n;

	//��������� �������� ���� � ���������� � ���� ������
	ofstream record("Buffer.txt", ios::app);

	if (record) {
		record << n << endl;

		for (int i = 0; i < n; i++) {
			cout << "������� �������: ";
			cin >> _surname;

			cout << "������� ������ (� ��): ";
			cin >> _measurements;

			cout << "������� ��� �������: ";
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
		cout << "������ �������� �����!" << endl;

	record.close();
}

void DataReading(string fileName)
{
	//������ ������ �� �����

	ifstream reading(fileName);
	ofstream record("Buffer.txt", ios::out);

	if (reading) {
		if (record) {

			//��������� ����������
			string _surname;
			int _measurements;
			string _product;
			int n;

			//��������� ������ �� �����

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

			cout << "������ �������!" << endl;
		}
		else
			cout << "������ �������� ������!" << endl;
	}
	else
		cout << "������ �������� �����!" << endl;

	//�������� �����
	reading.close();
	record.close();

}

void Print()
{
	ifstream reading("Buffer.txt");

	if (reading) {

		//��������� ����������
		string _surname;
		int _measurements;
		string _product;
		int n;

		//������� ������ �� ��������� �������
		reading >> n; 
		cout << "����������� ������: " << n << endl << endl;

		for (int i = 0; i < n; i++) {
			cout << "������ �� ������ �" << i + 1 << endl;

			reading >> _surname;
			cout << "�������: " << _surname << endl;

			reading >> _measurements;
			cout << "������ (� ��): " << _measurements << endl;

			reading >> _product;
			cout << "��� �������: " << _product << endl;

			cout << "_________________________________________________" << endl;
		}
	}
	else
		cout << "������ �������� �����!" << endl;

	//��������� ����
	reading.close();
}

bool DataCleaning()
{
	//������� ������

	bool clear = false;

	//��������� ����
	fstream _buf("Buffer.txt", ios::out);

	if (!_buf)
		cout << "������ �������� ��������� �����" << endl;

	//�������
	_buf.clear();

	//��������, ��� ���� ����
	if (_buf.peek() == EOF)
		clear = true;
	else
		clear = false;

	_buf.close();

	return clear;
}

void DataChange()
{
	//��������� ������

	//�������� ��� ��� ������
	//������� ����� � ����� ������ ���������� ������ � ����
	//������ �� ������������ � ������� ��� ������

	Copy();

	ifstream reading("Buffer_.txt");
	ofstream record("Buffer.txt", ios::out);

	if (reading) {
		if (record) {
			//��������� ����������
			string _surname;
			int _measurements;
			string _product;
			int n, _n;

			//��������� �� ��������� ����� � �����
			reading >> n;

			cout << "�������� ����� ����������� �������� (�� 1 �� " << n << "): ";
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
						cout << "������� �������: ";
						cin >> _surname;

						cout << "������� ������ (� ��): ";
						cin >> _measurements;

						cout << "������� ��� �������: ";
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

				cout << "������ ��������!" << endl;
			}
			else
				cout << "����� ������ �� �����!" << endl;
		}
		else
			cout << "������ �������� �����!" << endl;
	}
	else
		cout << "������ �������� ��������� �����!" << endl;

	record.close();
	reading.close();

	remove("Buffer_.txt");
}

void Copy() {
	//����������� � ����� ����

	ifstream reading("Buffer.txt");
	ofstream record("Buffer_.txt", ios::out);

	if (reading) {
		if (record) {
			//��������� ����������
			string _surname;
			int _measurements;
			string _product;
			int n;

			//��������� �� ��������� ����� � �����
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
			cout << "������ �������� �����!" << endl;
	}
	else
		cout << "������ �������� ��������� �����!" << endl;

	record.close();
	reading.close();

}

int AmountOfData()
{
	//������� ���������� ������ �� �����
	ifstream _buf("Buffer.txt");
	int n;

	if (_buf) {
		_buf >> n;
	}
	else
		cout << "������ �������� ��������� �����!" << endl;

	_buf.close();

	return n;
}

void DeleteData()
{
	//�������� ������

	//���������� ������
	//�������������� � �������� �����
	//����� ����������

	Copy();

	ifstream reading("Buffer_.txt");
	ofstream record("Buffer.txt", ios::out);

	if (reading) {
		if (record) {
			//��������� ����������
			string _surname;
			int _measurements;
			string _product;
			int n, _n;

			//��������� �� ��������� ����� � �����
			reading >> n;
			int b = n - 1;

			cout << "�������� ����� ���������� �������� (�� 1 �� " << n << "): ";
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
				cout << "������ �������!" << endl;
			}
			else
				cout << "����� ������ �� �����!" << endl;
		}
		else
			cout << "������ �������� �����!" << endl;
	}
	else
		cout << "������ �������� ��������� �����!" << endl;

	record.close();
	reading.close();

	remove("Buffer_.txt");

}

void AddData()
{
	//�������� ������

	//��������� ����������
	string _surname;
	int _measurements;
	string _product;
	int n = AmountOfData() + 1;

	//��������� �������� ����
	ofstream record("Buffer.txt", ios::app);
	ofstream record_("Buffer.txt", ios::out | ios::in);

	if (record_) {
		record_ << n << endl;
	}
	else
		cout << "������ �������� ��������� �����!" << endl;

	if (record) {
		record << endl;

		cout << "������� �������: ";
		cin >> _surname;

		cout << "������� ������ (� ��): ";
		cin >> _measurements;

		cout << "������� ��� �������: ";
		cin >> _product;

		record << _surname << endl;
		record << _measurements << endl;
		record << _product;
	}
	else
		cout << "������ �������� �����!" << endl;

	record.close();
	record_.close();
}

void SaveData(string fileName)
{
	//���������� ������

	ifstream reading("Buffer.txt");
	ofstream record(fileName, ios::out);

	if (reading) {
		if (record) {

			//��������� ����������
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

			cout << "������ ��������� � ����� " << fileName << endl;

		}
		else
			cout << "������ �������� ��������� ����� " << endl;
	}
	else
		cout << "������ �������� �����" << endl;

	record.close();
	reading.close();

}