#include <iostream>
#include <string>
#include "Playfair.h"

using namespace std;

int main()
{
	string key;
	string keydup;
	int length;

	string alpha = "abcdefghijklmnopqrstuvwxyz";

	cout << "Enter a keyword:" << endl;
	cin >> key;

	key.append(alpha);
	length = key.length();

	cout << "\n\n" << key << endl;
	cout << "\n" << length << endl;

	for (int i = 0; i < key.length(); i++)
	{
		for (int j = 0; j < key.length(); j++)
		{
			if (key[i] == key[j])
			{
				if (j + 1 < 26)
				key[j] == key[j + 1];

			}

		}

	}

	cout << "\n\n" << "After removing duplicates:" << endl;
	cout << "\n\n" << keydup << endl;


	system("pause");
	return 0;
}