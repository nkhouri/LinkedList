#include <iostream>
#include <fstream>
#include "ItemList.h"

using namespace std;
int main() {
	ItemList list;
	ifstream input;
	int numbers[20];		//hold the file so only need to open once

	input.open("int.dat");	//open the file being used for the numbers
	int numberRead;			//used to transfer the file int to the function insert
	//insert the numbers into the array
	int count = 0;
	while (!input.eof()) {
		input >> numberRead;
		numbers[count] = numberRead;
		count++;
	}
	input.close();

	//insert numbers into the list
	for (int i = 0; i < 20; i++) {
		list.Insert(numbers[i]);
	}

	//test to see if they are in the list
	cout << "-----------------------------------------\n";
	bool tester;
	for (int i = 0; i < 20; i++) {
		tester = list.IsThere(numbers[i]);
		if (tester == true)
			cout << numbers[i] << " is in the list!\n";
		else
			cout << numbers[i] << " is not in the list!\n";
	}
	//check how many items are in the list
	cout << "There are " << list.GetLength() << " numbers in the array\n";

	//print the array
	list.Print();
	cout << "-----------------------------------------\n\n";
	cout << "Deleting -47, 1926, and 2000 from the list...\n";

	//remove -47, 1926, and 2000
	list.Delete(-47);
	list.Delete(1926);
	list.Delete(2000);

	cout << "-----------------------------------------\n";
	//run tester to see if they were removed
	for (int i = 0; i < 20; i++) {
		tester = list.IsThere(numbers[i]);
		if (tester == true)
			cout << numbers[i] << " is in the list!\n";
		else
			cout << numbers[i] << " is not in the list!\n";
	}

	//check how many items are in the list
	cout << "There are " << list.GetLength() << " numbers in the array\n";

	//print list
	list.Print();
	cout << "-----------------------------------------\n\n";

	system("pause");
	return 0;
}