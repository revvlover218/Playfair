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

void PlayfairCipher::inputInfo()		//Method which is used to input the keyword, text message and a boolean variable for
{										//encryption/ decryption

	string keyword;
	string message;
	bool dec_enc;
	PlayfairCipher PFC;

	cout << "\nEnter keyword to be used:" << endl;
	cin >> keyword;
	PFC.setKey(keyword);

	cout << "\nEnter message to be encrypted/ decrypted:" << endl;
	cin >> message;
	PFC.setMessage(message);

	cout << "\nEnter '0' for encryption or '1' for decryption:" << endl;
	cin >> dec_enc;
	PFC.setMethod(dec_enc);
}

void PlayfairCipher::output()
{
	cout << "The encrypted message is:" << endl;
	cout << key << endl;
	cout << message << endl;
	cout << d_e << endl;
}
