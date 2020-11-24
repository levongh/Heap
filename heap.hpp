#pragma once

class Heap
{
public:
    ~Heap();
    void clear();
    void* allocate(size_t size);
    bool deallocate(void* mem);
    void dump();

    static Heap* get_instance();

private:
    Heap();
    static void* operator new(size_t size);
};
