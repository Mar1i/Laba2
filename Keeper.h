#pragma once
#include"TRAIN.h"
class Keeper
{

	TRAIN* arr;
	int size;


	
public:
	Keeper();
	~Keeper();
	void show();
	int getSize();
	void sort(TRAIN* arr, int size);
	void find();
	void push_back(TRAIN obj);
	TRAIN pop_back();
	void push_front(TRAIN obj);
	TRAIN pop_front();

	

};

