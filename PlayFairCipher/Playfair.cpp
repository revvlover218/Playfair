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
	int length;
	string alpha = "abcdefghijklmnopqrstuvwxyz";

	key.append(alpha);
	length = key.length();

	cout << "\n\n" << key << endl;
	cout << "\n" << length << endl;

	for (int i = 0; i < key.length(); i++)
	{
		if (key[i] == 'j')
			key[i] = ' ';
		for (int j = i + 1; j < key.length(); j++)
		{
			if (key[i] == key[j])
				key[j] = ' ';
		}

	}

	cout << "\n\n" << "After removing duplicates:" << endl;
	cout << "\n\n" << key << endl;

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