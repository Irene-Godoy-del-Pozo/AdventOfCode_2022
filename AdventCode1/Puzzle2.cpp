#include "Puzzle2.h"


#include <istream>
#include <fstream>
#include <string>




Puzzle2::Puzzle2(string _file)
{
	totalScore = 0;

	ifstream file(_file.c_str());

	string linea;

	
	int first = 0;
	int second = 0;


	while (getline(file, linea))
	{
		// Translate the shape for its value
		switch (*linea.begin())
		{
			case 'A':
				first = 1;
				break;
			case 'B':
				first = 2;
				break;
			case 'C':
				first = 3;
				break;
		} 

		switch (*(linea.end()-1))
		{
		case 'X':
			second = 1;
			break;
		case 'Y':
			second = 2;
			break;
		case 'Z':
			second = 3;
			break;
		}

		listGiven.push_back(pair<int, int>(first, second));

	}
	
	//PrintList();
	//CalculateScore();
	CalculateRealScore();
}

Puzzle2::~Puzzle2()
{
}

void Puzzle2::PrintList()
{
	
	list<pair<int, int>>::iterator it = listGiven.begin();

	for (it; it != listGiven.end(); it++)
	{
		cout << it->first << it->second << endl;
	}

}

void Puzzle2::CalculateScore()
{

	totalScore = 0;
	list<pair<int, int>>::iterator it = listGiven.begin();

	for (it; it != listGiven.end(); it++)
	{
		if (it->first == it->second) //draw
			totalScore += it->second + 3; 
		
		else
		{
			switch (it->second)
			{
			case 1:
				if (it->first == 3) // win
					totalScore += it->second + 6;
				else //lose
					totalScore += it->second;

				break;
			case 2:
				if (it->first == 1) // win
					totalScore += it->second + 6;
				else //lose
					totalScore += it->second;

				break;
			case 3:
				if (it->first == 2) // win
					totalScore += it->second + 6;
				else //lose
					totalScore += it->second;

				break;
			}
		}
	}

	cout << "Your total score is : "<< totalScore << endl;
}

void Puzzle2::CalculateRealScore()
{
	totalScore = 0;

	list<pair<int, int>>::iterator it = listGiven.begin();

	for (it; it != listGiven.end(); it++)
	{
		if (it->second == 1) //Lose
		{
			switch (it->first)
			{
			case 1: 
				totalScore += 3;
				break;
			case 2:
				totalScore += 1;
				break;
			case 3:
				totalScore += 2;
				break;
			}
		}
		else if (it->second == 3) //Win
		{
			
			switch (it->first)
			{
			case 1:
				totalScore += 2 + 6;
				break;
			case 2:
				totalScore += 3 + 6;
				break;
			case 3:
				totalScore += 1 + 6;
				break;
			}
		}
		else // Draw
			totalScore += it->first + 3;

		
	}

	cout << "Your REAL total score is : " << totalScore << endl;
}
