#include <iostream>
#include <string>
#include "Playfair.h"

using namespace std;

int main()
{
	PlayfairCipher PFC;
	
	string mes;
	
	PFC.inputInfo();
//	PFC.output();	
//	PFC.SortKeyword();
	PFC.prepMessage();
	
	

	system("pause");
	return 0;
}