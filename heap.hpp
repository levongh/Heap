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

private:
    struct mem_info_t
    {
        struct mem_info_t* next;
        size_t size;
        bool is_free;
    };
    mem_info_t* root;
    char* heap_end;
};
