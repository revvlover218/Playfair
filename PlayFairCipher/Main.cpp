#include <iostream>
#include <string>
#include "Playfair.h"

using namespace std;

int main()
{
	string key;

	string alpha = "abcdefghijklmnopqrstuvwxyz";

	cout << "Enter a keyword:" << endl;
	cin >> key;

	key.append(alpha);

	cout << "\n\n" << key << endl;



	system("pause");
	return 0;
}