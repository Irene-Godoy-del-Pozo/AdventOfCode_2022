#pragma once

//https://adventofcode.com/2022/day/1


#include <iostream>
#include<list>

using namespace std;

class Puzzle1 {

private:

	// List of the calories that each elf carries
	list<list<int>> caloriesList;

	// Name of the file with the input
	string fileName;

	// Elf/s that carries more calories
	string elfNum;

	//Num of calories carried for the elf
	string caloriesNum;

public:

	Puzzle1(string);
	~Puzzle1();

private:

	void PrintList();

	//Puzzle 1.1 How many total Calories is that Elf carrying?
	void Calories();

	//Puzzle 1.2 How many Calories are the top 3 Elves carrying in total?
	void Top(int);
};