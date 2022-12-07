#pragma once

// https://adventofcode.com/2022/day/2 

#include <iostream>
#include<list>

using namespace std;


class Puzzle2 {

private:

	//List of rounds
	list<pair<int, int>>  listGiven;
	
	int totalScore;


public:
	Puzzle2(string);
	~Puzzle2();

private:

	void PrintList();
	void CalculateScore(); //first question
	void CalculateRealScore();//second question


};