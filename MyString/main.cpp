//uriel serna haro
//CST-210 mwf 1230
//January 18, 2020
//MyString

#include"MyString.h"

using namespace std;

int main() {

	
	MyString A;//null constructor
	cout << "                  creating null MyString A....." << endl;
	cout << "size of MyString A: " << A.capacity << endl;//test capacity
	cout << "\n\n";
	cout << "                  creating MyString X with 'uriel'...." << endl;
	cout << "                  creating MyStrinf Y with 'serna'....." << endl;
	MyString X("uriel");//create two MyStrings from strings
	MyString Y("serna");
	cout << "mystring x = "<< X << endl;
	cout <<"mystring y = "<< Y << endl;
	cout << "\n\n";
	cout << "                  copying MyString X as B..." << endl;
	MyString B = X; //calling copy constructor on X to make B
	cout << "MyString B contains: " << B << endl;// show it worked
	cout<<"size of B is "<< B.capacity << endl;
	Y.length();
	cout << "\n\n";
	cout << "                    concating X and Y...." << endl;

	MyString D = X + Y;//concatting two strings to make Mystring D
	cout <<"result = "<< D << endl;
	cout << "\n\n";
	cout <<"                    testing if B and X are the same" << endl;
	B == (X);//testing to see if they are similar
	X < (Y);
	cout << "\n\n";
	cout << "                    testing substring on D from position 7" << endl;
	cout << D.substring(7) << endl;//gives substring from position 7 on
	cout << "\n\n";
	
	cout << "                    getting char in D[9]......" << endl;
	cout <<"D[9] is: "<< D.get(9) << endl;//return the char at position 9(n)
	D < Y;
	Y > D;//could not get compare function to work
	cout << "\n\n";
	cout << "                         testing case change" << endl;
	X.toUpper(); //change all entries to uppercase
	cout << X <<endl;
	X.toLower(); //change back to lowercase
	cout << "\n\n";
	cout << "                         now back to lowercase" << endl;
	cout << X << endl;
	cout << "                      X index of Y" << endl;
	cout << X.indexOf(Y) << endl; // test first and last of index
	cout << "                      X last index of Y" << endl;
	cout << X.lastIndexOf(Y) << endl;
	





}