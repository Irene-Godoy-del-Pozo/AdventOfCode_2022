#pragma once

//https://adventofcode.com/2022/day/8



#include <iostream>
#include <string>
#include <list>


using namespace std;

class Puzzle8 {



	list<string> rowTrees;

	int visibleTrees = 0;


public:
	Puzzle8(string);
	~Puzzle8();

private:

	void GetVisibleTrees();

	void PrintTrees();

	bool CheckRowTrees(int, int, int, list<string>::iterator);

	bool CheckColumnTrees(bool, int, list<string>::iterator, list<string>::iterator);
	



};