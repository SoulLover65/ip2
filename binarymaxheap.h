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
        // Nested struct StructureImplementation (only data)
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

        // Custom copy constructor and assignment operator (Rule of 3)
        MaxHeap(const MaxHeap& other);
        MaxHeap& operator=(const MaxHeap& other);
    };
}

#endif // BINARYMAXHEAP_H_INCLUDED
