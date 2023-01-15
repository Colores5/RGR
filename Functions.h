#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

//прототипы функций
void DataInitialization();//инициализация данных
void DataEntry();//ввод данных вручную
void DataReading(string fileName);//чтение данных
void Print();//вывод данных
bool DataCleaning();//очистка данных
void DataChange();//изменение данных
void Copy();//копирование данных
int AmountOfData();//количество данных
void DeleteData();//удаление данных
void AddData();//добавление данных
void SaveData(string fileName);//сохранение данных
