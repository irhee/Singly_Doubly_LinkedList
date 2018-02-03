/******************************************************************************
Data structures and algorithms-in-c++ 
Page 125-128
*******************************************************************************/
#include <iostream>
#include <string>

using namespace std;

typedef string Elem; // list element type  

class DNode
{ // doubly linked list node  

private:
	Elem elem; // node element value  
	DNode* prev; // previous node in list  
	DNode* next; // next node in list  
	friend class DLinkedList; // allow DLinkedList access  

};

class DLinkedList

{ // doubly linked list 

public: DLinkedList(); // constructor  

		~DLinkedList(); // destructor  

		bool empty() const; // is list empty?  

		Elem front() const; // get front element  

		Elem back() const; // get back element  

		void addFront(const Elem e); // add to front of list  

		void addBack(const Elem e); // add to back of list  

		void removeFront(); // remove from front  

		void removeBack(); // remove from back  

		void findMiddlePoint();

		void print();

private: // local type de?nitions  

	DNode* header; // list sentinels  

	DNode* trailer;

protected: // local utilities  

	void add(DNode* v, const Elem e); // insert new node before v  

	void remove(DNode* v); // remove node v  

};

DLinkedList::DLinkedList()
{ // constructor  

	header = new DNode; // create sentinels  

	trailer = new DNode;

	header->next = trailer; // have them point to each other  

	trailer->prev = header;
}

DLinkedList::~DLinkedList() { // destructor  

	while (!empty()) removeFront(); // remove all but sentinels  

	delete header; // remove the sentinels  

	delete trailer;

}

bool DLinkedList::empty() const // is list empty?  
{
	return (header->next == trailer);
}

Elem DLinkedList::front() const // get front element  
{
	return header->next->elem;
}

Elem DLinkedList::back() const // get back element  
{
	return trailer->prev->elem;
}

void DLinkedList::add(DNode* v, const Elem e)
{
	DNode* u = new DNode; u->elem = e; // create a new node for e  

	u->next = v; // link u in between v  

	u->prev = v->prev; // ...and v->prev  

	v->prev->next = v->prev = u;
}

void DLinkedList::addFront(const Elem e) // add to front of list  
{
	add(header->next, e);
}

void DLinkedList::addBack(const Elem e) // add to back of list  
{
	add(trailer, e);
}

void DLinkedList::remove(DNode* v)
{ // remove node v  

	DNode* u = v->prev; // predecessor  

	DNode* w = v->next; // successor  

	u->next = w; // unlink v from list  

	w->prev = u; delete v;
}

void DLinkedList::removeFront() // remove from font  
{
	remove(header->next);
}

void DLinkedList::removeBack() // remove from back  
{
	remove(trailer->prev);
}

void DLinkedList::findMiddlePoint()
{

}

void DLinkedList::print()
{
	DNode* traverse = header->next;
	int count = 0;
	while (traverse != NULL)
	{
		cout << count++ << ". " << traverse->elem << endl;
		traverse = traverse->next;
	}
}

int main()

{
	DLinkedList* newList = new DLinkedList;

	newList->addFront("Hello World");
	newList->addFront("777");
	newList->addFront("Hi");
	newList->print();

	delete newList;
	return 0;

}
#include <iostream>
#include <string>

using namespace std;

typedef string Elem; // list element type  

class DNode
{ // doubly linked list node  

private:
	Elem elem; // node element value  
	DNode* prev; // previous node in list  
	DNode* next; // next node in list  
	friend class DLinkedList; // allow DLinkedList access  

};

class DLinkedList

{ // doubly linked list 

public: DLinkedList(); // constructor  

		~DLinkedList(); // destructor  

		bool empty() const; // is list empty?  

		Elem front() const; // get front element  

		Elem back() const; // get back element  

		void addFront(const Elem e); // add to front of list  

		void addBack(const Elem e); // add to back of list  

		void removeFront(); // remove from front  

		void removeBack(); // remove from back  

		void findMiddlePoint();

		void print();

private: // local type de?nitions  

	DNode* header; // list sentinels  

	DNode* trailer;

protected: // local utilities  

	void add(DNode* v, const Elem e); // insert new node before v  

	void remove(DNode* v); // remove node v  

};

DLinkedList::DLinkedList()
{ // constructor  

	header = new DNode; // create sentinels  

	trailer = new DNode;

	header->next = trailer; // have them point to each other  

	trailer->prev = header;
}

DLinkedList::~DLinkedList() { // destructor  

	while (!empty()) removeFront(); // remove all but sentinels  

	delete header; // remove the sentinels  

	delete trailer;

}

bool DLinkedList::empty() const // is list empty?  
{
	return (header->next == trailer);
}

Elem DLinkedList::front() const // get front element  
{
	return header->next->elem;
}

Elem DLinkedList::back() const // get back element  
{
	return trailer->prev->elem;
}

void DLinkedList::add(DNode* v, const Elem e)
{
	DNode* u = new DNode; u->elem = e; // create a new node for e  

	u->next = v; // link u in between v  

	u->prev = v->prev; // ...and v->prev  

	v->prev->next = u;
	v->prev = u;

}

void DLinkedList::addFront(const Elem e) // add to front of list  
{
	add(header->next, e);
}

void DLinkedList::addBack(const Elem e) // add to back of list  
{
	add(trailer, e);
}

void DLinkedList::remove(DNode* v)
{ // remove node v  

	DNode* u = v->prev; // predecessor  

	DNode* w = v->next; // successor  

	u->next = w; // unlink v from list  

	w->prev = u; delete v;
}

void DLinkedList::removeFront() // remove from font  
{
	remove(header->next);
}

void DLinkedList::removeBack() // remove from back  
{
	remove(trailer->prev);
}

void DLinkedList::findMiddlePoint()
{
    DNode* frontHopper = header->next;
    DNode* rearHopper = trailer->prev;
    DNode* trace = header;
    int count = 0;

    while(trace != rearHopper) 
    { 
        frontHopper = frontHopper->next;
        rearHopper = rearHopper->prev;
        trace = trace->next;
        cout << count++ << endl;
        if(frontHopper->next != rearHopper)
        {
            break;
        }
    } 
        
    if(frontHopper == rearHopper)
    { 
        cout << frontHopper->elem<<" is the middle element. \n";
    }
        
    if(trace == rearHopper) 
    { 
        cout << rearHopper->elem << " and " << frontHopper->elem << " are the middle elements. \n";
    } 
}

void DLinkedList::print()
{
	DNode* traverse = header->next;
	int count = 0;
	while (traverse != NULL)
	{
		cout << count++ << ". " << traverse->elem << endl;
		traverse = traverse->next;
	}
}

int main()

{
	DLinkedList* newList = new DLinkedList;

	newList->addFront("Hello World");
	newList->addFront("777");
	newList->addFront("Hi");
	//newList->addFront("Gg");
	newList->print();
	newList->findMiddlePoint();

	delete newList;
	
	return 0;

}