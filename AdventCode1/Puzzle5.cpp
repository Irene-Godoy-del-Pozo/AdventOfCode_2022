#include "Puzzle5.h"


#include <istream>
#include <fstream>
#include <string>






Puzzle5::Puzzle5(string _file)
{
	ifstream file(_file.c_str());

	//------CRANES-----------------
	string linea = "     ";
	list<string> auxlist;
	string aux;
	getline(file, linea);
	
	//when it get to 1 it would mean that there is no more cranes
	while (linea[1] != '1')
	{
		//Get a list of the cranes per lines 
		aux = "";
		for (size_t i = 1; i <= linea.length(); i+=4)
		{
			
			if (linea[i] == ' ') aux += '-';
				
			else	aux += linea[i];
		}

		auxlist.push_back(aux);
		getline(file, linea);
	}

	//Get the cranes per column
	geteCranes(auxlist);

	PrintCranes();

	//------MOVEMENTS-----------------
	getline(file, linea,'m');
	
	while (getline(file, linea,' '))
	{
		Movements move;

		for (size_t i = 0; i < 3; i++)
		{
			
			switch (i)
			{
			case 0:	getline(file, linea, ' ');  move.quantity = stoi(linea); getline(file, linea, ' ');
				break;
			case 1:	getline(file, linea, ' ');  move.from = stoi(linea); getline(file, linea, ' ');
				break;
			case 2:	getline(file, linea, '\n');  move.to = stoi(linea);
				break;
			}
			
		}

		linea;

		movementsList.push_back(move);
	}

	//MoveCranes();
	MoveCranesTogether();
}

Puzzle5::~Puzzle5()
{
}

void Puzzle5::geteCranes(list<string> aux)
{
	list<string>::iterator it = aux.begin();
	string placeholder ;
	
	for (size_t i = 0; i < it->length(); i++)
	{
		placeholder = "";
		for (it; it != aux.end(); it++)
		{
			if(it->at(i)!='-')
				placeholder += it->at(i);
		}

		it = aux.begin();
		cranesList.push_back(placeholder);

	}


	


}


void Puzzle5::PrintCranes()
{
	list<string>::iterator it = cranesList.begin();

	for (it; it != cranesList.end();it++)
	{
		cout << *it << endl;
	}

}

void Puzzle5::GetTopCranes()
{
	list<string>::iterator it = cranesList.begin();

	for (it; it != cranesList.end(); it++)
	{
		topCranes += it->at(0);
	}

	cout << "Top crates: " + topCranes << endl;
}

void Puzzle5::MoveCranes()
{
	list<Movements>::iterator _it = movementsList.begin();

	// iterator to column from the cranes move are
	list<string>::iterator itfrom = cranesList.begin();

	//iterator to the column where the cranes ar going to be
	list<string>::iterator itto = cranesList.begin();


	for (_it; _it != movementsList.end(); _it++)
	{
		//Advance each iterator to the column given for the movements list
		advance(itto, (_it->to - 1));
		advance(itfrom, (_it->from - 1));

		//move {quantity} cranes 
		for (size_t i = 0; i < _it->quantity; i++)
		{
			
			//Copy to the column TO 
			itto->insert(0,1, itfrom->at(0));

			//Remove from the column FROM

			itfrom->erase(0, 1);
		}

		//Reset iterators
		itfrom = cranesList.begin();
		itto = cranesList.begin();
	}

	GetTopCranes();

	

}

void Puzzle5::MoveCranesTogether()
{
	list<Movements>::iterator _it = movementsList.begin();

	// iterator to column from the cranes move are
	list<string>::iterator itfrom = cranesList.begin();

	//iterator to the column where the cranes ar going to be
	list<string>::iterator itto = cranesList.begin();


	for (_it; _it != movementsList.end(); _it++)
	{
		//Advance each iterator to the column given for the movements list
		advance(itto, (_it->to - 1));
		advance(itfrom, (_it->from - 1));

		//Copy to the column TO 
		//position to begin inserting, string to insert, position to begin to copy, quantity of char to copy
		itto->insert(0, *itfrom, 0, _it->quantity );

		//Remove
		itfrom->erase(0, _it->quantity);

		//Reset iterators
		itfrom = cranesList.begin();
		itto = cranesList.begin();
	}

	GetTopCranes();
}

