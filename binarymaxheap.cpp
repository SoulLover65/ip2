#include "your_structure.hpp"

#include <algorithm>

namespace ip2
{
    MaxHeap::MaxHeap()
    {
        impl = new MaxHeapImpl();
    }

    // Copy constructor (Rule of 3)
    MaxHeap::MaxHeap(const MaxHeap& other)
    {
        impl = new MaxHeapImpl();
        impl->heap = other.impl->heap;
    }

    // Copy assignment operator (Rule of 3)
    MaxHeap& MaxHeap::operator=(const MaxHeap& other)
    {
        if (this != &other)
        {
            delete impl;
            impl = new MaxHeapImpl();
            impl->heap = other.impl->heap;
        }

        return *this;
    }

    MaxHeap::~MaxHeap()
    {
        delete impl;
    }

    // Insert an element into the heap
    void MaxHeap::insert(int value)
    {
        impl->heap.push_back(value);
        heapifyUp(impl->heap.size() - 1);
    }

    // Remove the maximum element (root) and return it
    int MaxHeap::removeMax()
    {
        if (impl->heap.empty())
        {
            throw MaxHeapException();
        }

        int max = impl->heap[0];
        impl->heap[0] = impl->heap.back();
        impl->heap.pop_back();

        if (!impl->heap.empty())
        {
            heapifyDown(0);
        }

        return max;
    }

    // Return the maximum element (root) without removing it
    int MaxHeap::peekMax()
    {
        if (impl->heap.empty())
        {
            throw MaxHeapException();
        }

        return impl->heap[0];
    }

    // Print the heap
    void MaxHeap::printHeap()
    {
        for (int value : impl->heap)
        {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    // Check if the heap is empty
    bool MaxHeap::isEmpty() const
    {
        return impl->heap.empty();
    }

    // Get the size of the heap
    int MaxHeap::size() const
    {
        return impl->heap.size();
    }

    // --------------------- Helper functions for heap operations ---------------------

    // Implementation of heapify up operation (preserve max-heap property)
    void MaxHeap::heapifyUp(int index)
    {
        while (index > 0 && impl->heap[parent(index)] < impl->heap[index])
        {
            std::swap(impl->heap[parent(index)], impl->heap[index]);
            index = parent(index);
        }
    }

    void MaxHeap::heapifyDown(int index)
    {
        int left = leftChild(index);
        int right = rightChild(index);
        int largest = index;

        if (left < impl->heap.size() && impl->heap[left] > impl->heap[largest])
        {
            largest = left;
        }

        if (right < impl->heap.size() && impl->heap[right] > impl->heap[largest])
        {
            largest = right;
        }

        if (largest != index)
        {
            std::swap(impl->heap[index], impl->heap[largest]);
            heapifyDown(largest);
        }
    }

    // Helper function to get the parent index
    int MaxHeap::parent(int index)
    {
        return (index - 1) / 2;
    }

    // Helper function to get the left child index
    int MaxHeap::leftChild(int index)
    {
        return 2 * index + 1;
    }

    // Helper function to get the right child index
    int MaxHeap::rightChild(int index)
    {
        return 2 * index + 2;
    }


}
