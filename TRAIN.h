#pragma once
#include <string>
#include<iostream>
using namespace std;
class TRAIN
{
	//VARIANT 9
	int number;
	string locate;
	string time;

public:

	TRAIN();
	TRAIN(const TRAIN& obj);
	TRAIN(int _number,string _locate, string _time);
	
	int getNumber();
	string getLoacate();
	string getTime();

	void setNumber(int _number);
	void setLocate(string _locate);
	void setTime(string _time);
	TRAIN& operator=(const TRAIN& obj);
	friend std::ostream& operator<<(std::ostream& out, const TRAIN& other);
	friend bool operator<(const TRAIN& ob1, const TRAIN& ob2);
	friend bool operator>(const TRAIN& ob1, const TRAIN& ob2);
	friend bool operator==(const TRAIN& ob1, const TRAIN& ob2);
	friend bool operator!=(const TRAIN& ob1, const TRAIN& ob2);
	

};

