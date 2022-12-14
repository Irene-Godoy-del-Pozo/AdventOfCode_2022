#pragma once




#include <iostream>
#include <string>
#include <list>
#include <vector>


using namespace std;

class Puzzle11 {


	class Monkey
	{
		

		//Divisible number to determine which monkey to throw the object to
		size_t divisible;

		string operationNum;
		char operation;
		//Possible monkeys to throw. [0] = true, [1] = false
		size_t monkey_to[2];

	public:

		int objectsInspected = 0;
		//Holding objects
		list<int> objects;

	public:
		Monkey(list<int>_objects, size_t _divisible, string _operationNum,char _operation , size_t firstMonkey, size_t secondMonkey) :
			objects(_objects), divisible(_divisible), operationNum(_operationNum), operation(_operation)
		{
			monkey_to[0] = firstMonkey;
			monkey_to[1] = secondMonkey;
		}
		~Monkey() {};

		size_t MonkeyToThrow(size_t worryLevel);
		
		void GetNewWorryLevel(int&, size_t);



	};


	vector<Monkey> monkeys;

	unsigned long monkeyLevel = 0;


public:
	Puzzle11(string);
	~Puzzle11() {};
	void Rounds(int, size_t);

	int GetMonkeyLevel();

	void Throw(size_t, int);
	void CreateMonkey(vector<string>);
};