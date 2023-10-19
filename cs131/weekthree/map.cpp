#include <iostream>
using namespace std;

struct Point {
	int x;
	int y;
};

enum Direction {
	NORTH,
	EAST,
	SOUTH,
	WEST
};

void move(Point& position, Direction direction)
{
	switch(direction) {
		case NORTH:
			position.y++;
			break;
		case EAST:
			position.x++;
			break;
		case SOUTH:
			position.y--;
			break;
		case WEST:
			position.x--;
			break;
		default:
			cout << "Invalid entry " << endl;
			break;
	}
}

int main()
{
	Point currentposition = {0,0};
	int choice;

	do {
		cout << "Choices, 1.North 2.East 3.South 4.West " << endl;
		cin >> choice;
		if(choice >= 1 && choice <= 4) {
			move(currentposition, static_cast<Direction>(choice - 1)); //casts choice -1 to direction
			cout << "(" << currentposition.x << " ,  " << currentposition.y << ")" << endl;
		}
		else if(choice == 5)
			cout << "Quitting " << endl;
		else
			cout << "Invalid input " << endl;
	
	} while(choice != 5);
	
	return 0;
}
