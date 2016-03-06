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
	void inputInfo();


	//Encryption
//	void createKeyword(string key);






};
#endif