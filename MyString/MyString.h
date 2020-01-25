//uriel serna haro
//CST-210 mwf 1230
//January 18 2020
//MyString

# include <iostream>
# include <cstring>
#include <cctype>

using namespace std;

class MyString
{

public:
	char* nstring; //pointer
	MyString(void);//default sets string to NULL
	MyString(const char* input);//Takes in a string and creates an object
	MyString(const MyString & S);//Copy constructor
	~MyString(void);//Destructor deletes the nstring at the end

	int capacity;//size of array
	int length();//displays length of string excluding null
	char& get(int loc);// returns a chracter at specified loc-1
	
	//MyString& operator=(const MyString& rhs);
	//int get(const MyString& S, int index = 0);
	


	friend ostream& operator << (ostream & OS, const MyString &S);// out stream displays the string
	friend istream& operator >> (istream & IS, MyString &S);//instream takes in a string and creates and object
	MyString& operator = (const MyString& S);//compare two strings
	friend  bool operator ==(const MyString& S1, const MyString & S2);// overload == operator
	friend MyString operator + (const MyString& S1, const MyString & S2);//overload + operator




	int operator < (MyString &obj); //A<B, check if MyString A is alphabetically before MyString B
	int operator > (MyString &obj); //A>B, check if MyString A is alphabetically after MyString B
	void printString(char *temp); //It is for testing purposes only, it will print the string
	char* toUpper(); //It will convert myString to UpperCase
	char* toLower(); //It will convert myString to lowerCase
	char* substring(int); //It will take the index and return the string from that index
	int indexOf(MyString& obj); // It will find the first occurence of substring
	int lastIndexOf(MyString& obj); //It will find the last occurence of substring


private:
	//char* nstring; //pointer
	short curr_length; //# of characters in string
	void ensureCapacity();
};


MyString::MyString()     //initializing array to null
{
	capacity = 0;
	curr_length = 0;
	nstring = new char[curr_length];
	nstring[curr_length - 1] = '\0';
}

MyString::MyString(const char *input) //takes in string and creates array according to length of string
{
	capacity = strlen(input);
	curr_length = strlen(input) + 1;
	nstring = new char[curr_length];
	for (int i = 0; i < (curr_length - 1); i++)
	{
		nstring[i] = input[i];
	}
	nstring[(curr_length - 1)] = NULL;
}

MyString::MyString(const MyString & S) //copy constructor takes in MyString and creates copy
{
	capacity = S.curr_length;
	curr_length = S.curr_length;
	nstring = new char[curr_length];
	for (int i = 0; i < (curr_length-1); i++)
	{
		nstring[i] = S.nstring[i];
	}

	if (nstring[curr_length - 1] != '\0') { nstring[curr_length - 1] = '\0'; }
}

MyString::~MyString() //deletes string in array
{
	delete[] nstring;
}


int MyString::length() // returns number of characters in string
{
	int i = 0;
	while (nstring[i] != '\0')
	{
		i++;
	}
	return i;
	cout << "is" << i << "long" << endl;
}

char& MyString::get(int loc) //returns character from location of int loc entered
{
	
	return nstring[loc - 1];
	
	
}





bool operator == (const MyString & S1, const MyString & S2)// takes two strings and compares to see if equal
{
	if (S1.curr_length == S2.curr_length)
	{
		short counter1 = S1.curr_length;
		int counter2 = 0;
		int i = 0;
		while (i != counter1)
		{
			if (S1.nstring[i] != S2.nstring[i]) { counter2++; }
			i++;
		}
		
			cout <<"0 = same string, 1=different. Your result: " << counter2 << endl; // returns zero if same
		if (counter2 != 0) { return false; }
		else { return true; }
	}
	else { return false; }

}

ostream& operator <<(ostream & OS, const MyString& S)//overloads outstream to print nstring
{
	OS << S.nstring;
	return OS;
}

istream& operator >>(istream & IS, MyString& S) // overloads instream to create string
{
	char* input = new char[100];
	IS.getline(input, 100);

	int i = 0;
	while (input[i] != '\0')
	{
		i++;
	}
	S.curr_length = i + 1;
	delete[]S.nstring;
	S.nstring = new char[(i + 1)];
	for (int j = 0; j < (i); j++)
	{
		S.nstring[j] = input[j];
	}
	S.nstring[i] = '\0';
	delete[]input;
	return IS;
}

MyString& MyString::operator =(const MyString &S)
{
	curr_length = S.curr_length;
	delete[] nstring;
	nstring = new char[curr_length];
	for (int i = 0; i < (curr_length - 1); i++)
	{
		nstring[i] = S.nstring[i];
	}
	nstring[(curr_length - 1)] = '\0';
	return *this;
}

