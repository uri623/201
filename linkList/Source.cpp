#include "dll.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
string cleanUp(string str2);
string cleanUp(string str);

int main() {

	DLinkedList<string> lst1;
	DLinkedList<string> lst2;
	DLinkedList<string> lst3;
	DLinkedList<string> lst4;

	

	ifstream fin("Text1.in");

	///////////This is for testing purposes only////////////////
	if (fin.is_open()){
		cout << "File is opened." << endl;
	}
	else {
		cout << "File not opened" << endl;
	}
	////////////////////////////////////////////////////////////

	string str;

	while (fin >> str) {
		str = cleanUp(str);
		lst1.insertOrderUnique(str);

	//	cout << str << endl;
	}
	
	fin.close();
	string str2;

	fin.open("Text2.in");
	while (fin >> str2) {
		str2 = cleanUp(str2);
		lst2.insertOrderUnique(str2);
	}
	fin.close();

	//lst3 = lst1.merge(lst2);
	//cout << "List 3: " << lst3 << endl;
	cout << "List 1: " << lst1 << endl;
	cout << "List 2: " << lst2 << endl;
	lst1.remove("baby");
	cout << "List 1: " << lst1 << endl;
	lst1.insertOrder("baby");
	lst1.insertOrder("tom");
	cout << "List 1: " << lst1 << endl;
	lst3 = lst1.merge(lst2);

	cout << "List 3: " << lst3 << endl;
	fin.open("Text3.in");
	while (fin >> str) {
		str = cleanUp(str);
		lst4.insertOrderUnique(str);
	}
	fin.close();
	cout << "testing cleanup.." << lst4 << endl;
	//cout << "List 1: " << lst1 << endl;


	//cout << "List 2: " << lst2 << endl;


	//DLinkedList<string> combined = lst1.merge(lst2);

	//cout << "\nAFTER MERGE" << endl;
	//cout << "List 1: " << lst1 << endl;
	//cout << "List 2: " << lst2 << endl;
	//cout << "\nCombined: " << combined << endl;


	//return 0;
	system("pause");
}

/**
* ASSIGNED
* @param str
* @return str in all lower case with LEADING and TRAILING non-alpha
* chars removed
*/
string cleanUp(string str) {
	
	int i = 0; //start counter
	string str1 = "";//create empty string
	

	for (int i = 0; i < str.size(); ++i) //loop over length of list
	{
		if (str[i] >= 65 && str[i] <= 90){//checks for upper case
			str[i] = str[i] + 32; //changes them to lower case
		}
		if (((str[i] >= 'a' && str[i] <= 'z' || str[i] == '\'')))//takes all letter characters
		{
			str1 = str1 + str[i]; //places cleaned up letters in str1
		}
		
	}
	
	return str1;
}