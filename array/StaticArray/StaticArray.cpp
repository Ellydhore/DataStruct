/*
    Author: Belleza, E.G.
    About Class: 
    -This implementation of the static integer array requires users to 
     specify a size as an input when creating an instance of this class. 
    -When inserting a new value into an array that already contains non-zero 
     elements, the system prompts the user to remove the element at the 
     specified position to avoid overriding the existing element.
    -Removing an element sets the value at the specified position back to its 
     default value.
*/

#include "../../abstract_classes/AbstractStaticArray.hpp"
#include <iostream>
#include <stdexcept> 

class StaticArray : AbstractStaticArray { 
private:
    int size;
    int* array;

    bool isPositionValid(int position) {
        if(position <= 0 || position > size) {
            std::cerr << "Error: The specified position is outside the valid range for the array.\nPlease provide a position within the allowed bounds." << std::endl;
            return false;
        }     
        return true;
    }

public:
    // Constructor
    StaticArray(int size){
        this->size = size; 
        if(size <= 0) {
            throw std::invalid_argument("Error: Array maximum size must be a positive integer greater than 0.");
        }
        
        // Initialize the array elements to 0 as the default value
        array = new int[this->size];
        for(int i = 0; i < this->size; i++) {
            array[i] = 0;
        }
    }
    
    int get(int position) {
        if(!isPositionValid(position)) {
            return 0;
        }
        int index = position - 1;
        return array[index];
    }

    void insert(int position, int value) {
        if(!isPositionValid(position)) {
            return;
        }
        int index = position - 1;
        if(array[index] != 0) {
            std::cerr << "Error: Unable to override non-zero value.\nPlease remove the existing element at the specified position before inserting a new one." << std::endl;
            return;
        }
        array[index] = value;
    }

    int remove(int position) {
        int removed = get(position);
        int index = position - 1;
        array[index] = 0;
        return removed;
    }

    int getSize() {
        return size;
    }

    void display() {
        std:: cout << "Array [";
        for(int i = 0; i < size; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << "]" << std::endl;
    }

    ~StaticArray() {
        delete[] array; 
    }
};