MyString operator + (const MyString& S1, const MyString & S2)
{
	
	int size = (S1.curr_length-1) + (S2.curr_length - 1) + 1;
	char * temp = new char[size];
	for (int i = 0; i < (S1.curr_length - 1); i++)
	{
		temp[i] = S1.nstring[i];
	}

	int j = 0;
	for (short k = S1.curr_length - 1, j = 0; k < (size - 1); k++, j++)
	{
		temp[k] = S2.nstring[j];
	}

	if (temp[size - 1] != '\0') { temp[size - 1] = '\0'; }

	MyString S3(temp);
	delete temp;
	return S3;
}


void MyString::ensureCapacity() {     //function called when no room to insert new char

	nstring = new char[capacity + 1];

}

int MyString::operator < (MyString &obj) //checks if string is alphabetically before other
{
	char a, b;
	for (int i = 0; i <= length() - 1 && i <= obj.length() - 1; i++) {
		a = nstring[i];
		b = obj.nstring[i];

		if (a >= 65 && a <= 90) {
			a += 32;
		}

		if (b >= 65 && b <= 90) {
			b += 32;
		}

		if (a < b) {
			return -1;
		}
		else if (a > b) {
			return 1;
		}

		i++;


	}

	if (length() < obj.length()) {
		return -1;
	}
	else if (length() > obj.length()) {
		return 1;
	}
	else if (length() == obj.length()) {
		return 0;
	}
}





int MyString::operator > (MyString &obj) //compares string to see if it is alphabetically after
{
	char a, b;
	for (int i = 0; i <= length() - 1 && i <= obj.length() - 1; i++) {
		a = nstring[i];
		b = obj.nstring[i];

		if (a >= 65 && a <= 90) {
			a += 32;
		}

		if (b >= 65 && b <= 90) {
			b += 32;
		}

		if (a > b) {
			return -1;
		}
		else if (a < b) {
			return 1;
		}

		i++;


	}

	if (length() > obj.length()) {
		return -1;
	}
	else if (length() < obj.length()) {
		return 1;
	}
	else if (length() == obj.length()) {
		return 0;
	}
}

void MyString::printString(char* tempString) // prints string to see
{ 


	int i = 0;
	while (tempString[i] != '\0')
	{
		cout << tempString[i];
		i++;

	}

	cout << endl;
}

char* MyString::toUpper() //reads characters and changes to uppercase if lowercase
{
	int i = 0;
	while (nstring[i] != '\0')
	{
		if (nstring[i] >= 97 && nstring[i] <= 122) {
			nstring[i] = nstring[i] - 32;
		}
		i++;
	}
	return nstring;
	cout << nstring <<endl;
}

char* MyString::toLower()//reads characters and changes to lowercase if uppercase
{
	int i = 0;
	while (nstring[i] != '\0')
	{
		if (nstring[i] >= 65 && nstring[i] <= 90) {
			nstring[i] = nstring[i] + 32;
		}
		i++;
	}
	return nstring;
}

char* MyString::substring(int a) //returns string starting at input location
{
	if (a > (strlen(nstring) - 1)) {
		cout << "Your entered index is incorrect" <<endl;//checks bounds
	}
	char *subString = new char[length()];

	int i = a, j = 0;
	while (nstring[i] != '\0')
	{
		subString[j] = nstring[i];
		i++;
		j++;
	}
	subString[length() - a] = NULL;
	return subString;
}

int MyString::indexOf(MyString& obj) //returns starting index of occurence
{
	int i, j, temp;
	for (i = 0; nstring[i] != '\0'; i++)
	{
		j = 0;
		if (nstring[i] == obj.nstring[j])
		{
			temp = i + 1;
			while (nstring[i] == obj.nstring[j] && i < strlen(nstring))
			{
				i++;
				j++;
			}

			if (obj.nstring[j] == '\0')
			{
				return temp - 1;
			}
			else
			{
				i = temp;
				temp = 0;
			}
			if (temp == 0) { //returns -1 if not found
				return -1;
			}
		}
	}
}

int MyString::lastIndexOf(MyString& obj) { //returns last occurence of string

	int i, j, temp;
	int index = -1;
	for (i = 0; nstring[i] != '\0'; i++)
	{
		j = 0;
		if (nstring[i] == obj.nstring[j])
		{
			temp = i + 1;
			while (nstring[i] == obj.nstring[j] && i < strlen(nstring))
			{
				i++;
				j++;
			}

			if (obj.nstring[j] == '\0')
			{
				index = temp - 1;

				//temp = index;
				//i = temp;
				//temp = 0;
			}

			{
				i = temp;
				temp = 0;
			}
		}
	}

	if (index == -1) //returns -1 if not found
		return -1;
	return index;
}