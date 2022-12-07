#include "Puzzle3.h"

#include <istream>
#include <fstream>
#include <string>



Puzzle3::Puzzle3(string _file)
{
	GeneratePriorities();
	totalPriorities = 0;

	ifstream file(_file.c_str());

	string linea;

	string aux[2];

	
	while (getline(file, linea))
	{
		//Divide the rucksack in compartments
		aux[0].assign(linea.begin(), linea.end() - (linea.size() / 2));

		aux[1].assign(linea.begin() + (linea.size() / 2), linea.end() );

		rucksacks.push_back(pair<string,string>(aux[0],aux[1]));
	}

	//PrintPriorities();
	//PrintRucksucks();
	CalculateRucksacks();
}

/// <summary>
/// Question 2 constructor
/// </summary>
/// <param name="_file"> name of the file</param>
/// <param name="maxElfs">num of elfs per group</param>
Puzzle3::Puzzle3(string _file, size_t maxElfs)
{
	GeneratePriorities();
	totalPriorities = 0;

	ifstream file(_file.c_str());

	string linea;

	list <string> aux;

	// Obtener línea de archivo, y almacenar contenido en "linea"
	while (getline(file, linea))
	{
		aux.push_back(linea);

		for (size_t i = 1; i < maxElfs; i++)
		{
			getline(file, linea);
			aux.push_back(linea);
		}

		elfsGoups.push_back(aux);

		aux.clear();
	}

	//PrintGroups();
	CalculateGroups();
}

Puzzle3::~Puzzle3()
{
}

void Puzzle3::PrintRucksucks()
{
	list<pair<string, string>>::iterator it = rucksacks.begin();

	for (it; it != rucksacks.end(); it++)
	{
		cout << it->first + " ------------- " + it->second << endl;
	}


	
}

void Puzzle3::CalculateRucksacks()
{

	list<pair<string, string>>::iterator it = rucksacks.begin();

	for (it; it != rucksacks.end(); it++)
	{
		for (size_t i = 0; i <= it->first.size(); i++)
		{
			//If the second compartment conteins the element it sum the priority and stop searching 
			if (it->second.find(it->first[i]) < it->second.size())
			{
				
				totalPriorities += CalculatePriority(it->first[i]);

				break;
			}
		}

	}

	cout << "Suma de prioridades total: " << totalPriorities << endl;


}

void Puzzle3::PrintGroups()
{
	list<list<string>>::iterator it = elfsGoups.begin();

	for (it; it != elfsGoups.end(); it++)
	{
		list<string>::iterator _it = it->begin();
		for (_it; _it != it->end(); _it++)
		{
			cout << *_it << endl;
			
		}

		cout << "    " << endl;
	}
}


void Puzzle3::CalculateGroups()
{
	list<list<string>>::iterator it = elfsGoups.begin();

	for (it; it != elfsGoups.end(); it++)
	{
		list<string>::iterator _it = it->begin();

		for (size_t i = 0; i < _it->size(); i++)
		{
			char aux = _it->at(i);

			//If the other 2 elfs conteins the element it sum the priority and stop searching 
			if ((++_it)->find(aux) != string::npos && (++_it)->find(aux) != string::npos)
			{

				totalPriorities += CalculatePriority(aux);

				break;
			}
			_it = it->begin();
		}



	
	

	}

	cout << "Suma de prioridades total: " << totalPriorities << endl;
}



void Puzzle3::PrintPriorities()
{
	list<pair<char, size_t>>::iterator it = priorities.begin();

	for (it; it != priorities.end(); it++)
	{
		cout << it->first + " ------------- " << it->second << endl;
	}
}

void Puzzle3::GeneratePriorities()
{
	priorities = list<pair<char, size_t>>{ 
		{'a',1},
		{'b',2},
		{'c',3},
		{'d',4},
		{'e',5},
		{'f',6},
		{'g',7},
		{'h',8},
		{'i',9},
		{'j',10},
		{'k',11},
		{'l',12},
		{'m',13},
		{'n',14},
		{'o',15},
		{'p',16},
		{'q',17},
		{'r',18},
		{'s',19},
		{'t',20},
		{'u',21},
		{'v',22},
		{'w',23},
		{'x',24},
		{'y',25},
		{'z',26},
		
		{'A',27},
		{'B',28},
		{'C',29},
		{'D',30},
		{'E',31},
		{'F',32},
		{'G',33},
		{'H',34},
		{'I',35},
		{'J',36},
		{'K',37},
		{'L',38},
		{'M',39},
		{'N',40},
		{'O',41},
		{'P',42},
		{'Q',43},
		{'R',44},
		{'S',45},
		{'T',46},
		{'U',47},
		{'V',48},
		{'W',49},
		{'X',50},
		{'Y',51},
		{'Z',52},

	};

}

size_t Puzzle3::CalculatePriority(char _element)
{
	size_t result = 0;

	list<pair<char, size_t>>::iterator it = priorities.begin();

	for (it; it != priorities.end(); it++)
	{
		if (it->first == _element)
			result = it->second;

	}



	return result;
}
