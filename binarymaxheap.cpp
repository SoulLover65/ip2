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

    // ---------------------- Arithmetic Operators ----------------------

    // Merge the two heaps (union of elements)
    MaxHeap MaxHeap::operator+(const MaxHeap& other)
    {
        MaxHeap result = *this;  // Start with the current heap (copy of this)

        // Add elements from the other heap
        for (int value : other.impl->heap)
        {
            result.insert(value);
        }

        return result;
    }

    // Merge the two heaps and update the current heap
    MaxHeap& MaxHeap::operator+=(const MaxHeap& other)
    {
        // Add elements from the other heap to this heap
        for (int value : other.impl->heap)
        {
            insert(value);
        }

        return *this;
    }

    // Remove elements from the first heap that the second heap also has
    MaxHeap MaxHeap::operator-(const MaxHeap& other)
    {
        MaxHeap result;

        for (int value : impl->heap)
        {
            // Only add elements to result if they are not in the other heap
            if (std::find(other.impl->heap.begin(), other.impl->heap.end(), value) == other.impl->heap.end())
            {
                result.insert(value);
            }
        }

        return result;
    }

    // Remove elements from the current heap that the second heap also has
    MaxHeap& MaxHeap::operator-=(const MaxHeap& other)
    {
        std::vector<int> newHeap;

        for (int value : impl->heap)
        {
            if (std::find(other.impl->heap.begin(), other.impl->heap.end(), value) == other.impl->heap.end())
            {
                newHeap.push_back(value);
            }
        }

        impl->heap = newHeap;
        heapifyDown(0);  // Re-establish the heap property
        return *this;
    }

    MaxHeap MaxHeap::operator*(const MaxHeap& other)
    {
        MaxHeap result;

        for (int value : impl->heap)
        {
            // Add value to result if it's present in both heaps
            if (std::find(other.impl->heap.begin(), other.impl->heap.end(), value) != other.impl->heap.end())
            {
                result.insert(value);
            }
        }

        return result;
    }

    // Modify the heap to leave only the intersection of the two heaps
    MaxHeap& MaxHeap::operator*=(const MaxHeap& other)
    {
        std::vector<int> newHeap;

        for (int value : impl->heap)
        {
            if (std::find(other.impl->heap.begin(), other.impl->heap.end(), value) != other.impl->heap.end())
            {
                newHeap.push_back(value);
            }
        }

        impl->heap = newHeap;
        heapifyDown(0);  // Re-establish the heap property
        return *this;
    }

    // Leaves only the symmetric difference of the two heaps (elements that are in either heap but not in both)
    MaxHeap MaxHeap::operator/(const MaxHeap& other)
    {
        MaxHeap result;

        // Add elements from the current heap that are not in the other heap
        for (int value : impl->heap)
        {
            if (std::find(other.impl->heap.begin(), other.impl->heap.end(), value) == other.impl->heap.end())
            {
                result.insert(value);
            }
        }

        // Add elements from the other heap that are not in the current heap
        for (int value : other.impl->heap)
        {
            if (std::find(impl->heap.begin(), impl->heap.end(), value) == impl->heap.end())
            {
                result.insert(value);
            }
        }

        return result;
    }

    // Leaves only the symmetric difference of the two heaps and modifies the current heap
    MaxHeap& MaxHeap::operator/=(const MaxHeap& other)
    {
        // Temporary heap to hold the symmetric difference
        std::vector<int> newHeap;

        // Add elements from the current heap that are not in the other heap
        for (int value : impl->heap)
        {
            if (std::find(other.impl->heap.begin(), other.impl->heap.end(), value) == other.impl->heap.end())
            {
                newHeap.push_back(value);
            }
        }

        // Add elements from the other heap that are not in the current heap
        for (int value : other.impl->heap)
        {
            if (std::find(impl->heap.begin(), impl->heap.end(), value) == impl->heap.end())
            {
                newHeap.push_back(value);
            }
        }

        // Replace the current heap with the new heap containing only the symmetric difference
        impl->heap = newHeap;
        heapifyDown(0);  // Re-establish the heap property

        return *this;
    }

    // ---------------------- Element Operators ----------------------

    // `operator+()` - Add a default element (0) at the end of the heap
    MaxHeap& MaxHeap::operator+()
    {
        insert(0);  // Use insert method to add the element
        return *this;
    }

    // `operator++()` - Insert the root element again (duplicate the root element)
    MaxHeap& MaxHeap::operator++()
    {
        if (!impl->heap.empty())
        {
            insert(impl->heap[0]);  // Insert the root element (maximum element) again
        }
        else
        {
            throw MaxHeapException();  // If the heap is empty, throw an exception
        }
        return *this;
    }

    // `operator-()` - Remove a single element at the end of the heap
    MaxHeap& MaxHeap::operator-()
    {
        if (!impl->heap.empty())
        {
            impl->heap.pop_back();  // Remove the last element
        }
        else
        {
            throw MaxHeapException();  // If the heap is empty, throw an exception
        }
        return *this;
    }

    // `operator--()` - Remove the root element (maximum element)
    MaxHeap& MaxHeap::operator--()
    {
        if (!impl->heap.empty())
        {
            removeMax();  // Remove the root (maximum) element
        }
        else
        {
            throw MaxHeapException();  // If the heap is empty, throw an exception
        }
        return *this;
    }

    // ---------------------- Comparison Operators ----------------------

    // `operator==()` - Checks if the heaps are identical (have the same elements in the same order)
    bool MaxHeap::operator==(const MaxHeap& other) const
    {
        // Check if the sizes are the same and the elements are identical
        return this->size() == other.size() && impl->heap == other.impl->heap;
    }

    // `operator!=()` - Checks if the heaps are not identical
    bool MaxHeap::operator!=(const MaxHeap& other) const
    {
        // Return true if the heaps are not identical
        return !(*this == other);  // Simply using operator== for the inverse check
    }

    // `operator<()` - Checks if the left heap has fewer elements than the right one
    bool MaxHeap::operator<(const MaxHeap& other) const
    {
        // Compare the sizes of the heaps
        return this->size() < other.size();
    }

    // `operator>()` - Checks if the left heap has more elements than the right one
    bool MaxHeap::operator>(const MaxHeap& other) const
    {
        // Compare the sizes of the heaps
        return this->size() > other.size();
    }

    // `operator<=()` - Checks if the left heap has equal amount or fewer elements than the right one
    bool MaxHeap::operator<=(const MaxHeap& other) const
    {
        // Compare the sizes of the heaps
        return this->size() <= other.size();
    }

    // `operator>=()` - Checks if the left heap has equal amount or more elements than the right one
    bool MaxHeap::operator>=(const MaxHeap& other) const
    {
        // Compare the sizes of the heaps
        return this->size() >= other.size();
    }

    // ---------------------- Other Operators ----------------------

    // `operator!()` - Clears the heap
    bool MaxHeap::operator!()
    {
        impl->heap.clear();  // Clear the underlying heap vector
        return true;         // Return true to indicate the heap was cleared
    }

    // `operator[]` - Access element by index
    int MaxHeap::operator[](int index)
    {
        if (index < 0 || index >= impl->heap.size())
        {
            throw std::out_of_range("Index is out of range");  // Ensure the index is valid
        }

        return impl->heap[index];  // Return the element at the specified index
    }


}
