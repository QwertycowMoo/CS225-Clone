/**
 * @file anagram_dict.cpp
 * Implementation of the AnagramDict class.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include "anagram_dict.h"

#include <algorithm> /* I wonder why this is included... */
#include <fstream>
#include <iostream>

using std::string;
using std::vector;
using std::ifstream;

/**
 * Constructs an AnagramDict from a filename with newline-separated
 * words.
 * @param filename The name of the word list file.
 */
AnagramDict::AnagramDict(const string& filename)
{
    /* Your code goes here! */
    ifstream wordsFile(filename);
    string word;
    if (wordsFile.is_open()) {
        /* Reads a line from `wordsFile` into `word` until the file ends. */
        while (getline(wordsFile, word)) {
            //cout << word << endl;
            
        }
    }

}

/**
 * Constructs an AnagramDict from a vector of words.
 * @param words The vector of strings to be used as source words.
 */
AnagramDict::AnagramDict(const vector<string>& words)
{
    /* Your code goes here! */
    for (string word: words) {
        //check through the existing dict and see if this is a permutation of any of the keys
        //std::cout << "word is " << word << std::endl;
        bool alreadyEntered = false;
        for (std::pair<string, vector<string>> dictEntry: dict) {
            
            if (std::is_permutation(word.begin(), word.end(), dictEntry.first.begin(), dictEntry.first.end())) {
                //std::cout << "found permutation!" << std::endl;
                dict[dictEntry.first].push_back(word);
                alreadyEntered = true;
                break;
            }
        }
        if (!alreadyEntered) {
            vector<string> areAnagrams;
            areAnagrams.push_back(word);
            dict[word] = areAnagrams;
        }
        
    }
}

/**
 * @param word The word to find anagrams of.
 * @return A vector of strings of anagrams of the given word. Empty
 * vector returned if no anagrams are found or the word is not in the
 * word list.
 */
vector<string> AnagramDict::get_anagrams(const string& word) const
{
    /* Your code goes here! */
    auto lookup = dict.find(word);
    if (lookup != dict.end()) {
        return lookup->second;
    }
    return vector<string>();
}

/**
 * @return A vector of vectors of strings. Each inner vector contains
 * the "anagram siblings", i.e. words that are anagrams of one another.
 * NOTE: It is impossible to have one of these vectors have less than
 * two elements, i.e. words with no anagrams are ommitted.
 */
vector<vector<string>> AnagramDict::get_all_anagrams() const
{
    /* Your code goes here! */
    vector<vector<string>> allAnagrams;
    for (std::pair<string, vector<string>> dictEntry: dict) {
        if (dictEntry.second.size() >= 2) {
            allAnagrams.push_back(dictEntry.second);
        }
        
    }
    return allAnagrams;
}
