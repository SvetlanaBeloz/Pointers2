#include <iostream>
#include <time.h>

//  1. Написать такие функции для работы с динамическим массивом :
//  ■ Функция распределения динамической памяти;
//  ■ Функция инициализации динамического массива;
//  ■ Функция печати динамического массива;
//  ■ Функция удаления динамического массива;
//  ■ Функция добавления элемента в конец массива;
//  ■ Функция вставки элемента по указанному индексу;
//  ■ Функция удаления элемента по указанному индексу.

void AllocateMemory(int*& arr, int size)
{
	arr = new int[size];
}

void FillArray(int*& arr, int size)
{
	srand(time(0));

	for (int i = 0; i < size; i++)
		arr[i] = rand() % 101;
}
void ShowArray(int*& arr, int size)
{
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

void DeleteMemory(int*& arr)
{
	delete[] arr;
}

void AddElementEndArray(int*& arr, int& size, int number)
{
	int* temp = new int[size + 1];
	for (int i = 0; i < size; i++)
		temp[i] = arr[i];
	temp[size] = number;
	size++;
	delete[] arr;
	arr = temp;
}

void InsertElementArray(int*& arr, int& size, int number, int index)
{
	size++;
	int* temp = new int[size];
	for (int i = 0; i < size; i++)
	{
		if (i < index)
			temp[i] = arr[i];
		else if (i == index)
			temp[i] = number;
		else
			temp[i] = arr[i - 1];
	}
	delete[] arr; 
	arr = temp;
}
void DeleteElement(int*& arr, int& size, int index)
{
	size--;
	int* temp = new int[size];
	for (int i = 0; i < size; i++)
	{
		if (i < index)
			temp[i] = arr[i];
		else if (i >= index)
			temp[i] = arr[i + 1];
	}
	delete[] arr;
	arr = temp;
}
//  2. Написать функцию, получающую указатель на динамический массив и его размер.Функция должна удалить из массива все простые числа 
//  и вернуть указатель на новый динамический массив

bool isPrime(int n)
{
	for (int i = 2; i < n; i++)
		if (n % i == 0) return false;
	return true;
}
void DeletePrimeNumber(int*& arr, int& size)
{
	int newSize = 0;
	int* temp = new int[size];
	for (int i = 0; i < size; i++)
	{
		if (!isPrime(arr[i])) {
			temp[newSize++] = arr[i];
		}
	}
	int* result = new int[newSize];
	for (int i = 0; i < newSize; i++)
	{ 
		result[i] = temp[i];
	}
	delete[] arr;
	delete[] temp;
	arr = result;
	size = newSize;
}

//  3. Написать функцию, получающую указатель на статический массив и его размер.Функция распределяет положительные, отрицательные 
//  и нулевые элементы в отдельных динамических массивы.

void AllocationNumbers(int* Arr, int size)
{
	int plusSize = 0;
	int minusSize = 0;
	int zeroSize = 0;
	int* plus = new int[size];
	int* minus = new int[size];
	int* zero = new int[size];


	for (int i = 0; i < size; i++)
	{
		if (Arr[i] > 0)
			plus[plusSize++] = Arr[i];
		else if (Arr[i] < 0)
			minus[minusSize++] = Arr[i];
		else zero[zeroSize++] = Arr[i];
	}
	int* plusArr = new int[plusSize];
	int* minusArr = new int[minusSize];
	int* zeroArr = new int[zeroSize];
	for (int i = 0; i < plusSize; i++) {
		plusArr[i] = plus[i];
		std::cout << plusArr[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < minusSize; i++) {
		minusArr[i] = minus[i];
		std::cout << minusArr[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < zeroSize; i++) {
		zeroArr[i] = zero[i];
		std::cout << zeroArr[i] << " ";
	}
	std::cout << std::endl;
}

int main()
{
	int size = 10;
	int* arr;
	AllocateMemory(arr, size);
	FillArray(arr, size);
	ShowArray(arr, size);
	std::cout << std::endl;
	AddElementEndArray(arr, size, 15);
	ShowArray(arr, size);
	std::cout << std::endl;
	InsertElementArray(arr, size, 25, 6);
	ShowArray(arr, size);
	std::cout << std::endl;
	DeleteElement(arr, size, 8);
	ShowArray(arr, size);
	std::cout << std::endl;
	DeletePrimeNumber(arr, size);
	ShowArray(arr, size);
	std::cout << std::endl;
	const int sizeNew = 20;
	int Arr[sizeNew]{ 20, -15, 0, 14, 59, 0, 26, -101, 69, -28, 92, -55, 0, 33, 45, -74, 66, 13, -49, 0 };
	AllocationNumbers(Arr, sizeNew);

}