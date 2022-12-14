#include "Puzzle10.h"



#include <istream>
#include <fstream>
#include <string>







Puzzle10::Puzzle10(string _file)
{

	ifstream file(_file.c_str());

	string linea;


	while (getline(file, linea))
	{
		program.push_back(linea);
	}

	ExecuteProgram();

	cout << "Total: " << signalStrength << endl;

	PrintCRT();

	

}

Puzzle10::~Puzzle10()
{
}

void Puzzle10::ExecuteProgram()
{

	int currentcycle = 0;
	int lastcycle=0;

	int X = 1;

	string command;
	
	pair<bool, size_t> isCycle;

	//Read each command of the program
	for (size_t i = 0; i < program.size(); i++)
	{
		
		command = program[i].substr(0, 4);
		lastcycle = currentcycle;

		if (command == "noop")
		{			
			currentcycle++;

			isCycle = IsAStrengthCycle(lastcycle, currentcycle);

			//If the cycle is one of the designate cycles calculate the signal strength
			if (isCycle.first == true)
			{
				signalStrength += isCycle.second * X;
			}
		}
		else
		{
			currentcycle += 2;

			isCycle = IsAStrengthCycle(lastcycle, currentcycle);

			//If the cycle is one of the designate cycles calculate the signal strength
			if (isCycle.first == true)
			{
				signalStrength += isCycle.second * X;
			}

			X += stoi(program[i].substr(4));			
		}
	}
}

pair<bool, size_t> Puzzle10::IsAStrengthCycle(int lastcycle,int currentcycle )
{
	/*  Posible situations that can trigger this function
	
		L ======> Last cycle before execute the current command
		C ======> Current cycle after execute the current command
	
			         15 16 17 18 19 [20] 21 22 23 24 
							  L------>C
								 L--->C
								 L------>C
	
	
	*/



	pair<bool, size_t> aux = { false,0 };

	for (size_t i = 0; i < strenghtCycles.size(); i++)
	{
		if (lastcycle == (strenghtCycles[i] - 1))
		{
			aux.first = true;
			aux.second = strenghtCycles[i];
			return aux;
		}
		else if ((currentcycle == strenghtCycles[i] ) &&
			(lastcycle == (strenghtCycles[i] - 2)))
		{
			aux.first = true;
			aux.second = strenghtCycles[i];
			return aux;
		}
	}

	return aux;
}

void Puzzle10::PrintCRT()
{

	int currentcycle = 0;
	string command;
	int X = 0;
	int cicleadded = 0;
	//First position of the sprite
	int sprite = 1;

	//Actual row
	size_t row = 1;
	
	size_t mod = row - 1;

	string _row = "";

	for (size_t i = 0; i < program.size(); i++)
	{
		command = program[i].substr(0, 4);

		if (command == "noop")
		{
			cicleadded = 1;
			X = 0;
		}
		else
		{
			cicleadded = 2;
			X = stoi(program[i].substr(4));
		}

		//Iterate the cicles reviewed
		for (size_t i = 0; i < cicleadded; i++)
		{
			currentcycle++;

			//If the cycle reach the final character of the row starts the next
			if (currentcycle > (40 * row))
			{
				cout << _row << endl;
				_row = "";
				row++;
				mod = 40 *( row - 1);
			}


			if (OverlapSprite((currentcycle - mod), sprite) == true)
				_row+= '#';
			else
				_row += '.';

		}

		sprite += X;


	}
	cout << _row << endl;
}

bool Puzzle10::OverlapSprite(int currentcycle, int sprite)
{

	for (size_t i = 0; i < SPRITE_SIZE; i++)
	{
		if (currentcycle == (sprite + i))
			return true;
	}



	return false;
}
