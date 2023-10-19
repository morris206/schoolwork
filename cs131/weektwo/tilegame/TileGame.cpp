#include <sstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include "TileGame.h"
using namespace std;

TileGame::TileGame()
{
    //Assign each item in the array to the value of the index
	for(int i = 0; i < 10; i++)
		tiles[i] = i;

//	srand(time(0));
	
    //TODO: Mix the positions up
    for(int i = 0; i < 10; i++){
		int random_index = rand() % 10;
		int temp = tiles[i];
		tiles[i] = tiles[random_index];
		tiles[random_index] = temp; 
	}	
}


int TileGame::findZero()
{
    //TODO Return the position of the Zero
	for(int i = 0; i < 10; i++){
		if(tiles[i] == 0)
			return i;				
	}
    return -1;
}

void TileGame:: moveRight()
{    
	int zero = findZero();
    if(zero == -1 || zero == 9)
     return;
  //TODO:  Swap the value to the left of the zero with the zero
		int temp = tiles[zero];
		tiles[zero] = tiles[zero + 1];
		tiles[zero + 1] = temp; 
}

void TileGame::moveLeft()
{
    int zero = findZero();
    if(zero == -1 || zero == 0)
      return;
    //TODO:  Swap the value to the right of the zero with the zero
    //Use the variable zero as the index of the zero
	int temp = tiles[zero];
	tiles[zero] = tiles[zero - 1];
	tiles[zero - 1] = temp; 
		
}

void TileGame::swap()
{
    int zero = findZero();  
    if(zero == -1 || zero == 0 || zero == 9)
      return;
    //TODO:  Swap the values on Eithor Side of the 0
    //Use the variable zero as the index of the zero

	int temp = tiles[zero - 1];
	tiles[zero - 1] = tiles[zero + 1];
	tiles[zero + 1] = temp;
}

bool TileGame::inOrder()
{
    //TODO: Check to see if the game is in order.  
    for(int i = 0; i < 10; i++){
		if(tiles[i] != i)
    		return false;
	}
	return true;
}


//Returns the game as a string for display 
string TileGame::getDisplay()
{
  stringstream output;
  for(int i = 0; i < 10; i++)
  {
    if(tiles[i]>0)
      output << "[" << tiles[i] << "]" << " ";
    else
      output << "[ ]" << " ";
  }
  return output.str();
}
