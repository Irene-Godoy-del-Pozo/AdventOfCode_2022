#include "Puzzle9.h"



#include <istream>
#include <fstream>
#include <string>





Puzzle9::Puzzle9(string _file)
{

	ifstream file(_file.c_str());

	string linea;

	string direction;
	int quantity;

	while (getline(file, linea))
	{
		direction = linea.substr(0, linea.find(' '));
		quantity = stoi(linea.substr(linea.find(' ') + 1, linea.back()));
		
		movements.push_back(pair<string, int>(direction,quantity));
	}


	Move();
	
	cout << "Total diferents tail positions: "  <<tailPositions.size() << endl;
}

Puzzle9::~Puzzle9()
{
}

void Puzzle9::Move()
{

	list<pair<string, int>>::iterator it = movements.begin();

	for (it; it != movements.end(); it++)
	{
		if (it->first == "L")
			MoveLeft(it->second);

		else if (it->first == "R")
			MoveRight(it->second);

		else if (it->first == "U")
			MoveUp(it->second);

		else if (it->first == "D")
			MoveDown(it->second);

	}

}


void Puzzle9::MoveLeft(int quantity)
{	

	for (size_t i = 0; i < quantity; i++)
	{
		
		rope[0].col--;
		MoveKnot();
		
	}

}

void Puzzle9::MoveRight(int quantity)
{
	
	for (size_t i = 0; i < quantity; i++)
	{
		
		rope[0].col++;
		MoveKnot();

	}
}

void Puzzle9::MoveUp(int quantity)
{
	
	for (size_t i = 0; i < quantity; i++)
	{		

		rope[0].row++;
		MoveKnot();
		
	}
}

void Puzzle9::MoveDown(int quantity)
{	

	for (size_t i = 0; i < quantity; i++)
	{		

		rope[0].row--;
		MoveKnot();
			
	}
	
}



void Puzzle9::CheckPosition()
{	
	
	string aux = to_string(rope[NUMBERKNOT-1].row) + "," + to_string(rope[NUMBERKNOT-1].col);

	//If the list does not contains that position it inserts it
	if (tailPositions.count(aux) == 0)
		tailPositions.insert(pair<string, size_t>(aux, 1));
	else 
		tailPositions[aux] ++;

}

void Puzzle9::MoveKnot()
{
	/*
	
		o => cells where previus knot could be to allow movement to knot actual (T)
		x => cells where T could go
		T => Knot that is being examinated. (in the loop is determinated by i)


			o  o  o  o  o

			o  x  x  x  o

			o  x  T  x  o

			o  x  x  x  o

			o  o  o  o  o


	* */

	for (size_t i = 1; i < NUMBERKNOT; i++)
	{
		//Same column
		if (rope[i - 1].col == rope[i].col)
		{
			if ((rope[i - 1].row - rope[i].row) == 2)
				rope[i].row++; 

			else if ((rope[i - 1].row - rope[i].row) == -2)
				rope[i].row--;
		}
		//Same Row
		else if (rope[i - 1].row == rope[i].row)
		{
			if ((rope[i - 1].col - rope[i].col) == 2)
				rope[i].col++;

			else if ((rope[i - 1].col - rope[i].col) == -2)
				rope[i].col--;
		}
		else 
		{

			if ((rope[i - 1].col - rope[i].col) == 2)
			{
				rope[i].col++;

				if ((rope[i - 1].row - rope[i].row) < 0)
					rope[i].row--;

				else 
					rope[i].row++;

			}

			else  if ((rope[i - 1].col - rope[i].col) == -2)
			{
				rope[i].col--;

				if ((rope[i - 1].row - rope[i].row) < 0)
					rope[i].row--;

				else
					rope[i].row++;

			}
			else if ((rope[i - 1].row - rope[i].row) == 2)
			{
				rope[i].row++;

				if ((rope[i - 1].col - rope[i].col) < 0)
					rope[i].col--;

				else
					rope[i].col++;

			}
			else if ((rope[i - 1].row - rope[i].row) == -2)
			{
				rope[i].row--;

				if ((rope[i - 1].col - rope[i].col) < 0)
					rope[i].col--;

				else
					rope[i].col++;

			}

		}		

	}
	CheckPosition();

}
