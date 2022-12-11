#include "Puzzle8.h"




#include <istream>
#include <fstream>
#include <string>




Puzzle8::Puzzle8(string _file)
{
	ifstream file(_file.c_str());

	string linea;

	while (getline(file, linea))
	{

		rowTrees.push_back(linea);
	}
	GetVisibleTrees();
	cout << "Number of visible trees : " << visibleTrees << endl;
	//PrintTrees();
}

Puzzle8::~Puzzle8()
{
}

void Puzzle8::GetVisibleTrees()
{
	//Pointer that will examine each row
	list<string>::iterator it = rowTrees.begin();
	//Pointer to the last row
	list<string>::iterator end_it = rowTrees.end();
	end_it--;

	//Pointer to the previus row
	list<string>::iterator prev_it = rowTrees.begin();
	//Pointer to the next row
	list<string>::iterator next_it = end_it;


	for (it; it != rowTrees.end(); it++)
	{
		//Top and bottom rows are always visible
		if (it == rowTrees.begin() || it == end_it)
			visibleTrees += it->length();

		else
		{
			//Iterate the trees in the row
			for (size_t i = 0; i < it->length(); i++)
			{
				
				//First and last trees of the row are always visible
				if (i == 0 || i == (it->length() - 1))
					visibleTrees++;

				else
				{
			
					prev_it = rowTrees.begin();
					next_it = end_it;

					if ((CheckRowTrees		( 1, 0, i, it) == true) ||					//left
						(CheckRowTrees		(-1, it->length() - 1, i, it) == true) ||	//right
						(CheckColumnTrees	(true , i, it, prev_it) == true) ||			//top
						(CheckColumnTrees	(false, i, it, next_it) == true))			//bot
						visibleTrees++;											

				}
			}
		}
	}
}

bool Puzzle8::CheckRowTrees(int increment, int initial, int i, list<string>::iterator row )
{
	bool visible = true;
	
	for (size_t side = initial; side != i; side += increment)
	{
		if (row->at(i) <= row->at(side))
		{
			visible = false;
			break;
		}
	}

	return visible;
}

bool Puzzle8::CheckColumnTrees(bool up , int i, list<string>::iterator row, list<string>::iterator other_rows)
{
	bool visible = true;

	while(other_rows != row)
	{
		if (row->at(i) <= other_rows->at(i))
		{
			visible = false;
			break;
		}
		if (up == true) other_rows++;
		else other_rows--;
	}

	return visible;
}


void Puzzle8::PrintTrees()
{
	list<string>::iterator it = rowTrees.begin();

	for (it; it != rowTrees.end(); it++)
	{
		cout << *it << endl;
	}

}
