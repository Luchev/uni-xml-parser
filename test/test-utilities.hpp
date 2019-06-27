#pragma once
#include <malloc.h>

/**
 * Check if a function has memory leaks
 * 
 * Provided a function check if the memory used before
 * and after calling the function is the same
 * Avoid using streams as this method does not work
 * with functions that use buffers like cin/cout/fstream
 * 
 */
template <class T>
bool testForMemoryLeak(T (*function)()) {
    struct mallinfo before, after;
    before = mallinfo();
    function();
    after = mallinfo();
    return (after.uordblks - before.uordblks) == 0;
}
