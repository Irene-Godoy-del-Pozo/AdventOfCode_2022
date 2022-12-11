#include "Puzzle7.h"




#include <istream>
#include <fstream>
#include <string>





Puzzle7::Puzzle7(string _file)
{

	ifstream file(_file.c_str());

	string linea;

	/*firstDirectory.insert(pair<string,Elements>( "/", first));
	string name;*/
	while (getline(file, linea))
	{
	
		//if (linea.compare(0, 4, "$ cd") == 0)
		//	name = linea.substr(5, linea.back());
		//else if (linea == "$ ls")
		//{
		//	list < string >aux;
		//	getline(file, linea);
		//	while (linea[0] != '$')
		//	{
		//		aux.push_back(linea);
		//		getline(file, linea);
		//	}
		//	//firstDirectory["/"].elements = FillList(aux);
		//	if(name == "/")
		//		firstDirectory["/"].elements = FillList(aux);
		//	else
		//		FindDirectory(firstDirectory["/"].elements,"dir "+name).elements = FillList(aux);

		//	if (linea != "$ cd ..") 
		//		name = linea.substr(5, linea.back());
		//}

		input.push_back(linea);

	}

	it_input = input.begin();
	Elements first;
	_main.elements.insert(pair<string, Elements>("/", first));
	totalsize = 0;
	CreateList(_main);
	
	int aa = GetSizes(_main);
	totalsize = 0;
	Print(_main, "");
	cout <<"First question: "<< totalsize << endl;

	unused_space = 70000000 - _main.elements["/"].size;
	min_space = 30000000 - unused_space;
	erase_dir = 70000000;
	int directory = GetErasedDirectory(_main);

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
//			name = it->substr(it->find(' ') + 1, it->back());

		}
		else
		{
			elm.size = 0;
		}
		
		name = it->substr(it->find(' ') + 1, it->back());
		aux.insert(pair<string, Elements>(name,elm));

	}




	return aux;
}

Puzzle7::Elements & Puzzle7::FindDirectory(map<string, Elements>& elm, string name)
{
	//if (name == "/") return elm[name];

	Elements* aux = &_empty;

	if (elm.count(name) == 1) 
		return elm[name];

	else
	{
		map<string, Elements>::iterator it = elm.begin();

		for (it; it != elm.end(); it++)
		{
			if (it->second.elements.size() != 0)
			{
				aux = &FindDirectory(it->second.elements, name);
				if (aux->size != _empty.size) 
					return *aux;
			}
		}

		

	}



	map<string, Elements>& a = elm;//firstDirectory.find(name)->second;
	
	return *aux;
}








void Puzzle7::CreateList(Elements& elm)
{
	string aux = *it_input;
	string child;
	list<string> elemntsdirectory;
	Elements* child_elemnts = &elm;

	for (it_input; it_input != input.end(); it_input++)
	{
		if (*it_input == "$ cd ..")
			return;
		else if (it_input->compare(0, 4, "$ cd") == 0)
		{
			child = it_input->substr(5, it_input->back());
			it_input++;
			if (child == "jqlm")
			{
				it_input++;
				it_input--;
			}
			CreateList(elm.elements[child]);
			//child_elemnts = &elm.elements[child].elements;
		}
		else if (*it_input == "$ ls")
		{
			it_input++;
			while ((it_input != input.end()) && (it_input->at(0) != '$') )
			{
				elemntsdirectory.push_back(*it_input);
				it_input++;
			} 
			
			child_elemnts->elements = FillList(elemntsdirectory);
			if (it_input != input.end()) it_input--;
			

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

int Puzzle7::GetSizes(Elements& elm)
{
	string aux;
	map<string, Elements>::iterator it = elm.elements.begin();
	int _size = 0;

	for (it; it != elm.elements.end(); it++)
	{
		

		if (it->second.elements.size() != 0)
		{
			
			it->second.size = GetSizes(it->second);
			_size += it->second.size;
			
		}
		else
		{
			_size += it->second.size;
			//if (it->second.size <= 100000) totalsize += it->second.size;

		}

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
