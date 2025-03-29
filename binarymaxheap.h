#ifndef BINARYMAXHEAP_H_INCLUDED
#define BINARYMAXHEAP_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cassert>
#include <memory>
#include <iostream>
#include <vector>
#include <stdexcept>

namespace ip2
{
    class MaxHeapException : public std::exception
    {
    public:
        const char* what() const noexcept override
        {
            return "MaxHeapException: Invalid operation or state in the heap";
        }
    };

    class MaxHeap
    {
    private:
        // Nested struct MaxHeapImpl (only data)
        struct MaxHeapImpl
        {
            std::vector<int> heap;  // The heap stored as a vector
        };

        MaxHeapImpl* impl;  // Pointer to Implementation

        // Helper functions for heap operations
        void heapifyUp(int index);
        void heapifyDown(int index);
        int parent(int index);
        int leftChild(int index);
        int rightChild(int index);

    public:
        MaxHeap();

        // Custom copy constructor and assignment operator (Rule of 3)
        MaxHeap(const MaxHeap& other);
        MaxHeap& operator=(const MaxHeap& other);

        ~MaxHeap();

        // Function to insert an element
        void insert(int value);

        // Function to remove and return the maximum element
        int removeMax();

        // Function to return the maximum element without removal
        int peekMax();

        // Function to print the heap
        void printHeap();

        // Function to check if the heap is empty
        bool isEmpty() const;

        // Function to get the size of the heap
        int size() const;

        // Arithmetic operators
        MaxHeap operator+(const MaxHeap& other);    // Merge the two heaps
        MaxHeap& operator+=(const MaxHeap& other);

        MaxHeap operator-(const MaxHeap& other);    // Remove first heaps elements that the second also has
        MaxHeap& operator-=(const MaxHeap& other);

        MaxHeap operator*(int scalar);              //Leaves only the intersection of the two heaps
        MaxHeap& operator*=(int scalar);

        MaxHeap operator/(int scalar);              //Leaves only the set difference of the two heaps
        MaxHeap& operator/=(int scalar);

        // Element operators
        MaxHeap& operator+(int value);  // Add a single element
        MaxHeap& operator++();          // Insert the same element
        MaxHeap& operator-(int value);  // Remove the specific element
        MaxHeap& operator--();          // Remove the root element

        // Comparison operators
        bool operator==(const MaxHeap& other) const;    //Checks if the heaps are identical
        bool operator!=(const MaxHeap& other) const;    //Checks if the heaps are not identical
        bool operator<(const MaxHeap& other) const;     //Checks if left heap has less elements than the right one
        bool operator>(const MaxHeap& other) const;     //Checks if left heap has more elements than the right one
        bool operator<=(const MaxHeap& other) const;    //Checks if left heap has  equal amount or less elements than the right one
        bool operator>=(const MaxHeap& other) const;    //Checks if left heap has  equal amount or more elements than the right one

        // Other operators
        bool operator!();               // Clear the heap
        int operator[](int index);     // Access element by index

    };
}

#endif // BINARYMAXHEAP_H_INCLUDED
