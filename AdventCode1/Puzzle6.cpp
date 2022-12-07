#include "Puzzle6.h"



#include <istream>
#include <fstream>
#include <string>





Puzzle6::Puzzle6(string _file)
{

	ifstream file(_file.c_str());

	string linea;

	getline(file, linea);

	dataStream = linea;

	
	//GetMarker(4);
	GetMarker(14);
}

Puzzle6::~Puzzle6()
{
}

void Puzzle6::GetMarker(size_t size)
{
	string marker;	
	char aux;

	//Number of elemnts in the marker
	int markerCount = 0;

	//Number of elemnts till the marker is complete
	int numTillFinsh = size;


	size_t i;
	for ( i = 0; i < dataStream.length() && markerCount < size; i++)
	{

		aux = dataStream.at(i);

		//If find another {aux} in the {numTillFinsh} follow positions is not part of the marker
		if (dataStream.find(aux, i + 1) < ( i + numTillFinsh) )
		{
			markerCount = 0;
			marker = "";
			numTillFinsh = size;

		}
		else
		{
			markerCount++;
			numTillFinsh--;
			marker += aux;
		}

	}

	numTillMarker = i;

	cout << "Marker: "+marker << endl;
	cout << numTillMarker << endl;
}
