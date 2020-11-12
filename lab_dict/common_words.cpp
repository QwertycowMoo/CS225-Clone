/**
 * @file common_words.cpp
 * Implementation of the CommonWords class.
 *
 * @author Zach Widder
 * @date Fall 2014
 */

#include "common_words.h"

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using std::string;
using std::vector;
using std::ifstream;
using std::cout;
using std::endl;
using std::feof;

string remove_punct(const string& str)
{
    string ret;
    std::remove_copy_if(str.begin(), str.end(), std::back_inserter(ret),
                        [](int c) {return std::ispunct(c);});
    return ret;
}

CommonWords::CommonWords(const vector<string>& filenames)
{
    // initialize all member variables
    
    init_file_word_maps(filenames);
    init_common();
}

void CommonWords::init_file_word_maps(const vector<string>& filenames)
{
    // make the length of file_word_maps the same as the length of filenames
    file_word_maps.resize(filenames.size());
    // go through all files
    for (size_t i = 0; i < filenames.size(); i++) {
        // get the corresponding vector of words that represents the current
        // file
        vector<string> words = file_to_vector(filenames[i]);
        /* Your code goes here! */
        map<string, unsigned int>& wordmap = file_word_maps[i];
        for (unsigned i = 0; i < words.size(); ++i){ 
            //get the last map in the vector of maps and see if the word exists in that map
            
            map<string, unsigned int>::iterator lookup = wordmap.find(words[i]);
            if (lookup != wordmap.end()) {
                lookup->second += 1; //add one to the word count
            } else {
                wordmap[words[i]] = 1;
            }
        }
        
    }
}

void CommonWords::init_common()
{
    /* Your code goes here! */
    for (map<string, unsigned int> wordmap : file_word_maps) {
        //individual wordmaps
        for(std::pair<string, unsigned int> wordpair: wordmap) {
            map<string, unsigned int>::iterator lookup = common.find(wordpair.first);
            if (lookup != common.end()) {
                lookup->second += 1;
            } else {
                common[wordpair.first] = 1;
            }
        }
    }
}

/**
 * @param n The number of times to word has to appear.
 * @return A vector of strings. The vector contains all words that appear
 * in each file >= n times.
 */
vector<string> CommonWords::get_common_words(unsigned int n) const
{
    vector<string> out;
    /* Your code goes here! */
    for (std::pair<string, unsigned int> wordpair: common) {
        string word = wordpair.first;
        unsigned count = wordpair.second;
        //std::cout << "word: " << word << " count: " << count << "filewordmaps size: " << file_word_maps.size() - 1<< std::endl;
        bool shouldAdd = true;
        if (count == file_word_maps.size()) {
            for (std::map<string, unsigned int> wordmap: file_word_maps) {
                map<string, unsigned int>::iterator lookup = wordmap.find(word);
                
                if (lookup->second < n) {
                    shouldAdd = false;
                    break;
                }

            }
            if (shouldAdd) {
                out.push_back(word);
            }
        }
    }
    return out;
}

/**
 * Takes a filename and transforms it to a vector of all words in that file.
 * @param filename The name of the file that will fill the vector
 */
vector<string> CommonWords::file_to_vector(const string& filename) const
{
    ifstream words(filename);
    vector<string> out;

    if (words.is_open()) {
        std::istream_iterator<string> word_iter(words);
        while (!words.eof()) {
            out.push_back(remove_punct(*word_iter));
            ++word_iter;
        }
    }
    return out;
}
