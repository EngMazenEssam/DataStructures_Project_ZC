#ifndef _LINKEDLIST
#define _LINKEDLIST

#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
class LinkedList
{
private:
	Node<T> *Head;	//Pointer to the head of the list
	//You can add tail pointer too (depending on your problem)
	int count;	//Number of nodes in the list
public:


	LinkedList()
	{
		count = 0;
		Head = nullptr;
	}

	//List is being desturcted ==> delete all items in the list
	~LinkedList()
	{
		DeleteAll();
	}
	
	/*
	* Function: PrintList.
	* prints the values of all nodes in a linked list.
	*/
	void PrintList()	const
	{
		cout<<"\nList has "<<count<<" nodes";
		cout<<"\nprinting list contents:\n\n";
		Node<T> *p = Head;

		while(p)
		{
			cout << "[ " << p->getItem() << " ]";
			cout << "--->";
			p = p->getNext();
		}
		cout << "*\n";
	}
	
	/*
	* Function: InsertBeg.
	* Creates a new node and adds it to the beginning of a linked list.
	* 
	* Parameters:
	*	- data : The value to be stored in the new node.
	*/
	void InsertBeg(const T &data)
	{
		Node<T> *R = new Node<T>(data);
		R->setNext(Head);
		Head = R;
		count++;

	}
	
	/*
	* Function: DeleteAll.
	* Deletes all nodes of the list.
	*/
	void DeleteAll()
	{
		Node<T> *P = Head;
		while (Head)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
		count = 0;
	}

	////////////////     Requirements   ///////////////////
	////////// Implement the funtions found in your exercise day sheet //////////
	


bool find(T key){
	Node<T> *now = Head;
	while(now){
		if (now->getItem() == key) {
			return true;
		}

		now = now->getNext();
	}
	return false;
}

int CountOccurance(T value) {
	Node<T> *now = Head;
	int t = 0;
	while (now)
	{
		if (now->getItem() == value){
			t++;
		}
		now = now->getNext();
	}
	return t;
}

void DeleteNodes(T value){
	// LinkedList p = Head;
	Node<T> *now = Head;
	Node<T> *next = now->getNext();
	while (next)
	{
		if (next->getItem() == value){
			now->setNext(next->getNext());
			delete next;
			count--;
		}
		now = now->getNext();
		next = now->getNext()->getNext();
	}
}


void Reverse(){
	Node<T> *prev = nullptr;
	Node<T> *current = Head;
	Node<T> *next = nullptr;

	while (current) {
		next = current->getNext();
		current->setNext(prev);
		prev = current;
		current = next;
	}
	Head = prev;
}

};

#endif	
