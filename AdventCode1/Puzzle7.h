#pragma once

//https://adventofcode.com/2022/day/7



#include <iostream>
#include <string>
#include <list>
#include <map>

using namespace std;

class Puzzle7 {

	struct Elements {

		int size = -10;

		map<string, Elements> elements;

		bool operator == (const Elements& lhs) const
		{
			return this->size == lhs.size && this->elements == lhs.elements;
		}

		bool operator != (const Elements& lhs) const
		{
			return this->size != lhs.size && this->elements != lhs.elements;
		}

	}_main,_empty;

	map<string,Elements> firstDirectory;
	list<string> input;
	list<string>::iterator it_input;
	int totalsize;
	int unused_space = 0;
	int min_space= 0;
	int erase_dir = 0;

public:
	Puzzle7(string);
	~Puzzle7();

	

private:
	map<string, Elements> FillList(list<string>);

	Elements& FindDirectory(map<string, Elements>& , string);//string name);

	void CreateList(Elements&);
	void Print(Elements elm,string);
	int GetSizes(Elements& elm);
	int GetErasedDirectory(Elements);
};