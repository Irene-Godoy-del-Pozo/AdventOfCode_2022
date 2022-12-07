#pragma once

//https://adventofcode.com/2022/day/3

#include <iostream>
#include <string>
#include <list>
using namespace std;

class Puzzle3 {

	
	//List of each rucksack. Each string is a compartment
	list<pair<string, string>> rucksacks;

	//List of groups of elfs.
	list<list<string>> elfsGoups;

	//List of each char with its value
	list<pair<char, size_t>> priorities;
	int totalPriorities;


public:
	Puzzle3(string); //Constructor for the first question
	Puzzle3(string,size_t); // Constructor for the second question
	~Puzzle3();

private:

	void PrintRucksucks();
	void CalculateRucksacks();

	void PrintGroups();
	void CalculateGroups();


	void PrintPriorities();
	void GeneratePriorities();
	size_t CalculatePriority(char);
};