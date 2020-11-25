#include <iostream>
#include <iomanip>
#include "heap.hpp"

namespace {

static const size_t max_heap_size = (10 * 1024); //10 KB
static char heap_memory[max_heap_size];
static char heap_object[sizeof(Heap)];

}

Heap::Heap()
{
    clear();
    root = reinterpret_cast<mem_info_t*>(&heap_memory[0]);
    root->next = nullptr;
    root->size = max_heap_size;
    root->is_free = true;
    heap_end = & heap_memory[max_heap_size - 1];

    std::cout << "Heap initialized" << std::endl;
}

Heap::~Heap()
{
    clear();
    std::cout << "Heap destroyed" << std::endl;
}

void Heap::clear()
{
    for (auto& byte : heap_memory) {
        byte = static_cast<char>(0);
    }
    return;
}

void* Heap::operator new(size_t size)
{
    return reinterpret_cast<void*>(heap_object);
}

Heap* Heap::get_instance()
{
    static Heap* heap = nullptr;
    if (nullptr == heap) {
        heap = new Heap();
    }
    return heap;
}
