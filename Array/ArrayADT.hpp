#ifndef ARRAY_ADT_HPP
#define ARRAY_ADT_HPP

#include <string>
#include <cstring>
#include <sstream>

template <typename T> class ArrayADT
{
private:
	int maxLength;		// max size of array
	int actLength;	    // current number of items in array
	T *dataArray; 	// element array

public:

	// Constructor - creates an empty array. Note that the constructor dynamically
    // allocates the size of the dataArray, but that the size is fixed after initialization.
	ArrayADT(int size)
	{
        maxLength = size;
        actLength = 0;
        dataArray = new T[size];
        for(int i = 0; i < size; i++){
            dataArray[i] = 0;
        }
    }
	// Constructor - creates an already populated array.
	ArrayADT(T a[], int sizeOfA)
    {
        maxLength = sizeOfA;
        actLength = sizeOfA;
        dataArray = new T[sizeOfA];

        std::memcpy(dataArray, a, (sizeof(T) * sizeOfA));
    }

	// getter method to return the size of the array
	int getArraySize()
	{
	    return maxLength;
	}

	// getter method to return the number of items
	int getNoOfItemsInArray()
	{
	    return actLength;
	}

	bool isEmpty()
	{
	    return (actLength == 0);
	}

	bool isFull()
	{
	    return (actLength == maxLength);
	}

	// method to insert a value at a particular index in the array
	bool insert(T val, int index)
	{
	    if(index > maxLength || index < 0){
        return false;
    }
        else{
            if(isEmpty()){
                dataArray[index] = val;
                actLength++;
                return true;
            }
            else{
                for(int i = (maxLength - 1); i >= index; i--){
                    dataArray[i + 1] = dataArray[i];
                }
                dataArray[index] = val;

                if(isFull()){
                    actLength = maxLength;
                }
                else{
                    actLength++;
                }
                return true;
            }
        }
	}

	// method to retrieve a value at a particular index in the array, returns sentinel value 999 if it fails.
    T retrieve(int index)
    {
        if(index > maxLength || index < 0){
        return 999;
        }
        else{
            return dataArray[index];
        }
    }

	// method to remove a value at a particular index in the array
 	bool remove(int index)
 	{
        if(isEmpty()){
            return false;
        }
        else{
            if(index > maxLength || index < 0){
                return false;
            }
            else{
                for(int i = index; i < maxLength; i++){
                    dataArray[i] = dataArray[i + 1];
                }
                dataArray[maxLength - 1] = 0;
                actLength--;
                return true;
            }
        }
 	}

    // method to destroy the array contents
    // and reclaim the memory
    ~ArrayADT()
    {
        delete[] dataArray;
    }

    // method to create a copy of the existing array-data and return it.
    T* copyArray()
    {
        T *copiedArray = new T[maxLength];

        std::memcpy(copiedArray, dataArray, (sizeof(T) * maxLength));

        return copiedArray;
    }

    // method to increase the array to a new size
    bool increaseArraySize(int s)
    {
        T *oldArray = dataArray;
        dataArray = new T[maxLength + s];

        std::memcpy(dataArray, oldArray, (sizeof(T) * maxLength));

        for(int i = maxLength; i < (maxLength + s); i++){
            dataArray[i] = 0;
        }

        maxLength += s;
        delete[] oldArray;

        return true;
    }

    // method to print the number of items in the array, the array size and the content of the array to a string.
    std::string toString()
    {
        std::string s;
        std::ostringstream ss;
        s += "The amount of items in the array is ";
        ss << actLength;
        s += ss.str();
        ss.str("");
        ss.clear();
        s += "\nThe total size of the array is ";
        ss << maxLength;
        s += ss.str();
        ss.str("");
        ss.clear();
        s += "\nThe elements in the array are ";

        for(int i = 0; i < maxLength; i++){
            s += "\n";
            ss << dataArray[i];
            s += ss.str();
            ss.str("");
            ss.clear();
        }
        return s;
    }
};

#endif
