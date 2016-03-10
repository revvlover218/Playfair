//Name: Reshal Luchman
//Student number: 213501051
//ENEL4SE - Security and Encryption
//Major practical 1

#include <iostream>
#include <string>
#include "Playfair.h"

using namespace std;

int main()
{
	PlayfairCipher PFC;
	
	PFC.inputInfo();
	PFC.SortKeyword();
	PFC.prepMessage();
	PFC.encry_decry();
	
	//PFC.test();
//	PFC.output();	
	system("pause");
	return 0;
}