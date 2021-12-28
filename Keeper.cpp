#include "Keeper.h"

Keeper::Keeper()
{
	arr = nullptr;
	size = 0;
	bool flag = true;
	int number;
	int n = 0;
	std::string name, time;
	while (flag) {
		
		std::cout << "\t\tMenu\t\t\n";
		std::cout << "1. Add trains\n";
		std::cout << "2. Delete trains\n";
		std::cout << "3. Change trains\n";
		std::cout << "4. Show all trains\n";
		std::cout << "5. Find trains\n";
		std::cout << "6. Exit\n";
		std::cout << "Enter number of command: ";
		cin >> n;


		switch (n)
		{
		case 1:
			
			std::cout << "\nEnter number: ";
			std::cin >> number;
			std::cout << "\nEnter name City: ";
			std::cin >> name;
			std::cout << "\nEnter time: ";
			std::cin >> time;
			push_back(TRAIN(number,name,time));
			sort(arr, size);
			break;
		case 2:
			pop_back();
			sort(arr, size);
			break;
		case 3:
			show();
			std::cout << "\nEnter index of train: ";
			std::cin >> n;
			std::cout << "\nEnter number: ";
			std::cin >> number;
			std::cout << "\nEnter name City: ";
			std::cin >> name;
			std::cout << "\nEnter time: ";
			std::cin >> time;
			arr[n].setLocate(name);
			arr[n].setNumber(number);
			arr[n].setTime(time);
			break;

		case 4:
			show();
			break;
		case 5:
			find();
			break;

		default:
			flag = false;
			break;
		}
	
	
	}

}

Keeper::~Keeper()
{
	try {
		if (size == 0)
			throw "Empty list";

		delete[] arr;
	}
	catch (const char* exception) {
		std::cout << exception;

	}
}

void Keeper::show()
{
	if (size == 0)
		throw "empty list";

	for (int i = 0; i < size; i++)
		cout << arr[i]<< endl;
}

int Keeper::getSize()
{
	return this->size;
}

void Keeper::sort(TRAIN* arr, int size)
{
	int i = 0, j = size - 1;
	TRAIN x = arr[size / 2];

	do {
		while (arr[i] < x) i++;
		while (arr[j] > x) j--;

		if (i <= j) {
			TRAIN tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;


		}
	} while (i <= j);

	if (j > 0)
		sort(arr,j+1);
	if (i < size)
		sort(&arr[i], size - i);
}

void Keeper::find()
{
	int number,cnt = 0;
	std::cout << "\nEnter number for find: ";
	std::cin >> number;

	for (int i = 0; i < size; i++) {
	
		if (number == arr[i].getNumber()) {
			cout << arr[i]<<"\n";
			cnt++;
		}
	}
	if (cnt == 0) 
		cout << "Not found train with number "<< number << "\n";
	
}

void Keeper::push_back(TRAIN obj)
{
	TRAIN* arrN = new TRAIN [size+1];
	
	if (size != 0) {
		for (int i = 0; i < size; i++) 
			arrN[i] = arr[i];	
		arrN[size] = obj;
	}
	else 
		arrN[size] = obj;
	
	size++;
	TRAIN* bufptr = arr;
	arr = arrN;
	delete[] bufptr;
	
}

TRAIN Keeper::pop_back()
{
	if (size == 0)
		throw "empty list";


	TRAIN* arrN = new TRAIN[size - 1];
	if (size == 1) {
		TRAIN trPop(arr[0]);
		delete[] arr;
		arr = nullptr;
		size--;
		return TRAIN(trPop);
	}
	for (int i = 0; i < size-1; i++) 
		arrN[i] = arr[i];
	
	TRAIN trPop(arr[size-1]),* bufptr = arr;
	arr = arrN;
	delete[] bufptr;
	size--;
	return TRAIN(trPop);
	// TODO: вставьте здесь оператор return
}

void Keeper::push_front(TRAIN obj)
{

	TRAIN* arrN = new TRAIN[size + 1];

	if (size != 0) {
		arrN[0] = obj;
		for (int i = 1; i < size+1; i++)
			arrN[i] = arr[i-1];
		
	}
	else
		arrN[size] = obj;

	size++;
	TRAIN* bufptr = arr;
	arr = arrN;
	delete[] bufptr;

}

TRAIN Keeper::pop_front()
{
	if (size == 0)
		throw "empty list";


	TRAIN trPop(arr[0]), * bufptr = arr;
	TRAIN* arrN = new TRAIN[size - 1];//выделили память под новый массив
	if (size == 1) {
		delete[] arr;
		arr = nullptr;
		size--;
		return TRAIN(trPop);
	}
	for (int i = 1; i < size; i++)//начиная со второго элемента заполняем новый массив
		arrN[i - 1] = arr[i];

	arr = arrN;
	delete[] bufptr;
	size--;
	return TRAIN(trPop);
}
