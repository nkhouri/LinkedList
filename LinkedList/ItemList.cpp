#include "ItemList.h"
#include <iostream>

using namespace std;

ItemList::ItemList()
{
	head = NULL;
}

bool ItemList::IsThere(int item) const
{
	ListNode *n;
	n = head;

	while (n != NULL) {
		if (n->value == item)
			return true;
		n = n->next;
	}
	return false;
}

void ItemList::Insert(int item)
{
	ListNode *n;		//used to copy the head node
	ListNode *t;		//used to make the new node
	n = head;

	if (head == NULL) {		//checks to see if the linked list is empty
		t = new ListNode;	//creates a temp node to store the new value
		t->value = item;	//adds the data to the node
		t->next = NULL;		//sets the next value to point to null because its at the end
		head = t;
	}
	else {
		while (n != NULL) {
			if (n->next == NULL)
				break;
			n = n->next;
		}
		t = new ListNode;	//creates a temp node to store the new value
		t->value = item;	//adds the data to the node
		t->next = NULL;		//sets the next value to point to null because its at the end
		n->next = t;		//set the n node to point to the new t node
	}
}


void ItemList::Delete(int item)
{
	ListNode *n;
	ListNode *t;
	n = head;

	while (n != NULL){
		if (n->value == item) {
			t = n->next;	//deletes the link between the desired node
			free(n);		//deallocates the node from memory
			break;			//leaves the loop
		}
		t = n;				//sets the t pointer to n
		n = n->next;		//shifts the n to the next node in the line so t is always 1 behind
	}
}

void ItemList::Print() const
{
	ListNode *n;
	n = head;
	
	while (n != NULL) {
		cout << n->value << endl;
		n = n->next;
	}
}

int ItemList::GetLength() const
{
	int c = 0;
	ListNode *n;
	n = head;

	while (n != NULL) {
		c++;
		n = n->next;
	}
	return c;
}

ItemList::~ItemList()
{
	delete head;
}
