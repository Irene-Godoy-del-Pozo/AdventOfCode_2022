#pragma once

//https://adventofcode.com/2022/day/4


#include <iostream>
#include <string>
#include <list>
using namespace std;

class Puzzle4 {

	//Each pair contaisn 2 arrays that contains de range of sections assigns to each elf
	struct Pairs
	{
		int p1[2];
		int p2[2];
	};
private:

	list<Pairs> listPairs;

	int totalPairs;

public:

	Puzzle4(string);
	~Puzzle4();

	void PrintPairs();
	void CalculateTotalPairs(); // question 1
	void CalculateTotalPairsFullOverlaped(); // question 2


};