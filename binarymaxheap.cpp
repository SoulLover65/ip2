#include "your_structure.hpp"

namespace ip2
{
    MaxHeap::MaxHeap()
    {
        impl = new MaxHeapImpl();
    }

    MaxHeap::~MaxHeap()
    {
        delete impl;
    }
}
