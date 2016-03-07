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





void PlayfairCipher::SortKeyword()
{
	
	string alpha = "abcdefghijklmnopqrstuvwxyz";
	char keyword[5][5];

	key.append(alpha);	//the alphabets are appended to the keyword
	
	for (int i = 0; i < key.length(); i++)
	{

		for (int j = i + 1; j < key.length(); j++)
		{
			if (key[i] == key[j])
				key.erase(j, 1); //Remove duplicate characters
		}

	}

	for (int i = 0; i < key.length(); i++)
	{
		if (key[i] == 'j')		//Remove 'j' from keyword
			key.erase(i, 1);
	}

	cout << "\n\n" << "After removing duplicates:" << endl;
	cout << "\n\n" << key << endl;
	
	int i = 0;

	for (int r = 0; r < 5; r++)
	{
	
		for (int c = 0; c < 5; c++)
		{

			keyword[r][c] = key[i];
			i++;
		}
	}

	for (int r = 0; r < 5; r++)
	{

		for (int c = 0; c < 5; c++)
		{

			cout << keyword[r][c] << "\t";
		}
		cout << endl;
	}


}

void PlayfairCipher::inputInfo()		//Method which is used to input the keyword, text message and a boolean variable for
{										//encryption/ decryption

	string keyword;
	string message;
	bool dec_enc;
	///PlayfairCipher PFC;

	cout << "Enter keyword to be used:" << endl;
	cin >> keyword;
	
	cout << "\nEnter message to be encrypted/ decrypted:" << endl;
	cin >> message;
	
	cout << "\nEnter '0' for encryption or '1' for decryption:" << endl;
	cin >> dec_enc;

	setKey(keyword);
	setMessage(message);
	setMethod(dec_enc);
}

void PlayfairCipher::output()
{

//	PlayfairCipher PFC;

	cout << "The encrypted message is:" << endl;
	cout << getKeyWord() << endl;
	cout << getMessage() << endl;
	cout << getMethod() << endl;
}

void PlayfairCipher::testoutput()
{



}