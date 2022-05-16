#include "LinkedList.hpp"
#include <limits>
#include <cstddef>

int getNumberFromUser(string statement,bool &flag){
    int input;
    cout<< statement <<endl;
    cin>>input;
    if(cin.fail()|| input>INT_MAX)
    {
        cout<<"Something went wrong!, please try again"<<endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        input = -1;
        flag = false;
    }

    return input;
}

int main(){

    cout<<" Welcome to the LinkedList program"<<endl;
    LinkedList linkedlist;
    int input = -1;
    
    do{
        cout<< " To insert at the Beginning, Press 1"<<endl;
        cout<< " To insert at the End,Press 2"<<endl;
        cout<< " To search for an item, Press 3"<<endl;
        cout<< " To remove an item, Press 4"<<endl;
        cout<<" To print the list, press 5"<<endl;
        cout<<" To end the program, press 0"<<endl;

        cin>>input;


        if(cin.fail())
        {
            cin.clear();
            input = -1;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    
        switch (input)
        {
            case 0 :{
                cout<<" Goodbye"<<endl;
                break;
            }
            case 1:
            {
                
                string statement = " Please enter the number you want to insert at the beginning";
                bool status = true;
                int number = getNumberFromUser(statement, status);
                if(status)// status represents if nothing went wrong when taking the input from the user
                    if(linkedlist.insertAtFirst(number))
                        cout<<" Number entered successfully!"<<endl;
                break;
            }
            case 2:
            {
                string statement = " Please enter the number you want to insert at the end";
                bool status = true;
                int number = getNumberFromUser(statement, status);
                if(status)// status represents if nothing went wrong when taking the input from the user
                    if(linkedlist.insertAtEnd(number))
                        cout<<"Number entered successfully!"<<endl;
                break;
            }
            case 3:
            {
                string statement = " Please enter the number you are searching for";
                bool status = true;
                int number = getNumberFromUser(statement, status);
                if(status)// status represents if nothing went wrong when taking the input from the user
                {    
                    int index = linkedlist.searchForItem(number);
                    if(index!= -1)
                        cout<<" The number you are looking for is at index : " << index <<endl;
                    else
                        cout<<" This number is not in the list"<<endl;
                }
                break;
            }
            case 4:
            {
                string statement = " Please enter the number you want to delete";
                bool status = true;
                int number = getNumberFromUser(statement, status);
                if(status)// status represents if nothing went wrong when taking the input from the user
                { 
                    if(linkedlist.removeByItem(number))
                        cout<<" Number removed successfully"<<endl;
                    else
                        cout<<" Number wasn't found !"<<endl;
                }
                break;
            }
            case 5:
            {
                linkedlist.printList();
                break;
            }
            default:
            {
                cout<<" Please try again!"<<endl;
                break;
            }
        }

    }while(input != 0);



    return 0;
}
