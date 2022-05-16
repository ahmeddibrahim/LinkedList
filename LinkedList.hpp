using namespace std;
#include <stdio.h>
#include <iostream>
#include <limits.h>
#include "Node.hpp"

class LinkedList
{
    private:
        Node* head;
        Node* tail;
        int size;
    
    public:
        LinkedList();
        int getSize();
        bool insertAtFirst(int item);
        bool insertAtEnd(int item);
        int searchForItem(int item);
        bool removeByItem(int item);
        void printList();
        void emptyList();
        ~LinkedList();

};

LinkedList::LinkedList(){
    head=tail=NULL;
    size = 0;
}
int LinkedList::getSize(){
    return size;
}

bool LinkedList::insertAtFirst(int item){

    Node* newNode = new Node(item);
    if(size==0) // first input to the list, set head and tail to this node
       head = tail = newNode;
    else //  else the list has data
    {
        Node* previousHead = head; // store the current head
        head = newNode; // set head to the new node
        head->setNext(previousHead);// let the new head point to the previous head
    }
    size++;
    return true;
}

bool LinkedList::insertAtEnd(int item){

    Node* newNode = new Node(item);
    if(size==0) 
       head = tail = newNode; // first input to the list, set head and tail to this node
    else
    {
        tail->setNext(newNode); // add the node after the tail
        tail = tail->getNext(); // make the tail be this new node
    }
    size++;
    return true;
}

int LinkedList::searchForItem(int item){

    Node* curr = head;
    int index = 0;
    while(curr!=NULL)
    {
        if(curr->getData() == item)
            return index;
        index++;
        curr=curr->getNext();
    }
    return -1;
}

bool LinkedList::removeByItem(int item){
    Node* curr = head;
    Node* prev = NULL;
    while(curr!=NULL)
    {
        if(curr->getData() == item)
        {
            if(prev == NULL) // this means we are removing the head
            {
                head = curr->getNext(); // assign the head to next node
            }
            else 
            {
                Node* next = curr->getNext(); // get the next node
                prev->setNext(next); // connect the previous node to the next node from the current
            }
            
            delete curr; // free the removed node
            size--; // decrease the size
            return true;
        }
        prev = curr; // keeping track of the previous node
        curr=curr->getNext();
    }
    return false;
}

void LinkedList::printList()
{
    Node* curr = head;
    cout<< "[ " ;
    while(curr!=NULL){
        cout<< " "<<curr->getData()<<" ,";
        curr = curr->getNext();
    }

    cout<<" ] "<<endl;
}
void LinkedList::emptyList(){
    if(head==NULL)
        return;

    Node* curr;
    while(head!=NULL){
        curr = head;
        head = head->getNext();
        delete curr;
        size--;
    }
    head = tail = NULL;
}

LinkedList::~LinkedList(){// deconstructor
    emptyList();
}