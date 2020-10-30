/**
 * @file lphashtable.cpp
 * Implementation of the LPHashTable class.
 */
#include "lphashtable.h"
#include <iostream>

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
    for (size_t i = 0; i < size; i++){
        if (table[i]) {
            delete table[i];
        }
    }

       
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
    unsigned hashedIndex = hashes::hash(key, size);
    elems++;
    if (shouldResize()) {
        //std::cout << "resizing" << std::endl;
        resizeTable();
        hashedIndex = hashes::hash(key, size);
    }
    while (should_probe[hashedIndex]) {
        hashedIndex++;
        if (hashedIndex == size) {
            hashedIndex = 0;
        }
    }
    should_probe[hashedIndex] = true;
    //std::cout << "inserting: " << key << std::endl;
    table[hashedIndex] = new std::pair<K, V>(key, value);
   
}

template <class K, class V>
void LPHashTable<K, V>::remove(K const& key)
{
    /**
     * @todo: implement this function
     */
    //std::cout << "remove:" << std::endl;
    int indx = findIndex(key);
    if (indx != -1){
        table[indx] = nullptr;
        should_probe[indx] = false;
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
    unsigned hashedIndex = hashes::hash(key, size);
    unsigned sentinel = hashedIndex;
    //std::cout << "size: " << size << std::endl;
    while (should_probe[hashedIndex]) {
        if (table[hashedIndex]->first == key) {
            //std::cout << "returning inside: " << hashedIndex << std::endl;
            return hashedIndex;
        }
        hashedIndex++;
        if (hashedIndex == size) {
            hashedIndex = 0;
        }
        if (hashedIndex == sentinel) {
            break;
        }
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
    size_t newSize = size * 2;
    newSize = findPrime(newSize);

    //std::cout << "new size: " << newSize << std::endl;
    std::pair<K, V>** newTable = new std::pair<K, V>*[newSize];
    bool* new_should_probe = new bool[newSize];

    //reinitializing
    for (size_t i = 0; i < newSize; i++) {
        newTable[i] = NULL;
        new_should_probe[i] = false;
    }

    for(size_t i = 0; i < size; i++) {
       if (table[i]) {
        K key = table[i]->first;
        V value = table[i]->second;

        unsigned newHash = hashes::hash(key, newSize);
        while (new_should_probe[newHash] == true) {
            newHash++;
            if (newHash == newSize) {
                newHash = 0;
            }
        }
        newTable[newHash] = new std::pair<K, V>(key, value);
        new_should_probe[newHash] = true;
        delete table[i];
       }
   //std::cout << "old index: " << i << " " << key << ", " << value << " now mapped to index " << newHash << " <" << newTable[newHash].begin()->first << ", " << newTable[newHash].begin()->second << std::endl;
    }

    size = newSize;
    auto toDelete = table;
    auto toDeleteBool = should_probe;
    table = newTable;
    should_probe = new_should_probe;
    delete[] toDeleteBool;
    delete[] toDelete;
}
