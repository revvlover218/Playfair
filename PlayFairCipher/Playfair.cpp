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

void PlayfairCipher::prepMessage()
{
	string mes;

	if (d_e == 0) //Encryption
	{

		for (int i = 0; i < message.length(); i+=2)
		{

			mes += message[i];		//append each character to the string: mes
		
			if (i + 1 < message.length()) //if the length of the message has not been reached
			{
				if (message[i] == message[i + 1])		//Check if the next character is the same as the current character 
				{										//if it is insert an "X" between them, since Playfair cipher does not
					mes += "x";							//allow the character in each pair to be the same.
				}
				mes += message[i + 1];
			}
		}

		if (mes.length() % 2 == 1)		//Since encryption requires the characters of the message to be in pairs, it means that the length 
			mes.append("x");			//of the string must be even. Therefore, if there is an odd number of characters in the string
										//insert an 'X' to make the length of the string even.
		message = mes;

		cout << "\n\n" << message << endl;
	}
}