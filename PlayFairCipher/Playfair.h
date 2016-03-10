//Name: Reshal Luchman
//Student number: 213501051
//ENEL4SE - Security and Encryption
//Major practical 1

#ifndef PLAYFAIR_H
#define PLAYFAIR_H
#include <string>

using namespace std;

class PlayfairCipher
{

private:
	string key;		//variable to hold the keyword as a straight string 
	string message;	//message to be encrypted/ decrypted
	bool d_e;		//a boolean parameter which indicates whether the passed message is plaintext or ciphertext i.e
					//whether the message is to be encrypted or decrypted, d_e is short for decryption and encryption
	char keyword[5][5] = {}; //2D array to store the key after it has been liberated of its duplicates and character 'j'.
	string cipher;		//variable to hold the final result

public:
	PlayfairCipher();	//Constructor
	~PlayfairCipher();	//Destructor

	//Accessor and Mutator functions
	//Accessor
	string getKeyWord();
	string getMessage();
	bool getMethod();

	string getCipher();

	//Mutator
	void setKey(string);
	void setMessage(string);
	void setMethod(bool);

	void setCipher(string);

	//Input
	void inputInfo();		//Method which is used to input the keyword, text message and a boolean variable for
							//encryption (0)/ decryption(1)

	//Process
	void SortKeyword(); //This is the keyword manipulation. The spaces from the keyword is removed and the rest of the  
						//letters of the alphabet are appended to the keyword.
						//Next, the duplicates are 'removed' using the .erase function. Thereafter, the character 'j' is removed
						//since position of 'i' = position of 'j'.
						//Lastly, the 2D array is populated with the key word.
	void prepMessage(); //Takes the message from input and removes all spaces. Then a search is done to find an appropriate filler
						//character. Repeating letters in a pair are separated using the filler character (Q, X, Z)
						//The same filler character is used if the pairs are incomplete.
	char getChar(int, int);	//Takes in two int parameters, i.e. the row and column and returns the corresponding character 
							//from the 2D array.
	void getCharPos(char, int &, int &); //Takes in a character from the message, returns using referencing, the row and column
										//values for that character.
	void encry_decry();

	//Output
	void output();
	void test();

};
#endif