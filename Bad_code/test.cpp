#include "binarymaxheap.h"
#include <cassert>
#include <iostream>
#include <fstream>

void testMaxHeap()
{
    // Output test results to a file
    std::ofstream outputFile("test_binarymaxheap_output.txt");

    ip2::MaxHeap heap;

    // Test insert and size
    heap.insert(15);
    heap.insert(20);
    heap.insert(5);
    heap.insert(30);

    assert(heap.size() == 4); // Should have 4 elements
    assert(heap.peekMax() == 30); // Root element should be 30

    outputFile << "Elements are inserted correctly." << std::endl;

    // Test removeMax
    int max = heap.removeMax();
    assert(max == 30); // Max element removed
    assert(heap.size() == 3); // Heap should have 3 elements now

    outputFile << "Elements are removed correctly." << std::endl;

    // Test peekMax again after removal
    assert(heap.peekMax() == 20); // Now root should be 20

    // Test the + operator (union)
    ip2::MaxHeap heap2;
    heap2.insert(15);
    heap2.insert(40);

    ip2::MaxHeap unionHeap = heap + heap2;
    assert(unionHeap.size() == 5); // Should have 5 elements after union

    // Test the - operator (set difference)
    ip2::MaxHeap diffHeap = heap - heap2;
    assert(diffHeap.size() == 2); // Should have 2 elements after difference

    // Test the * operator (intersection)
    ip2::MaxHeap intersectionHeap = heap * heap2;
    assert(intersectionHeap.size() == 1); // Should have 1 element in intersection

    // Test the / operator (symmetric difference)
    ip2::MaxHeap symDiffHeap = heap / heap2;
    assert(symDiffHeap.size() == 3); // Should have 4 elements in symmetric difference

    outputFile << "Arithmetic operations are performed correctly." << std::endl;

    // Test empty heap
    ip2::MaxHeap emptyHeap;
    assert(emptyHeap.isEmpty() == true); // Should be empty

    outputFile << "Empty heap recognised." << std::endl;

    // Test operator++
    ++heap;
    assert(heap.size() == 4); // Heap should have 4 elements after adding root element again

    // Test operator--
    --heap;
    assert(heap.size() == 3); // Heap should have 3 elements after removing root

    outputFile << "Unary operators functional." << std::endl;

    // Test operator! (clear heap)
    bool cleared = !heap;
    assert(heap.isEmpty() == true); // Heap should be empty after clear

    outputFile << "Heap cleared correctly." << std::endl;

    outputFile.close();
}

int main()
{
    testMaxHeap();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
