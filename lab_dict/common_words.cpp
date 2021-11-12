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
#include <map>

using std::string;
using std::vector;
using std::ifstream;
using std::cout;
using std::endl;
using std::feof;
using std::map;

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
        /*
            The index of i corresponds to a specific file. The function init_file_word_maps
            maps the file's words to its corresponding map. Iterate through the vector
            "words" and store its words, as well as the number of times they appear,
            into file_word_maps
        */
        for(auto word: words)
        {
            file_word_maps[i][word] = file_word_maps[i][word] + 1;
        }
    }
}

void CommonWords::init_common()
{
    /* Your code goes here! */
    /*
        This function maps a word to the number of documents that word appears
        in. Iterate through file_word_maps and find how many times each word appears
        in each document.

        Our first for loop iterates through each map in our file_word_maps member.
        Our second for loop iterates through each string in our corresponding map.
    */
    for(auto current_map: file_word_maps)
    {
        for(auto current_string: current_map)
        {
            map<string, unsigned int>::iterator common_elem = common.find(current_string.first);
            /*
                We use find to determine if our current string exists in the file. If so,
                we can increment its number. If not, then we add the string to common
                and initialize its number to one, as the element appears in our
                map but is currently not included in our common elements vector.
            */
            if(common_elem != common.end())
            {
                common_elem->second = common_elem->second + 1;
            }
            else
            {
                common[current_string.first] = 1;
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
    /*
        We want to find each word that appears in EVERY file at least "n" times. 
        Thus, we need to iterate throughout common and check to see if each word
        in common has appeared in every file. If so, we then check to see if that
        word has appeared in EVERY file at least n times.
    */
    for(std::pair<string, unsigned int> it: common)
    {
        if(it.second == file_word_maps.size())
        {
            /*
                The word has appeared in every file. Now we need to see if it appears
                in every file at least n times.
            */
            bool shouldAdd = true;
            for(auto cur_map: file_word_maps)
            {
                if(cur_map[it.first] < n)
                {
                    shouldAdd = false;
                    break;
                }
            }
            if(shouldAdd == true)
            {
                out.push_back(it.first);
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
