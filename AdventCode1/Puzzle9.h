#pragma once


#include <iostream>
#include <string>
#include <list>
#include <map>


using namespace std;

class Puzzle9 {


	//List of movements
	list<pair<string, int>> movements;

	//Position of the tail 
	map<string,size_t> tailPositions;
	


	struct Knot {
		int col = 0;
		int row = 0;

		bool operator==(const Knot& other) const
		{
			return this->col == other.col && this->row == other.row;
		}

		Knot& operator=(const Knot& other) 
		{
			this->col = other.col;
			this->row = other.row;
			return *this;
		}

	};

	//First Question = 2 |||||| Second question = 10
	const size_t NUMBERKNOT = 10;
	
	//The size depends on NUMBERKNOT
	Knot rope[10];


public :
	Puzzle9(string);
	~Puzzle9();

private:
	//Determine the next movement
	void Move();

	void MoveLeft(int);
	void MoveRight(int);
	void MoveUp(int);
	void MoveDown(int);

	//Adds the position of the tail to the list
	void CheckPosition();

	//Move or not each knot of the rope by checking if the previus one is far enough
	void MoveKnot();
};