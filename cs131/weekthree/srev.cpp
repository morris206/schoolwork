#include <iostream>
#include <cstring>
using namespace std;

/*
int numRevWVar(int num)
{


}
*/

char *charRev(char *string)
{
	int j = strlen(string);

	for(int i = 0; i < j / 2; i++) {
		string[i] ^= string[j - i - 1];
		string[j - i - 1] ^= string[i];
		string[i] ^= string[j - i - 1];
	}
	return string;
}

int main(int argc, char **argv)
{
	if (argc > 1) {
		char *string = charRev(argv[1]);
		printf("num: %s\n", string);
	}
	exit(0);
}
