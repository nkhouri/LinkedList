#pragma once
class ItemList
{
private:
	struct ListNode{
		int value;
		ListNode * next;
	};

	ListNode * head;
public:
	ItemList();
	// Post: List is the empty list.

	bool IsThere(int item) const;
	// Post: If item is in the list IsThere is
	// True; False, otherwise.

	void Insert(int item);
	// Pre: item is not already in the list.
	// Post: item is in the list.

	void Delete(int item);
	// Pre: item is in the list.
	// Post: item is no longer in the list.

	void Print() const;
	// Post: Items on the list are printed on the screen.

	int GetLength() const;
	// Post: Length is equal to the number of items in the
	// list.

	~ItemList();
	// Post: List has been destroyed.
};