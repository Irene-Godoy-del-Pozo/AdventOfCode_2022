#include "Puzzle1.h"


#include <istream>
#include <fstream>
#include <string>
#include <algorithm>


Puzzle1::Puzzle1(string _file) 
{
	fileName = _file;
	
	ifstream file(_file.c_str());

	string linea;
	
	//List of calories of 1 elf
	list<int> aux;
	
	
	while (getline(file, linea)) 
	{
		//Fill the list with all the calories of the elf
		if (linea != "")
		{
			aux.push_back(stoi( linea ));
			
		}
		//Add the elf to the list
		else
		{
			caloriesList.push_back(aux);

			aux.clear();
		}
		
	}
	caloriesList.push_back(aux);

	//PrintList();
	
	//Calories();

	Top(3);
}

Puzzle1::~Puzzle1()
{
}


void Puzzle1::PrintList()
{
	list<list<int>>::iterator i = caloriesList.begin();

	for (i ; i != caloriesList.end(); i++)
	{
		list<int>aux = *i;
		list<int>::iterator j;
		for (j = aux.begin(); j != aux.end(); j++)
		{
			cout << *j << endl;
		}
		cout << " " << endl;
	}

}

void Puzzle1::Calories()
{

	list<list<int>>::iterator i = caloriesList.begin();

	int max = 0;
	int counter = 0;

	for (i; i != caloriesList.end(); i++)
	{
		list<int>aux = *i;
		list<int>::iterator j;

		int caloriescount = 0;

		//Sum all calories of one elf
		for (j = aux.begin(); j != aux.end(); j++)
		{
			caloriescount += *j;
		}
		
		//Compare that elf with the one with more calories
		if (caloriescount > max)
		{
			max = caloriescount;
			elfNum = to_string( counter);
		}
		else if (caloriescount == max) 
			elfNum += " and " + to_string(counter);

		counter++;
	}

	caloriesNum = to_string(max);


	cout << "The elf (or elfs ) carrying the most Calories is " + elfNum + " with a total of " + caloriesNum + " calories."  << endl;

	
}

void Puzzle1::Top(int maxtop)
{
	list<list<int>>::iterator i = caloriesList.begin();



	list<int> caloriesPerElf;

	for (i; i != caloriesList.end(); i++)
	{
		list<int>aux = *i;
		list<int>::iterator j;

		int caloriescount = 0;

		for (j = aux.begin(); j != aux.end(); j++)
		{
			caloriescount += *j;
		}

		caloriesPerElf.push_back(caloriescount);

	}

	int counter = 0;

	cout << " The Top " << maxtop << " of elfs is: " << endl;

	for (int top = 0; top < maxtop; top++)
	{
		//GEt the elf with more calories on the list
		list<int>::iterator _max = std::max_element(caloriesPerElf.begin(), caloriesPerElf.end());
		
		// Get the position on the list
		list<int>::difference_type q = distance(caloriesPerElf.begin(), _max);

		counter += *_max;

		//Print th score
		cout << (top+1)<< "- Elf Number " << q << " with a total of " << *_max << " calories." << endl;

		//Remove from the list to be able to find the others top 3
		caloriesPerElf.remove(*_max);
	}
	


	cout << "The total of calories between the "<<maxtop<<" is: "<< counter << endl;

}
