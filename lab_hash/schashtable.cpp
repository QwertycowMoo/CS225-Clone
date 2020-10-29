/**
 * @file schashtable.cpp
 * Implementation of the SCHashTable class.
 */

#include "schashtable.h"
#include <iostream>
 
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
    std::cout << "elements: " << elems << std::endl;
    std::cout << "shouldResize: " << shouldResize() << std::endl;
    if (shouldResize()) {
        resizeTable();
    }
    unsigned hashedKey = hashes::hash(key, size);

    std::list< std::pair<K,V> >& listAtHashIndex = table[hashedKey];
    //not sure if this is supposed to be here because write up says you don't need to care about duplicate keys but it still is a sc hash table
    // if (listAtHashIndex.size() != 0) {
    //     listAtHashIndex.erase(listAtHashIndex.begin());
    // }
    listAtHashIndex.push_back(std::pair<K, V>(key, value));
    elems++;
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
    // prevent warnings... When you implement this function, remove this line.
    unsigned hashedKey = hashes::hash(key, size);
    std::list< std::pair<K,V> >& listAtHashIndex = table[hashedKey];
    for (size_t i = 0; i < listAtHashIndex.size(); i++) {
        it = listAtHashIndex.begin();
        listAtHashIndex.erase(it);
    }
    

}

template <class K, class V>
V SCHashTable<K, V>::find(K const& key) const
{

    /**
     * @todo: Implement this function.
     */ 
    unsigned hashedKey = hashes::hash(key, size);
    std::list< std::pair<K,V> >& listAtHashIndex = table[hashedKey];

    for (auto it = listAtHashIndex.begin(); it != listAtHashIndex.end(); ++it) {
        if (it->first == key) {
            return it->second;
        }
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

     //need to fix this
    size_t newSize = size * 2;
    newSize = findPrime(newSize);
    size = newSize;
    std::list<std::pair<K, V>>* newTable = new std::list<std::pair<K, V>>[newSize];

    for (size_t i = 0; i < (*table).size(); i++) {
        K key = table[i].begin()->first;
        V value = table[i].begin()->second;
        unsigned newHash = hashes::hash(key, newSize);
        
        std::list< std::pair<K,V> >& newlistHashIdx = newTable[newHash];
        newlistHashIdx.push_back(std::pair<K, V>(key, value));
    }
    auto toDelete = table;
    table = newTable;
    delete[] toDelete;
}
