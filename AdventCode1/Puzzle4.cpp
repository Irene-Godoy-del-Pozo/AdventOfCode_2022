#include "Puzzle4.h"

#include <istream>
#include <fstream>
#include <string>

Puzzle4::Puzzle4(string _file)
{
	ifstream file(_file.c_str());

	string linea;


	while (getline(file, linea , '-'))
	{
		Pairs pair;

		// First elf
		pair.p1[0] = stoi(linea);

		getline(file, linea, ',');
		
		pair.p1[1] = stoi(linea);

		
		//Second Elf
		getline(file, linea, '-');

		pair.p2[0] = stoi(linea);

		getline(file, linea);

		pair.p2[1] = stoi(linea);

		listPairs.push_back(pair);

	}

	//PrintPairs();
	//CalculateTotalPairs();
	CalculateTotalPairsFullOverlaped();
}

Puzzle4::~Puzzle4()
{
}

void Puzzle4::PrintPairs()
{
	list<Pairs>::iterator it = listPairs.begin();

	for (it; it != listPairs.end(); it++)
	{
		cout << it->p1[0]<< " y " << it->p1[1] << "////" << it->p2[0] << " y " << it->p2[1] << endl;
	}

}

void Puzzle4::CalculateTotalPairs()
{
	list<Pairs>::iterator it = listPairs.begin();
	totalPairs = 0;

	for (it; it != listPairs.end(); it++)
	{

		/* Elf {x0,x1} and Elf {y0, y1}
			
			x0 >= y0  && x1 <= y1
					or
			y0 >= x0  && y1 <= x1
		*/
		if ((it->p1[0] >= it->p2[0] && it->p1[1] <= it->p2[1]) || 
			(it->p2[0] >= it->p1[0] && it->p2[1] <= it->p1[1])) 
			totalPairs++;
		
	}

	cout << " El total de parejas que overlapean completamente son: " << totalPairs << endl;
}

void Puzzle4::CalculateTotalPairsFullOverlaped()
{
	list<Pairs>::iterator it = listPairs.begin();
	totalPairs = 0;

	for (it; it != listPairs.end(); it++)
	{
		/* Elf {x0,x1} and Elf {y0, y1}

			x0 <= y1  && x1 <= y0
					
		*/
		if (it->p1[0] <= it->p2[1]  && it->p1[1] >= it->p2[0])
			totalPairs++;

	}

	cout << " El total de parejas que overlapean de algun modo son: " << totalPairs << endl;
}
