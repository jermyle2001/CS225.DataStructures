/**
 * @file lphashtable.cpp
 * Implementation of the LPHashTable class.
 */
#include "lphashtable.h"

template <class K, class V>
LPHashTable<K, V>::LPHashTable(size_t tsize)
{
    if (tsize <= 0)
        tsize = 17;
    size = findPrime(tsize);
    table = new std::pair<K, V>*[size];
    should_probe = new bool[size];
    for (size_t i = 0; i < size; i++) {
        table[i] = NULL;
        should_probe[i] = false;
    }
    elems = 0;
}

template <class K, class V>
LPHashTable<K, V>::~LPHashTable()
{
    for (size_t i = 0; i < size; i++)
        delete table[i];
    delete[] table;
    delete[] should_probe;
}

template <class K, class V>
LPHashTable<K, V> const& LPHashTable<K, V>::operator=(LPHashTable const& rhs)
{
    if (this != &rhs) {
        for (size_t i = 0; i < size; i++)
            delete table[i];
        delete[] table;
        delete[] should_probe;

        table = new std::pair<K, V>*[rhs.size];
        should_probe = new bool[rhs.size];
        for (size_t i = 0; i < rhs.size; i++) {
            should_probe[i] = rhs.should_probe[i];
            if (rhs.table[i] == NULL)
                table[i] = NULL;
            else
                table[i] = new std::pair<K, V>(*(rhs.table[i]));
        }
        size = rhs.size;
        elems = rhs.elems;
    }
    return *this;
}

template <class K, class V>
LPHashTable<K, V>::LPHashTable(LPHashTable<K, V> const& other)
{
    table = new std::pair<K, V>*[other.size];
    should_probe = new bool[other.size];
    for (size_t i = 0; i < other.size; i++) {
        should_probe[i] = other.should_probe[i];
        if (other.table[i] == NULL)
            table[i] = NULL;
        else
            table[i] = new std::pair<K, V>(*(other.table[i]));
    }
    size = other.size;
    elems = other.elems;
}

template <class K, class V>
void LPHashTable<K, V>::insert(K const& key, V const& value)
{

    /**
     * @todo Implement this function.
     *
     * @note Remember to resize the table when necessary (load factor >= 0.7).
     * **Do this check *after* increasing elems (but before inserting)!!**
     * Also, don't forget to mark the cell for probing with should_probe!
     */

    elems++;
    if(shouldResize())
    {
        resizeTable();
    }
    int idx = hashes::hash(key, size);

    if(!table[idx])
    {
        /*
            If the spot at the index is empty, we can directly insert our value.
        */

        table[idx] = new std::pair<K, V>(key, value);
        should_probe[idx] = true;
    }
    else
    {
        /*
            If the location at the index is NOT empty, then we need to traverse our 
            list until we find an empty spot
        */
        while(should_probe[idx] && table[idx])
        {
            idx = (idx + 1) % size;
        }
        table[idx] = new std::pair<K, V>(key, value);
        should_probe[idx] = true;
    }
    
}

template <class K, class V>
void LPHashTable<K, V>::remove(K const& key)
{
    /**
     * @todo: implement this function
     */
    /*
        Simple remove - just find the corresponding index using findIndex
        function and delete memory associated with such
    */
    int idx = findIndex(key);
    if(idx != -1){
        delete table[idx];
        table[idx] = NULL;
        elems--;
    }
}

