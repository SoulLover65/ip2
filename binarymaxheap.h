//Makefile commands:
// make — Builds everything
// make build — Builds the main executable
// make run — Runs the main executable
// make build_run — Builds and runs the main executable
// make test_build — Builds the test executable
// make test_run — Runs the test executable
// make test_build_run — Builds and runs the test executable
// make clean — Cleans all generated files


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
        MaxHeap operator+(const MaxHeap& other);             // Union of the two Heaps
        MaxHeap& operator+=(const MaxHeap& other);

        MaxHeap operator-(const MaxHeap& other);              // Set difference of the two heaps
        MaxHeap& operator-=(const MaxHeap& other);

        MaxHeap operator*(const MaxHeap& other);              //Leaves only the intersection of the two heaps
        MaxHeap& operator*=(const MaxHeap& other);

        MaxHeap operator/(const MaxHeap& other);              //Leaves only the symmetric difference of the two heaps
        MaxHeap& operator/=(const MaxHeap& other);

        // Element operators
        MaxHeap& operator+();          // Add a single element at the end
        MaxHeap& operator++();          // Insert the root element again
        MaxHeap& operator-();           // Remove a single element at the end
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
