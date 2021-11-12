/**
 * @file fib.cpp
 * Contains Fibonacci-number generating functions both utilizing and not
 * utilizing memoization.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include "fib.h"

#include <map>

using std::map;

/**
 * Calculates the nth Fibonacci number where the zeroth is defined to be
 * 0.
 * @param n Which number to generate.
 * @return The nth Fibonacci number.
 */
unsigned long fib(unsigned long n)
{
    /* Your code goes here! */
    if(n == 0)
    {
        return 0;
    }
    else if(n == 1){
        return 1;
    }
    else
    {
        return fib(n -1) + fib(n - 2);
    }
    return 0;
}

/**
 * Calculates the nth Fibonacci number where the zeroth is defined to be
 * 0. This version utilizes memoization.
 * @param n Which number to generate.
 * @return The nth Fibonacci number.
 */
unsigned long memoized_fib(unsigned long n)
{
    /* Your code goes here! */
    /*
        Declare a static map that we can use throughout the call of the function.
        The static modifier allows us to keep using the same variable as if it was
        a global variable SPECIFIC to the function. We can keep adding to the map
        for the duration of the function's existence, i.e. as long as we keep
        calling it.
    */
    static map<unsigned long, unsigned long> dictionary = {{0,0}, {1,1},};
    map<unsigned long, unsigned long>::iterator iter = dictionary.find(n);
    /*
        Here we have attempted to find an existing value within our map. However,
        it will return the end if the value does not exist, and thus we will need 
        to push the new calculated value into our map.

        If our value does exist, then we can simply get its associated value.
    */
    if(iter != dictionary.end())
    {
        return iter->second;
    }
    else
    {
        unsigned long newEntry = memoized_fib(n - 1) + memoized_fib(n - 2);
        dictionary[n] = newEntry;
        return newEntry;
    }
}
