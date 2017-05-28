#if !defined CLINKED_LIST_HPP
#define CLINKED_LIST_HPP

#include <string>
#include <sstream>

#include "ListNode.hpp"

template <typename T> class CLinkedList
{

public:

    // Constructs an empty linked list.
    CLinkedList()
    {
        head = new ListNode<T>(999);
    }

    // Construct a liked list with data from an array
    CLinkedList(T a[], int size)
    {
        head = new ListNode<T>(999);
        ListNode<T> *prevNode = head;
        int n = size;
        int sizeCounter = 0;

        for(int i = n; i > 0; i--){
            //std::cout << i << " " << a[n - i] << std::endl;
            ListNode<T> *b = new ListNode<T>(a[n - i]);
            prevNode->next = b;
            prevNode = b;
            sizeCounter++;
            if(sizeCounter == size){
                b->next = head;
            }
        }
    }

    // Return the integer value stored at the front of the list.
    T getFirst()
    {
        if(isEmpty()){
            return head->data;
        }
        else{
            return head->next->data;
        }
    }

    // Return the integer value stored at the end of the list.
    T getLast()
    {
        if(isEmpty()){
            return head->data;
        }
        else if(getSize() == 1){
            return getFirst();
        }
        else{
            ListNode<T> *travNode = head;
            do{
                travNode = travNode->next;
            }while(travNode->next != head);
            return travNode->data;
        }
    }

    // Return the number of nodes in the list.
    int getSize()
    {
        if(isEmpty()){
            return 0;
        }
        else{
            ListNode<T> *travNode = head->next;
            int nodeCounter = 1;
            while(travNode->next != head){
                travNode = travNode->next;
                nodeCounter++;
            }
            return nodeCounter;
        }
    }

    // Add a node storing the integer value `val` at the front of the list.
    bool addFirst(T val)
    {
        ListNode<T> *newNode = new ListNode<T>(val);
        if(isEmpty()){
            head->next = newNode;
            newNode->next = head;
            return true;
        }
        else{
            newNode->next = head->next;
            head->next = newNode;
            return true;
        }
    }

    // Add a node storing the integer value `val` at the end of the list.
    bool addLast(T val)
    {
        if(isEmpty()){
            return addFirst(val);
        }
        else{
            ListNode<T> *newNode = new ListNode<T>(val);
            ListNode<T> *travNode = head->next;
            while(travNode->next != head){
                travNode = travNode->next;
            }
            newNode->next = head;
            travNode->next = newNode;
            return true;
        }
    }

    // Returns true if list is empty
    bool isEmpty()
    {
        return (head->next == nullptr);
    }

    // Add a node containing `val` after position `index`, if it exists.
    bool addAfterPos(T val, int index)
    {
        if(index < 0 || index > getSize()){
            return false;
        }
        else if(index == getSize()){
            ListNode<T> *newNode = new ListNode<T>(val);
            ListNode<T> *travNode = head->next;
            while(travNode->next != head){
                travNode = travNode->next;
            }
            newNode->next = head;
            travNode->next = newNode;
            return true;
        }
        else{
            ListNode<T> *newNode = new ListNode<T>(val);
            ListNode<T> *travNode = head->next;
            for(int i = 1; i < index; i++){
                travNode = travNode->next;
            }
            newNode->next = travNode->next;
            travNode->next = newNode;
            return true;
        }
    }

    // Retrieve data in node located at position `index`, if it exists.
    T getAtPos(int index)
    {
        if(index < 0 || index > getSize()){
            return false;
        }
        else if(index == getSize()){
            ListNode<T> *travNode = head->next;
            while(travNode->next != head){
                travNode = travNode->next;
            }
            return travNode->data;
        }
        else{
            ListNode<T> *travNode = head->next;
            for(int i = 1; i < index; i++){
                travNode = travNode->next;
            }
            return travNode->data;
        }
    }

    // Delete the `n`th node in the list, if it exists.
    bool deleteAtPos(int index)
    {
        if(index < 0 || index > getSize()){
            return false;
        }
        else if(index == 1){
            ListNode<T> *toDelete = head->next;
            head->next = toDelete->next;
            delete[] toDelete;
            return true;
        }
        else if(index == getSize()){
            ListNode<T> *travNode = head->next;
            while(travNode->next->next != head){
                travNode = travNode->next;
            }
            delete[] travNode->next;
            travNode->next = head;
            return true;
        }
        else{
            ListNode<T> *travNode = head->next;
            ListNode<T> *toDelete = nullptr;
            for(int i = 1; i < (index - 1); i++){
                travNode = travNode->next;
            }
            toDelete = travNode->next;
            travNode->next = toDelete->next;
            delete[] toDelete;
            return true;
        }
    }

    // Return a pointer to node containing `n`, or `NULL` if not found.
    ListNode<T> *searchPointer(T n)
    {
        if(isEmpty()){
            return nullptr;
        }
        else{
            ListNode<T> *travNode = head->next;
            while(travNode->next != head && travNode->data != n){
                travNode = travNode->next;
            }
            if(travNode->data == n){
                return travNode;
            }
            else{
                return nullptr;
            }
        }
    }

    // Return a one-based index to node containing `n`, or `-1` if not found.
    int searchIndex(T n)
    {
        if(isEmpty()){
            return -1;
        }
        else{
            ListNode<T> *travNode = head->next;
            int nodeCounter = 1;
            while(travNode->next != head && travNode->data != n){
                travNode = travNode->next;
                nodeCounter++;
            }
            if(travNode->data == n){
                return nodeCounter;
            }
            else{
                return -1;
            }
        }
    }

    // Return a string representation of the list.
    std::string toString()
    {
        std::string s;
        if(isEmpty()){
            s += "This list is empty\n";
        }
        else{
            std::ostringstream ss;
            ListNode<T> *travNode = head->next;

            s += "The list has ";
            ss << getSize();
            s += ss.str();
            ss.str("");
            ss.clear();
            s += " elements.\nThe first element is: ";
            ss << getFirst();
            s += ss.str();
            ss.str("");
            ss.clear();
            s += ", and the last element is ";
            ss << getLast();
            s += ss.str();
            ss.str("");
            ss.clear();
            s += ".\n";
            s += "The elements in the list are ";
            do{
                s += "\n";
                ss << travNode->data;
                s += ss.str();
                ss.str("");
                ss.clear();
                travNode = travNode->next;
            }while(travNode != head);
            s += "\n";
        }
        return s;
    }

    // helper function to indicate the ordinality of an item in a sequence
	std::string ordinality(int n)
	{
        std::string pos;

        if ((n%10 == 1) && (n != 11))
            pos = "st";
        else if ((n%10 == 2) && (n != 12))
            pos = "nd";
        else if ((n%10 == 3) && (n != 13))
            pos = "rd";
        else
            pos = "th";

        return pos;
	}

private:

    // The head member contains a pointer to the first node in the list.
    ListNode<T>* head;

};

#endif
