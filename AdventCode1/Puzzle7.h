#pragma once

//https://adventofcode.com/2022/day/7



#include <iostream>
#include <string>
#include <list>
#include <map>

using namespace std;

class Puzzle7 {

	//Each element of the list (either directory or file)
	struct Elements {

		//Size of the element
		int size = 0;

		//Elements that THIS element contains. If its size is 0 means that THIS element is a file.
		map<string, Elements> elements;


	}_main;

	//Contains each line of the input file
	list<string> input;

	//Iterator of the list input
	list<string>::iterator it_input;

	//Sum of sizes of directories which size is less than 100 000. First question answer
	int totalsize = 0;


	//Min space that it necesary to free
	int min_space= 0;

	//Size of the directory that has to be deleted. Second question answer
	int erase_dir = 0;

	const int TOTAL_DISK_SPACE = 70000000;
	const int MIN_UNUSED_SPACE = 30000000;

public:
	Puzzle7(string);
	~Puzzle7();

private:

	
	map<string, Elements> FillList(list<string>);

	//Create hierarchy of elements from the input given
	void CreateList(Elements&);
	void Print(Elements elm,string);

	//Assign each directory with its total size
	int AssignSizes(Elements& elm);

	//Gets the directory that needs to be erase
	int GetErasedDirectory(Elements);
};