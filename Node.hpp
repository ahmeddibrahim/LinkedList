#include <stdio.h>

class Node
{
    private: 
        int data;
        Node * next;

    public:
        Node();
        Node(int data);
        int getData();
        void setData(int data);
        Node* getNext();
        void setNext(Node* next);
        ~Node();

};

Node::Node(){
    next = NULL;
}

Node::Node(int data):Node(){
    this->data = data;
}

int Node::getData(){
    return data;
}

void Node::setData(int data){
    this->data = data;
}

Node* Node::getNext(){
    return next;
}

void Node::setNext(Node* next){
    this->next = next;
}
Node::~Node(){}