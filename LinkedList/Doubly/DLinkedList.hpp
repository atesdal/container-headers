#if !defined DLINKED_LIST_HPP
#define DLINKED_LIST_HPP

#include <string>
#include <sstream>
#include "DListNode.hpp"

template <typename T> class DLinkedList
{

public:

    // Constructs an empty linked list.
    DLinkedList()
    {
        head = nullptr;
    }

	// Construct a liked list with data from an array
	DLinkedList(T a[], int size)
	{
        head = new DListNode<T>(a[0]);

        DListNode<T> *prevNode = head;
        int n = size;

        for(int i = (n - 1); i > 0; i--){
            DListNode<T> *b = new DListNode<T>(a[n - i], nullptr, prevNode);
            prevNode->next = b;
            prevNode = b;
        }
	}

    // Return the integer value stored at the front of the list.
    T getFirst()
    {
        if(isEmpty()){
            return -1;
        }
        else{
            return head->data;
        }
    }

    // Return the integer value stored at the end of the list.
    T getLast()
    {
        if(isEmpty()){
            return -1;
        }
        else{
            DListNode<T> *travNode = head;
            while(travNode->next != nullptr){
                travNode = travNode->next;
            }
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
            DListNode<T> *travNode = head;
            int nodeCounter = 1;
            while(travNode->next != nullptr){
                travNode = travNode->next;
                nodeCounter++;
            }
            return nodeCounter;
        }
    }

    // Add a node storing the integer value `val` at the front of the list.
    bool addFirst(T val)
    {
        DListNode<T> *newNode = new DListNode<T>(val);
        if(isEmpty()){
            head = newNode;
            return true;
        }
        else if(!isEmpty()){
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return true;
        }
        else{
            return false;
        }
    }

    // Add a node storing the integer value `val` at the end of the list.
    bool addLast(T val)
    {
        if(isEmpty()){
            return addFirst(val);
        }
        else{
            DListNode<T> *travNode = head;
            while(travNode->next != nullptr){
                travNode = travNode->next;
            }
            DListNode<T> *newNode = new DListNode<T>(val, nullptr, travNode);
            travNode->next = newNode;
            return true;
        }
    }

	// Returns true if list is empty
	bool isEmpty()
	{
        return (head == nullptr);
	}

	// Returns a string formed by concatenating the data fields of all list nodes, starting from the last node.
    std::string toRevString()
    {
        std::string s;
        std::ostringstream ss;
        if(isEmpty()){
            s += "This list is empty\n";
            return s;
        }
        else if(getSize() == 1){
            s += "The elements in the list from right to left are \n";
            ss << head->data;
            s += ss.str();
            s += "\n";
            return s;
        }
        else{
            std::ostringstream ss;
            DListNode<T> *travNode = head;

            while(travNode->next != nullptr){
                travNode = travNode->next;
            }

            s += "The elements in the list from right to left are ";
            do{
                s += "\n";
                ss << travNode->data;
                s += ss.str();
                ss.str("");
                ss.clear();
                travNode = travNode->prev;
            }while(travNode != nullptr);
            s += "\n";
        }
        return s;
    }

    // Add a node containing `val` after position `index`, if it exists.
    bool addAfterPos(T val, int index)
    {
        if(index < 1 || index > getSize()){
            return false;
        }
        else if(index == getSize()){
            return addLast(val);
        }
        else if(isEmpty()){
            return addFirst(val);
        }
        else{
            DListNode<T> *travNode = head;

            for(int i = 1; i < index; i++){
                travNode = travNode->next;
            }
            DListNode<T> *newNode = new DListNode<T>(val, travNode->next, travNode);
            newNode->next->prev = newNode;
            travNode->next = newNode;
            return true;
        }
    }

    // Retrieve data in node located at position `index`, if it exists.
    T getAtPos(int index)
    {
        if(index < 1 || index > getSize()){
            return -1;
        }
        else if(index == 1){
            return getFirst();
        }
        else if(index == getSize()){
            return getLast();
        }
        else{
            DListNode<T> *travNode = head;
            for(int i = 1; i < index; i++){
                travNode = travNode->next;
            }
            return travNode->data;
        }
    }

    // Delete the `n`th node in the list, if it exists.
    bool deleteAtPos(int index)
    {
        if(index < 1 || index > getSize()){
            return false;
        }
        else if(index == 1){
            head = head->next;
            delete[] head->prev;
            head->prev = nullptr;
            return true;
        }
        else if(index == getSize()){
            DListNode<T> *travNode = head;
            while(travNode->next->next != nullptr){
                travNode = travNode->next;
            }
            delete[] travNode->next;
            travNode->next = nullptr;
            return true;
        }
        else{
            DListNode<T> *travNode = head;
            for(int i = 1; i < (index - 1); i++){
                travNode = travNode->next;
            }
            travNode->next = travNode->next->next;
            delete[] travNode->next->prev;
            travNode->next->prev = travNode;
            return true;
        }
    }

    // Return a pointer to node containing `n`, or `NULL` if not found.
    DListNode<T> *searchPointer(T n)
    {
        if(isEmpty()){
            return nullptr;
        }
        else{
            DListNode<T> *travNode = head;
            while(travNode->next != nullptr && travNode->data != n){
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
            DListNode<T> *travNode = head;
            int nodeCounter = 1;
            while(travNode->next != nullptr && travNode->data != n){
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
            DListNode<T> *travNode = head;

            s += "The elements in the list from left to right are ";
            do{
                s += "\n";
                ss << travNode->data;
                s += ss.str();
                ss.str("");
                ss.clear();
                travNode = travNode->next;
            }while(travNode != nullptr);
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
    DListNode<T> *head;

};

#endif
