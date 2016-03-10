//Name: Reshal Luchman
//Student number: 213501051
//ENEL4SE - Security and Encryption
//Major practical 1

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

string PlayfairCipher::getCipher()
{
	return cipher;
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

void PlayfairCipher::setCipher(string c)
{
	cipher = c;
}

void PlayfairCipher::inputInfo()		//Method which is used to input the keyword, text message and a boolean variable for
{										//encryption/ decryption

	string keyford_e;
	string messageford_e;
	bool dec_enc;
	///PlayfairCipher PFC;

	cout << "Enter keyword to be used:" << endl;
	getline(cin, keyford_e);
	
	cout << "\nEnter message to be encrypted/ decrypted:" << endl;
	getline(cin, messageford_e);
	
	cout << "\nEnter '0' for encryption or '1' for decryption:" << endl;
	cin >> dec_enc;

	setKey(keyford_e);
	setMessage(messageford_e);
	setMethod(dec_enc);
}

void PlayfairCipher::SortKeyword()
{
	
	string alpha = "abcdefghijklmnopqrstuvwxyz";
	int i = 0;

	for (int i = 0; i < key.length(); i++)
	{
		if (key[i] == ' ')
			key.erase(i, 1);
	}


	key.append(alpha);	//Appended alphabets to the keyword
	
	for (int i = 0; i < key.length(); i++)
	{

		for (int j = i + 1; j < key.length(); j++)
		{
	
			if (key[i] == key[j])
				key.erase(j, 1); //Remove duplicate characters. This function also ammends the length of the array when needed.
		}

	}

	for (int i = 0; i < key.length(); i++)
	{

		if (key[i] == 'j')		//Remove 'j' from keyword
			key.erase(i, 1);
	}

	for (int r = 0; r < 5; r++)
	{
	
		for (int c = 0; c < 5; c++)
		{

			keyword[r][c] = key[i];	//Stores each character of the key into the 2D array.
			i++;
		}
	}
}

void PlayfairCipher::prepMessage()
{

	string mes;
	char filler; //default filler character
	int testfillq = 0; //test if filler character exists in message, if it does (testfill = 1) use next character (Q, X, Z)
	int testfillx = 0;
	int testfillz = 0;

	for (int i = 0; i < message.length(); i++)
	{

		if (message[i] == ' ')		//Remove spaces from the Plain/ Cipher text.
			message.erase(i, 1);
	}

	//Find appropriate filler character
	for (int i = 0; i < message.length(); i++)
	{

		if (message[i] == 'q')
			testfillq = 1;
		if (message[i] == 'x')
			testfillx = 1;
        if (message[i] == 'z')
			testfillz = 1;
	}

	if (testfillx == 0)
		filler = 'x';
	else if (testfillz == 0)
		filler = 'z';
	else if (testfillq == 0)
		filler = 'q';

	for (int i = 0; i < message.length(); i+=2)
		{

			mes += message[i];		//append each character to the string: mes
		
			if (i + 1 < message.length()) //if the length of the message has not been reached
			{
				if (message[i] == message[i + 1])		//Check if the next character is the same as the current character 
				{										//if it is insert a filler character between them, since Playfair cipher 
					mes += filler;						//does not allow the character in each pair to be the same.
				}
				mes += message[i + 1];
			}
		}

		if (mes.length() % 2 == 1)		//Since encryption requires the characters of the message to be in pairs, it means that 
			mes += filler;			//the length of the string must be even. Therefore, if there is an odd number of 
										//characters in the string insert an 'X' to make the length of the string even.
		message = mes;
}

char PlayfairCipher::getChar(int row, int column)
{
	return keyword[(row + 5) % 5][(column + 5) % 5];
}

void PlayfairCipher::getCharPos(char ch, int &row, int &col)
{

	for (int i = 0; i < 5; i++)
	{

		for (int j = 0; j < 5; j++)
		{

			if (keyword[i][j] == ch)
			{

				row = i;
				col = j;
			}
		}
	}
}

void PlayfairCipher::encry_decry()
{
	int row1 = 0, col1 = 0, row2 = 0, col2 = 0;
	int h = 0;

	int direction; //variable to hold value for the direction of encryption i.e. encryption = 1 and decryption = -1

	if (!d_e)
		direction = 1;
	if (d_e)
		direction = -1;

	while (h < message.length())
	{

		getCharPos(message[h], row1, col1);
		h++;
		getCharPos(message[h], row2, col2);

		if (row1 == row2)
		{

			cipher += getChar(row1, col1 + direction);
			cipher += getChar(row2, col2 + direction);
		}

		if (col1 == col2)
		{

			cipher += getChar(row1 + direction, col1);
			cipher += getChar(row2 + direction, col1);
		}

		else
		{

			cipher += getChar(row1, col2);
			cipher += getChar(row2, col1);
		}

		h++;
	}
}


void PlayfairCipher::output()
{

	for (int i = 0; i < cipher.length(); i++)
		toupper(cipher[i]);		//Convert to upper case

	if (!d_e)
	{

		cout << "\nThe encrypted Ciphertext is" << endl;
		cout << cipher << endl;
	}

	if (d_e)
	{

		cout << "\nThe decrypted plaintext is" << endl;
		cout << cipher << endl;
	}
}