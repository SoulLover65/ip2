#include "binarymaxheap.h"
#include <iostream>

int main()
{
    try
    {
        ip2::MaxHeap heap1;
        heap1.insert(15);
        heap1.insert(20);
        heap1.insert(5);
        heap1.insert(30);

        std::cout << "Heap 1: ";
        heap1.printHeap();

        ip2::MaxHeap heap2;
        heap2.insert(15);
        heap2.insert(40);
        heap2.insert(25);

        std::cout << "Heap 2: ";
        heap2.printHeap();

        // Union of two heaps (heap1 + heap2)
        ip2::MaxHeap heap3 = heap1 + heap2;
        std::cout << "Heap 3 (Union): ";
        heap3.printHeap();

        // Difference of two heaps (heap1 - heap2)
        ip2::MaxHeap heap4 = heap1 - heap2;
        std::cout << "Heap 4 (Set difference): ";
        heap4.printHeap();

        // Intersection of two heaps (heap1 * heap2)
        ip2::MaxHeap heap5 = heap1 * heap2;
        std::cout << "Heap 5 (Intersection): ";
        heap5.printHeap();

        // Symmetric difference of two heaps (heap1 / heap2)
        ip2::MaxHeap heap6 = heap1 / heap2;
        std::cout << "Heap 6 (Symmetric Difference): ";
        heap6.printHeap();

        // Test operators
        heap1 += heap2;
        std::cout << "Heap 1 after += Heap 2: ";
        heap1.printHeap();

        heap1 -= heap2;
        std::cout << "Heap 1 after -= Heap 2: ";
        heap1.printHeap();

        // Remove the max element (root)
        std::cout << "Remove max from Heap 1: " << heap1.removeMax() << std::endl;
        heap1.printHeap();

        // Peek the max element without removal
        std::cout << "Peek max from Heap 1: " << heap1.peekMax() << std::endl;

        // Test post-increment (root element)
        ++heap1;
        std::cout << "Heap 1 after increment (insert root again): ";
        heap1.printHeap();

        // Test post-decrement (remove root element)
        --heap1;
        std::cout << "Heap 1 after decrement (remove root): ";
        heap1.printHeap();

    }
    catch (const ip2::MaxHeapException& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
