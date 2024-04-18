 #include <iostream>

void myswap(int num1, int num2) {
	int tmp = num1;
	num1 = num2;
	num2 = tmp;
}

void pswap(int* pointer1, int* pointer2) {
	int tmp = *pointer1;
	*pointer1 = *pointer2;
	*pointer2 = tmp;
}

void p_sum_arr(int arr[], const int length, int* var);





int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;

	//указатели на переменные
	n = 7;
	std::cout << "n = " << n << std::endl;//обращение к значению переменной
	std::cout << "&n = " << &n << std::endl;//вывод адреса переменной n с помощью орепации &

	int* pn = &n;//создание указателя на область памяти типа int 
	std::cout << "pn = " << pn << std::endl;//вывод значения указателя (16 ричный)
	std::cout << "pn = " << *pn << std::endl;//вывод значения n через разыменование указателя

	*pn = 15;//изменение значения n через разыменование указателя
	std::cout << "n = " << n << std::endl;

	std::cout << "-----------------------------\n";

	m = 42;
	std::cout << "m = " << m << std::endl;
	std::cout << "&m = " << &m << std::endl;

	pn = &m;//"перенаправление" указателя на переменную m
	std::cout << "pn = " << pn << std::endl;
	std::cout << "*pn = " << *pn << std::endl;

	int* pm = &m;
	std::cout << "pm = " << pm << std::endl;

	//Указатели и массивы
	const int size = 5;
	int arr[size]{ 30, 40, 50, 60, 70 };
	int* parr2 = &arr[2];
	std::cout << parr2 << std::endl;
	std::cout << *parr2 << std::endl;

	parr2++;
	std::cout << parr2 << std::endl;
	std::cout << *parr2 << std::endl;

	parr2 = &arr[0];
	for (int i = 0; i < size; i++)
		std::cout << *(parr2 + i) << ' ';
	std::cout << std::endl;


	//Указатели и функции
	n = 7; m = 15;

	std::cout << n << ' ' << m << std::endl;
	//myswap(n, m);не работает, т к параметры это копии передаваемых значений
	pswap(&n, &m);

	std::cout << n << ' ' << m << std::endl;

	//Задача 1.Сумма массива в указатель
	std::cout << "Задача1.\nМассив: ";
	const int size1 = 5;
	int arr1[size1]{ 15, 5, 6, 7, 10 };
	for (int i = 0; i < size1; i++)
		std::cout << arr1[i] << ' ';
	std::cout << std::endl;

	int sum;
	p_sum_arr(arr1, size1, &sum);
	std::cout << "Сумма элементов = " << sum << std::endl;












	return 0;
}

void p_sum_arr(int arr[], const int length, int* var) {
	*var = 0;//в переменной на которую направлен указатель теперь лежит 0
	for (int i = 0; i < length; i++)
		*var += arr[i];

}