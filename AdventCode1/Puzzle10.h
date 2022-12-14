#pragma once


#include <iostream>
#include <string>
#include <vector>
#include <array>


using namespace std;

class Puzzle10 {


	vector<string> program;

	array<size_t , 6> strenghtCycles = {20 , 60 , 100 , 140 , 180 , 220};

	int signalStrength = 0;

	const size_t SPRITE_SIZE = 3;

public:
	Puzzle10(string);
	~Puzzle10();

private:

	void ExecuteProgram();

	pair<bool,size_t> IsAStrengthCycle(int, int);

	void PrintCRT();
	bool OverlapSprite(int, int);
};