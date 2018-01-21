#include <iostream>
#include "ItemList.h"

using namespace std;
int main() {
	ItemList i;

	cout << "Adding the numbers 5, 10, and 15\n";
	i.Insert(5);
	i.Insert(10);
	i.Insert(15);

	cout << "Printing...\n";
	i.Print();

	cout << "Deleting 10...\n";
	i.Delete(10);

	cout << "Printing...\n";
	i.Print();

	system("pause");
	return 0;
}