/**
 * @file schashtable.cpp
 * Implementation of the SCHashTable class.
 */

#include "schashtable.h"
 
template <class K, class V>
SCHashTable<K, V>::SCHashTable(size_t tsize)
{
    if (tsize <= 0)
        tsize = 17;
    size = findPrime(tsize);
    table = new std::list<std::pair<K, V>>[size];
    elems = 0;
}

template <class K, class V>
SCHashTable<K, V>::~SCHashTable()
{
    delete[] table;
}

template <class K, class V>
SCHashTable<K, V> const& SCHashTable<K, V>::
operator=(SCHashTable<K, V> const& rhs)
{
    if (this != &rhs) {
        delete[] table;
        table = new std::list<std::pair<K, V>>[rhs.size];
        for (size_t i = 0; i < rhs.size; i++)
            table[i] = rhs.table[i];
        size = rhs.size;
        elems = rhs.elems;
    }
    return *this;
}

template <class K, class V>
SCHashTable<K, V>::SCHashTable(SCHashTable<K, V> const& other)
{
    table = new std::list<std::pair<K, V>>[other.size];
    for (size_t i = 0; i < other.size; i++)
        table[i] = other.table[i];
    size = other.size;
    elems = other.elems;
}

template <class K, class V>
void SCHashTable<K, V>::insert(K const& key, V const& value)
{

    /**
     * @todo Implement this function.
     *
     */
    /*
        First, check to see if we need to resize the table. Add one element to loadfactor
            and resize if necessary.
        Calculate hash table index, insert at end of list in index
    */


    /*
        If the key exists, then we don't need to resize the table as we are just
            inserting the value into a pre-existing node. 
    */
    if(keyExists(key)){ 
        //Get index of our key in hash table
        size_t idx = hashes::hash(key, size);
        typename std::list<std::pair<K, V>>::iterator it = table[idx].begin();
        //
        while(it != table[idx].end()){
            if(it->first == key){
                it->second = value;
                return;
            }
            it++;
        }
    }
    else{
        /*
            Otherwise, the key does NOT exist, and we need to add a new element to the table.
            We need to increment the # of elements and check to see if the table needs to be resized.
        */
        elems++;
        if(shouldResize()){
            resizeTable();
        }
        size_t idx = hashes::hash(key, size);
        std::pair<K, V> kvPair(key, value);
        table[idx].push_front(kvPair);
    }

}

template <class K, class V>
void SCHashTable<K, V>::remove(K const& key)
{
    typename std::list<std::pair<K, V>>::iterator it;
    /**
     * @todo Implement this function.
     *
     * Please read the note in the lab spec about list iterators and the
     * erase() function on std::list!
     */
    if(elems == 0)
    {
        return;
    }

    int idx = hashes::hash(key, size);

    for(it = table[idx].begin(); it != table[idx].end(); it++){
        if(it->first == key){
            table[idx].erase(it);
            elems--;
            return;
        }
    }

}

template <class K, class V>
V SCHashTable<K, V>::find(K const& key) const
{

    /**
     * @todo: Implement this function.
     */

    /*
        We want to find the element with the corresponding key. The hash function assigns table
            values based on keys that are passed through, so we need to pass through our key into
            our hash function to find what hash table index it corresponds to.
    */

    //Reference given function keyExists
    if(keyExists(key)){
        size_t idx = hashes::hash(key, size);
        typename std::list<std::pair<K,V>>::iterator itr;
        for(itr = table[idx].begin(); itr != table[idx].end(); itr++){
            if(itr->first == key){
                return itr->second;
            }
        }
    }
    else{
        return V();
    }

    return V();
}

template <class K, class V>
V& SCHashTable<K, V>::operator[](K const& key)
{
    size_t idx = hashes::hash(key, size);
    typename std::list<std::pair<K, V>>::iterator it;
    for (it = table[idx].begin(); it != table[idx].end(); it++) {
        if (it->first == key)
            return it->second;
    }

    // was not found, insert a default-constructed version and return it
    ++elems;
    if (shouldResize())
        resizeTable();

    idx = hashes::hash(key, size);
    std::pair<K, V> p(key, V());
    table[idx].push_front(p);
    return table[idx].front().second;
}

template <class K, class V>
bool SCHashTable<K, V>::keyExists(K const& key) const
{
    size_t idx = hashes::hash(key, size);
    typename std::list<std::pair<K, V>>::iterator it;
    for (it = table[idx].begin(); it != table[idx].end(); it++) {
        if (it->first == key)
            return true;
    }
    return false;
}

template <class K, class V>
void SCHashTable<K, V>::clear()
{
    delete[] table;
    table = new std::list<std::pair<K, V>>[17];
    size = 17;
    elems = 0;
}

template <class K, class V>
void SCHashTable<K, V>::resizeTable()
{
    typename std::list<std::pair<K, V>>::iterator it;
    /**
     * @todo Implement this function.
     *
     * Please read the note in the spec about list iterators!
     * The size of the table should be the closest prime to size * 2.
     *
     * @hint Use findPrime()!
     */

    //Step 1: double array and closest prime to new number, will be new size
    unsigned newSize = findPrime(2 * size);

    //Step 2: declare new table of 
    typename std::list<typename std::pair<K, V>> * newTable = new std::list<std::pair<K, V>>[newSize];

    for(unsigned i = 0; i < size; i++){
        std::list<std::pair<K, V>> &elem = table[i];

        for(typename std::list<typename std::pair<K, V>>::iterator itr = elem.begin(); itr != elem.end(); itr++){
            //Change this maybe - check later with Tyler
            std::pair<K, V> kv_pair = *itr;
            K key = kv_pair.first;
            int hashIndex = hashes::hash(key, newSize);
            newTable[hashIndex].push_back(kv_pair);
        }

    }

delete[] table;
table = newTable;
size = newSize;
}
