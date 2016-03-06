#include "Playfair.h"
#include <iostream>
#include <string>

using namespace std;

PlayfairCipher::PlayfairCipher()		//default constructor
{
}

PlayfairCipher::~PlayfairCipher()		//Destructor
{
}

//Accessor and Mutator functions

//Accessor functions
string PlayfairCipher::getKeyWord()
{
	return key;
}

string PlayfairCipher::getMessage()
{
	return message;
}

bool PlayfairCipher::getMethod()
{
	return d_e;
}

//Mutator functions
void PlayfairCipher::setKey(string k)
{
	key = k;
}

void PlayfairCipher::setMessage(string m)
{
	message = m;
}

void PlayfairCipher::setMethod(bool de)		//de is short for decryption and encryption
{
	d_e = de;
}





/*void PlayfairCipher::createKeyword(string key)
{
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
		for (int j = i + 1; j < key.length(); j++)
		{
			if (key[i] == key[j])
			{
				//if (j + 1 < 26)
				//key[i] == key[j + 1];
				//cout << "\n" << key[i] << endl;
				key[j] = ' ';

			}

		}

	}

	cout << "\n\n" << "After removing duplicates:" << endl;
	cout << "\n\n" << key << endl;

}*/

void PlayfairCipher::inputInfo()
{

}

