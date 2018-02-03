/******************************************************************************

*******************************************************************************/
#include <iostream>
#include <string>

using namespace std;

typedef string Elem;
class Snode{
private:
    Elem elem;
    Snode* next;
    friend class LinkedList;
};
class LinkedList{
public:
    LinkedList();
    LinkedList(Elem newElem);
    ~LinkedList();
    bool isEmpty() const;
    Elem& frontNode() const;
    void removeFront();
    void addFront(Elem newElem);
    void print();
private:
    Snode* head;
};
LinkedList::LinkedList()
{
    head = NULL;
}
LinkedList::LinkedList(Elem newElem)
{
    addFront(newElem);
}
LinkedList::~LinkedList()
{
    while(!isEmpty()) removeFront();
}
bool LinkedList::isEmpty() const
{
    return head == NULL;
}
Elem& LinkedList::frontNode() const
{
    return head->elem;
}
void LinkedList::removeFront()
{
    Snode* tmp = head;
    head = head->next;
    delete tmp;
}
void LinkedList::addFront(Elem newElem)
{   
    Snode* newSnode = new Snode;
    newSnode->elem = newElem;
    newSnode->next = head;
    head = newSnode;
}
void LinkedList::print()
{
    Snode *traverse = head;
    while(traverse != NULL) 
    {
        cout << traverse->elem << endl;
        traverse = traverse->next;
    }
}
int main()
{
    Elem hello = "Hello World";
    LinkedList* newLink = new LinkedList(hello);
    cout << "Seg?" <<endl;
    if(newLink->isEmpty())
    {
        cout << "Bool isEmpty(): true" <<endl;
    }
    else
    {
        cout << "Bool isEmpty(): flase" <<endl;
    }
    newLink->addFront("Hi");
    newLink->addFront("hello");
    newLink->print();
    newLink->removeFront();
    newLink->print();
    
    delete newLink;
    return 0;
}