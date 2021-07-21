#include <iostream>
#include <memory>
using namespace std;

/* 
FAILED LINKED LIST
FAILED LINKED LIST
FAILED LINKED LIST
FAILED LINKED LIST
FAILED LINKED LIST
*/

/* 
LINKED LIST EXPLANATION:
a list in which the previous element has the pointer to the next element's memory
this is slower than arrays to find a specific element.

however, while arrays have a finite size, linkedlists can theoretically be infinitely big.
*/
/* 
TYPE 
g++ linekdList.cpp
.\a.exe

to run this file
*/
// simple linked list for int values

/* 
major note:
when making a linked list in C++
remember that when assigning a dereferenced pointer to a variable,
that is now a copy. you have to save the pointers, not the dereferences or else
the linked list won't work.
*/

/* 
I FRICKIN GIVE UP
C++ randomly changes the values of pointers because
it likes to discard things it thinks you don't need anymore!
I tried shared_ptr and it doesn't work!!!
time to do it in javascript. my native language.
*/

class Node
{
public:
    int data;
    Node *next;
    Node(int incomingData)
    {
        data = incomingData;
        next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = NULL;
    }

    // add node to end of linked list
    void append(int data)
    {
        cout << "[ACTION] ATTEMPTING APPEND" << endl;
        // apparently you can't compare types to null
        // you have to compare their pointers to see if they exist
        if (head == NULL)
        {
            Node tempNode(data);
            head = &tempNode;
            return;
        }

        Node *current = head;
        while ((*current).next != NULL)
        {
            // dereference the pointer because
            // current.next is a pointer in itself

            current = (*current).next;
        }

        shared_ptr<Node> smartPtr(current);
        cout << (*smartPtr.get()).data << endl;
        Node newNode = Node(data);
        cout << (*smartPtr.get()).data << endl;
        cout << newNode.data << endl;
        (*smartPtr.get()).next = &newNode;
    }

    void deleteWithData(int data)
    {
        cout << "[ACTION] ATTEMPTING DELETION" << endl;

        if (head == NULL)
        {
            return;
        }

        // incase head is data

        if ((*head).data == data)
        {
            head = (*head).next;
            return;
        }

        // then
        Node *current = head;

        while ((*current).next != NULL)
        {
            if (
                (*(*current).next).data == data && // if next entry is equal
                (*(*current).next).next != NULL    // if next entry exists
            )
            {
                (*current).next = (*(*current).next).next; // set the current next to next next
                current = (*current).next;                 // set the current to the next next
            }
            else
            {
                // set next entry to null, end of linked list
                (*current).next = NULL;
            }
        }
    }

    void printList()
    {
        cout << "[ACTION] ATTEMPTING PRINT" << endl;

        if (head == NULL)
        {
            cout << "EMPTY LIST" << endl;
            return;
        }

        Node current = *head;

        cout << "PRINTING LIST" << endl;

        do
        {
            cout << current.data << endl;
            current = *current.next;
        } while (current.next != NULL);

        cout << current.data << endl;

        cout << "FINISHED PRINTING LIST" << endl;
    }
};

int main()
{
    LinkedList myList = LinkedList();

    cout << "Running Linked List Tests" << endl;

    myList.printList();
    myList.append(1);
    myList.append(2);
    myList.append(3);
    myList.deleteWithData(2);

    cout << "Finished all tasks without error!" << endl;

    return 0;
}