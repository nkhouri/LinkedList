#include <iostream>
#include <fstream>
#include "ItemList.h"

using namespace std;
int main() {
	ItemList i;
	ifstream input;

	input.open("int.dat");	//open the file being used for the numbers
	int numberRead;			//used to transfer the file int to the function insert
	//insert the numbers into the list
	while (!input.eof()) {
		input >> numberRead;
		i.Insert(numberRead);
	}
	input.close();

	//test to see if they are in the list
	input.open("int.dat");
	bool tester;
	while (!input.eof()) {
		input >> numberRead;
		tester = i.IsThere(numberRead);
		if (tester == true)
			cout << numberRead << " is in the list!\n";
		else
			cout << numberRead << " is not in the list!\n";
	}
	input.close();
	//check how many items are in the list
	cout << "There are " << i.GetLength() << " numbers in the array\n";

	//print the array
	i.Print();

	//remove -47, 1926, and 2000
	i.Delete(-47);
	i.Delete(1926);
	i.Delete(2000);

	//run tester to see if they were removed
	input.open("int.dat");
	while (!input.eof()) {
		input >> numberRead;
		tester = i.IsThere(numberRead);
		if (tester == true)
			cout << numberRead << " is in the list!\n";
		else
			cout << numberRead << " is not in the list!\n";
	}
	input.close();

	//check how many items are in the list
	cout << "There are " << i.GetLength() << " numbers in the array\n";

	//print list
	i.Print();


	system("pause");
	return 0;
}