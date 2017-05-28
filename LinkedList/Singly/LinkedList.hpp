#if !defined LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <string>
#include <sstream>

#include "ListNode.hpp"

template <typename T> class LinkedList
{

public:

    // Constructs an empty linked list.
    LinkedList()
    {
        head = nullptr;
    }

    // Returns true if list is empty.
    bool isEmpty()
    {
        return (head == nullptr);
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
            ListNode<T> *travNode = head;
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
            ListNode<T> *travNode = head;
            int nodeCounter = 1;
            while(travNode->next != nullptr){
                travNode = travNode->next;
                nodeCounter++;
            }
            return nodeCounter;
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
            ListNode<T> *nextNode = head;

            s += "The amount of items in the list is ";
            ss << getSize();
            s += ss.str();
            ss.str("");
            ss.clear();
            s += "\nThe elements in the list are ";
            do{
                s += "\n";
                ss << nextNode->data;
                s += ss.str();
                ss.str("");
                ss.clear();
                nextNode = nextNode->next;
            }while(nextNode != nullptr);
        }
        return s;
    }

    // Add a node storing the integer value `val` at the front of the list.
    bool addFirst(T val)
    {
        if(isEmpty()){
            head = new ListNode<T>(val);
            return true;
        }
        else if(!isEmpty()){
            ListNode<T> *newNode = new ListNode<T>(val, head);
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
        else if(!isEmpty()){
            ListNode<T> *travNode = head;
            while(travNode->next != nullptr){
                travNode = travNode->next;
            }
            ListNode<T> *newNode = new ListNode<T>(val);
            travNode->next = newNode;
            return true;
        }
        else{
            return false;
        }
    }

    // Add a node containing `val` after position `index`, if it exists.
    bool addAfterPos(T val, int index)
    {
        if(index > getSize() || index < 1){
            return false;
        }
        else if(index == getSize()){
            return addLast(val);
        }
        else{
            ListNode<T> *travNode = head;
            for(int i = 1; i < index; i++){
                travNode = travNode->next;
            }
            ListNode<T> *newNode = new ListNode<T>(val, travNode->next);
            travNode->next = newNode;
            return true;
        }
    }

    // Retrieve data in node located at position `index`, if it exists.
    T getAtPos(int index)
    {
        if(index > getSize() || index < 1){
            return -1;
        }
        else{
            ListNode<T> *travNode = head;
            for(int i = 1; i < index; i++){
                travNode = travNode->next;
            }
            return travNode->data;
        }
    }

    // Delete the `n`th node in the list, if it exists.
    bool deleteAtPos(int index)
    {
        if(index > getSize() || index < 1){
            return false;
        }
        else if(index == 1){
            ListNode<T> *toDelete = head;
            head = head->next;
            delete[] toDelete;
            return true;
        }
        else if(index == getSize()){
            ListNode<T> *travNode = head;
            while(travNode->next->next != nullptr){
                travNode = travNode->next;
            }
            ListNode<T> *toDelete = travNode->next;
            delete[] toDelete;
            travNode->next = nullptr;
            return true;
        }
        else{
            ListNode<T> *travNode = head;
            for(int i = 1; i < (index - 1); i++){
                travNode = travNode->next;
            }
            ListNode<T> *toDelete = travNode->next;
            travNode->next = toDelete->next;
            delete[] toDelete;
            return true;
        }
    }

    // Return a pointer to node containing `n`, or `NULL` if not found.
    ListNode<T> *searchPointer(T n)
    {
        ListNode<T> *travNode = head;
        while(travNode->data != n && travNode->next != nullptr){
            travNode = travNode->next;
        }
        if(travNode->data == n){
            return travNode;
        }
        else{
            return nullptr;
        }
    }

    // Return a one-based index to node containing `n`, or `-1` if not found.
    int searchIndex(T n)
    {
        ListNode<T> *travNode = head;
        int index = 1;
        while(travNode->data != n && travNode->next != nullptr){
            travNode = travNode->next;
            index++;
        }
        if(travNode->data == n){
            return index;
        }
        else{
            return -1;
        }
    }

private:

    // The head member contains a pointer to the first node in the list.
    ListNode<T> *head;

};

#endif
