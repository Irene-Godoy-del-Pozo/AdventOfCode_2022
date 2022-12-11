#include "Puzzle7.h"




#include <istream>
#include <fstream>
#include <string>





Puzzle7::Puzzle7(string _file)
{

	//Fill the list input with de data given

	ifstream file(_file.c_str());

	string linea;

	while (getline(file, linea))
	{
	
		input.push_back(linea);
	}

	it_input = input.begin();

	
	CreateList(_main);
	
	AssignSizes(_main);

	Print(_main, "");
	cout <<"First question: "<< totalsize << endl;

	int unused_space = TOTAL_DISK_SPACE - _main.elements["/"].size;
	min_space = MIN_UNUSED_SPACE - unused_space;
	erase_dir = TOTAL_DISK_SPACE;

	GetErasedDirectory(_main);

	cout << "Second question: " << erase_dir << endl;

}

Puzzle7::~Puzzle7()
{
}



map<string, Puzzle7::Elements> Puzzle7::FillList(list<string> _list)
{
	map<string, Elements> aux;

	list<string>::iterator it = _list.begin();

	for (it; it != _list.end(); it++)
	{
		Elements elm;
		string name;

		//its a file
		if (it->at(0) != 'd')
		{
			string a = it->substr(0, it->find(' '));
			elm.size = stoi(a);


		}
	
		
		name = it->substr(it->find(' ') + 1, it->back());
		aux.insert(pair<string, Elements>(name,elm));

	}




	return aux;
}








void Puzzle7::CreateList(Elements& elm)
{
	
	string child;
	list<string> elemntsdirectory;
	Elements* child_elemnts = &elm;

	for (it_input; it_input != input.end(); it_input++)
	{
		if (*it_input == "$ cd ..") //get back one level
			return;
		else if (it_input->compare(0, 4, "$ cd") == 0) //Get in one level in {child} directory
		{
			child = it_input->substr(5, it_input->back());

			it_input++;

			CreateList(elm.elements[child]);

		}
		else if (*it_input == "$ ls") //fill the directory's map 
		{
			it_input++;
			while ((it_input != input.end()) && (it_input->at(0) != '$') )
			{
				elemntsdirectory.push_back(*it_input);
				it_input++;
			} 
			
			child_elemnts->elements = FillList(elemntsdirectory);

			if (it_input != input.end()) it_input--; //get back to the previous input line to be able to read it
			

		}
		if (it_input == input.end()) return;
	}

}

void Puzzle7::Print(Elements elm,string espace)
{
	string aux;
	map<string, Elements>::iterator it = elm.elements.begin();

	for (it; it != elm.elements.end(); it++)
	{

		if (it->second.elements.size() != 0)
		{
			cout <<espace + it->first << endl;
			cout << espace+"tamaño dir: "<< it->second.size << endl;
			Print(it->second, espace + "  ");

			if(it->second.size <= 100000)
				totalsize += it->second.size;
		}
		else
		{
			cout << espace + it->first+" ----> " << it->second.size << endl;
		}
		
	}

	
}

int Puzzle7::AssignSizes(Elements& elm)
{
	string aux;
	map<string, Elements>::iterator it = elm.elements.begin();
	int _size = 0;

	for (it; it != elm.elements.end(); it++)
	{
		//If it's a directory 
		if (it->second.elements.size() != 0)
		{			
			it->second.size = AssignSizes(it->second);			
		}

		_size += it->second.size;
	}
	

	return _size;
}

int Puzzle7::GetErasedDirectory(Elements elm)
{
	string aux;
	map<string, Elements>::iterator it = elm.elements.begin();

	for (it; it != elm.elements.end(); it++)
	{

		if (it->second.elements.size() != 0)
		{
			
			GetErasedDirectory(it->second);


			if (it->second.size >= min_space && it->second.size <= erase_dir)
				erase_dir = it->second.size;
		}
		

	}
	return 0;
}
