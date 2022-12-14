
#include "Puzzle11.h"


#include <istream>
#include <fstream>
#include <string>




Puzzle11::Puzzle11(string _file)
{
	ifstream file(_file.c_str());

	string linea;



	vector<string>monkeydata;

	while (getline(file, linea))
	{
		if (linea.substr(0, 6) != "Monkey")
		{
			monkeydata.push_back(linea);
		}
		else
		{
			if(monkeydata.size() > 1 )
			CreateMonkey(monkeydata);
			monkeydata.clear();
		}
	}
	//Last monkey
	CreateMonkey(monkeydata);

	
	//Rounds(20,3);
	Rounds(10000, 10000);

	monkeys;

	cout << monkeyLevel << endl;
}




void Puzzle11::Rounds(int numRounds, size_t manageable)
{
	list<int>::iterator it;

	

	for (int i = 0; i < numRounds; i++) // Round
	{
		for (size_t j = 0; j < monkeys.size(); j++) //Monkeys
		{
			it = monkeys[j].objects.begin();

			for ( ; it != monkeys[j].objects.end(); it++) //Objects
			{

				monkeys[j].GetNewWorryLevel(*it, manageable);

				monkeys[j].objectsInspected++;

				size_t to = monkeys[j].MonkeyToThrow(*it);

				Throw(to, *it);


			}			
			//Clear the list of objects thrown
			monkeys[j].objects.clear();
		}
		
		if (i == 19)
			int a = monkeys[0].objectsInspected;
		else if(i == 999)
			int b = monkeys[0].objectsInspected;

	}


	monkeyLevel = GetMonkeyLevel();

}

void Puzzle11::Throw(size_t to, int object)
{
	monkeys.at(to).objects.push_back(object);


}

void Puzzle11::CreateMonkey(vector<string> data)
{
	list<int>objects;

	char operation;
	string operationnum;

	int div;

	int truemonkey;
	int falseMonkey;

	string object = data[0].substr(18);
	string aux;

	for (size_t i = 0; i < object.size(); i+=4)
	{
		aux = object.substr(i, 2);
		objects.push_back(stoi(aux));
	}

	object = data[1].substr(23);
	operation = object[0];
	operationnum = object.substr(2);

	div = stoi(data[2].substr(21));
	

	truemonkey = stoi(data[3].substr(29));
	falseMonkey = stoi(data[4].substr(30));

	Monkey monkey = { objects,(size_t) div, operationnum, operation, (size_t)truemonkey, (size_t)falseMonkey };
	monkeys.push_back(monkey);

}

int Puzzle11::GetMonkeyLevel()
{
	int first = 0;
	int second = 0;

	for (size_t i = 0; i < monkeys.size(); i++)
	{
		if (monkeys[i].objectsInspected > first)
		{
			second = first;
			first = monkeys[i].objectsInspected;
		}
		else if(monkeys[i].objectsInspected > second)
			second = monkeys[i].objectsInspected;
	}

	return first * second;
}



//MONKEY


size_t Puzzle11::Monkey::MonkeyToThrow(size_t worryLevel)
{
	size_t monkey = 0;

	if ((worryLevel % divisible) == 0)
		monkey = monkey_to[0];
	else
		monkey = monkey_to[1];


	return monkey;
}


void Puzzle11::Monkey::GetNewWorryLevel(int& old, size_t manageable)
{
	size_t num;
	//Gets the operation number
	if (operationNum == "old")
		num = old;
	else
		num = stoi(operationNum);

	//if (old > 100000)
	//	old -= 100000 * divisible;

	if (operation == '+')
	{
		old = old + num;
	}
	else
	{
		old = old * num;
	}

	if (old > 1000000)
	old -= 1000000 * divisible;

	//old = old % 96577;

	old = old / manageable;

	
}