template <class K, class V>
int LPHashTable<K, V>::findIndex(const K& key) const
{
    
    /**
     * @todo Implement this function
     *
     * Be careful in determining when the key is not in the table!
     */

    /*
        First, see if the key is at the corresponding hash function, i.e.
        no collision was recorded.
    */
    int k = hashes::hash(key, size);

    if(table[k] && table[k]->first == key)
    {
        /*
            We have two cases when checking our corresponding hashkey: if the value exists
            (which is the first statement) AND if the value is accurate (which is the second
            statement). If both are true, then our key exists at the corresponding index.
        */
        return k;
    }
        /*
            Otherwise, our key does NOT exist in the expected location, and we need to check
            the rest of the list to find where it is. Traverse the rest of the table using
            shouldProbe.

            We traverse through the table starting from our supposed index, until we hit a point 
            is supposedly empty, indicated by should_Probe
        */
    while(should_probe[k] && table[k] && table[k]->first != key)    
    {
        k = (k + 1) % size; //Make sure k is w/in limits of table, can wrap around
    }

    if(table[k] && table[k]->first == key){
        return k;
    }

    return -1;
}

template <class K, class V>
V LPHashTable<K, V>::find(K const& key) const
{
    int idx = findIndex(key);
    if (idx != -1)
        return table[idx]->second;
    return V();
}

template <class K, class V>
V& LPHashTable<K, V>::operator[](K const& key)
{
    // First, attempt to find the key and return its value by reference
    int idx = findIndex(key);
    if (idx == -1) {
        // otherwise, insert the default value and return it
        insert(key, V());
        idx = findIndex(key);
    }
    return table[idx]->second;
}

template <class K, class V>
bool LPHashTable<K, V>::keyExists(K const& key) const
{
    return findIndex(key) != -1;
}

template <class K, class V>
void LPHashTable<K, V>::clear()
{
    for (size_t i = 0; i < size; i++)
        delete table[i];
    delete[] table;
    delete[] should_probe;
    table = new std::pair<K, V>*[17];
    should_probe = new bool[17];
    for (size_t i = 0; i < 17; i++)
        should_probe[i] = false;
    size = 17;
    elems = 0;
}

template <class K, class V>
void LPHashTable<K, V>::resizeTable()
{

    /**
     * @todo Implement this function
     *
     * The size of the table should be the closest prime to size * 2.
     *
     * @hint Use findPrime()!
     */

    //First we find the new size of our hash table using findPrime
    unsigned newSize = findPrime(2 * size);

    /*
        Allocate memory for the new hash table, of size found earlier.
        The table contains a list of pointers to pair types, but we need
        to double dereference so we can use it to act as a pointer. We will
        also initialize this to avoid the possibility of undetermined behavior.
    */
    std::pair<K, V>** newTable = new std::pair<K, V>*[newSize];

    /*
        Also allocate memory for a new should_probe list, it's a dynamic
        array so treat it as such. Also delete the original should_probe
        list whenever and set as such. We should also initialize newProbe
        to avoid possibility of undetermined behavior.
    */
    bool* newProbe = new bool[newSize];
    delete[] should_probe;
    should_probe = newProbe;

    //Here we are initializing our two new dynamic arrays.
    for(unsigned i = 0; i < newSize; i++){
        newTable[i] = NULL;
        should_probe[i] = false;
    }

    /*
        Now we iterate through our original hash table and rehash accordingly,
        following our collision rules like insert.
    */
    for(unsigned i = 0; i < size; i++){
        if(table[i]){
            /*
                We only need to rehash for existing values in our old table. Hash
                using the new size and corresponding values
            */
            K key = table[i]->first;
            size_t idx = hashes::hash(key, newSize);
            if(!newTable[idx]){
                /*
                    If no value in our newTable currently exists, we can just
                    insert the pair/pointer in. Otherwise, we need to operate
                    for collision.
                */
                newTable[idx] = table[i];
                should_probe[idx] = true;
            }
            else{
                /*
                    Otherwise, we need to find the next best location available. Increment 
                    idx until we find a space that is empty for us to work on.
                */
                while(should_probe[idx] && newTable[idx]){  
                    idx = (idx + 1) % newSize;
                }
                newTable[idx] = table[i];
                should_probe[idx] = true;
            }

        }

    }
    /*
        Now we need to correctly set our pointer for the table and update
        the size
    */
    size = newSize;
    delete[] table;
    table = newTable;
} //EoF
