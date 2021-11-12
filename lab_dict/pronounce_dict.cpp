/**
 * @file pronounce_dict.cpp
 * Implementation of the PronounceDict class.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include "pronounce_dict.h"

#include <iterator>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

using std::string;
using std::map;
using std::vector;
using std::ifstream;
using std::istream;
using std::istream_iterator;
using std::stringstream;

/**
 * Constructs a PronounceDict from a CMU pronunciation dictionary
 * file. See http://www.speech.cs.cmu.edu/cgi-bin/cmudict .
 * @param pronun_dict_filename Filename of the CMU pronunciation
 * dictionary.
 */
PronounceDict::PronounceDict(const string& pronun_dict_filename)
{
    ifstream pronun_dict_file(pronun_dict_filename);
    string line;
    if (pronun_dict_file.is_open()) {
        while (getline(pronun_dict_file, line)) {
            /* Used to break the line by whitespace. The CMU Dict does this for
             * separating words from their pronunciations. */
            stringstream line_ss(line);
            istream_iterator<string> line_begin(line_ss);
            istream_iterator<string> line_end;
            if (line[0] != '#' && *line_begin != ";;;") {
                /* Associate the word with the rest of the line
                 * (its pronunciation). */
                istream_iterator<string> temp_itr = line_begin;
                dict[*temp_itr] = vector<string>(++line_begin, line_end);
            }
        }
    }
    /* If it's not open then... well... just don't do anything for the sake
     * of simplicity. */
}

/**
 * Constructs a PronounceDict from a CMU std::map mapping the word
 * to a vector of strings which represent the pronunciation.
 * @param pronun_dict Maps a string word to a vector of strings
 * representing its pronunciation.
 */
PronounceDict::PronounceDict(const map<string, vector<string>>& pronun_dict)
    : dict(pronun_dict)
{
    /* Nothing to see here. */
}

/**
 * Uses the dictionary to determine if the two words are homophones.
 * @param word1 First word to be tested.
 * @param word2 Second word to be tested.
 * @return true if the two words are homophones, false otherwise (or
 * one or both words weren't in the dictionary).
 * Note: The word keys in the dictionary are stored in uppercase.
 */
bool PronounceDict::homophones(const string& word1, const string& word2) const
{
    /* Your code goes here! */
    /*
        We need to transform our strings to uppercase first, before we can start
        comparing it to any values in our dictionary. The CMU pronounciation dictionary
        is stored in our map "dict". 
    */
    
    string string1 = word1;
    string string2 = word2;

    std::transform(string1.begin(), string1.end(), string1.begin(), ::toupper);
    std::transform(string2.begin(), string2.end(), string2.begin(), ::toupper);

    /*
        We should also check to see if the words even exist in the dictionary, or
        if the words have the same number of syllables. These are both dead giveaways
        that our words are NOT homophones. 
    */

    if(dict.count(string1) == 0 || dict.count(string2) == 0)
    {
        return false;
    }

    /*
        Since we want to look at the pronounciation of each variable, we look at how
        our dictionary is formatted. The dictionary maps strings to vectors of strings
        that contain their pronounciation. Thus, we want to get the vectors of strings
        associated with our words, or the pronounciations of such. We can use the 
        at() feature of map to get a reference to those estrings, and compare
        the values of each vector to evaluate whether or not the words are 
        homophones.
    */

    vector<string> pronounciation1 = dict.at(string1);
    vector<string> pronounciation2 = dict.at(string2);

    if(pronounciation1.size() != pronounciation2.size())
    {
        return false;
    }
    for(size_t i = 0; i < pronounciation1.size(); i++)
    {
        if(pronounciation1[i] != pronounciation2[i])
        {
            return false;
        }
    }

    return true;
}
