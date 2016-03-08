#ifndef PLAYFAIR_H
#define PLAYFAIR_H
#include <string>

using namespace std;

class PlayfairCipher
{

private:
	string key;		//variable to hold the keyword 
	string message;	//message to be encrypted/ decrypted
	bool d_e;		//a boolean parameter which indicates whether the passed message is plaintext or ciphertext i.e
					//whether the message is to be encrypted or decrypted, d_e is short for decryption and encryption

public:
	PlayfairCipher();	//Constructor
	~PlayfairCipher();	//Destructor

	//Accessor and Mutator functions
	//Accessor
	string getKeyWord();
	string getMessage();
	bool getMethod();

	//Mutator
	void setKey(string);
	void setMessage(string);
	void setMethod(bool);

	//Input
	void inputInfo();		//Method which is used to input the keyword, text message and a boolean variable for
							//encryption/ decryption

	//Process
	void SortKeyword(); //This is the keyword manipulation. The keyword is appended to the rest of the letters of the alphabet,
						//and the duplicates are 'removed' using the .erase function. Thereafter, the 'j' is removed.
						//Next a 2D array is created and is populated with the key word.
	void prepMessage(); //Takes the message from input and separates repeating letters using the filler character "X"
						//The same filler characgter is used if the pairs are incomplete.
	//Output
	void output();
	void testoutput();


	//Encryption
//	void createKeyword(string key);






};
#endif