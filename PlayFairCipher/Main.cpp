#include <iostream>
#include <string>
#include "Playfair.h"

using namespace std;

int main()
{
	PlayfairCipher PFC;
	
	
	PFC.inputInfo();
//	PFC.output();	
	PFC.SortKeyword();
	
	system("pause");
	return 0;
}