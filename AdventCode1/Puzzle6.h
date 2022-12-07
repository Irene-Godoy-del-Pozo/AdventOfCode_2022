#pragma once

//https://adventofcode.com/2022/day/6

#include <iostream>
#include <string>
#include <list>
using namespace std;

class Puzzle6 {


	string dataStream;

	size_t numTillMarker;

public:
	Puzzle6(string);
	~Puzzle6();


	void GetMarker(size_t);

};