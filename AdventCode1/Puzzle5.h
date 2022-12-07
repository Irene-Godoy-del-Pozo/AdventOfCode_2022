#pragma once

//https://adventofcode.com/2022/day/5

#include <iostream>
#include <string>
#include <list>
using namespace std;

class Puzzle5 {

private:

	struct Movements
	{
		size_t quantity;
		size_t from;
		size_t to;
	};

	//List of each column of cranes
	list<string> cranesList;

	list<Movements> movementsList;

	string topCranes;

public:

	Puzzle5(string);
	~Puzzle5();

private: 

	void PrintCranes();
	void GetTopCranes();
	void MoveCranes(); //question 1
	void MoveCranesTogether();//question 2

	void geteCranes(list<string>);

};