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

using std::string;
using std::vector;
using std::map;
using std::pair;
using std::ifstream;

/**
 * Constructs an AnagramDict from a filename with newline-separated
 * words.
 * @param filename The name of the word list file.
 */
AnagramDict::AnagramDict(const string& filename)
{
    /* Your code goes here! */
    /*
        We'll open and prase the file like we did in pronounce_dict. We will
        also sort our string by letter to determine the # of occurrences of each
        letter in order to determine whether or not the words are anagrams or not.
        Sorting the word will also allows us to more easily find anagrams, as
        anagrams of the word will contain the exact same string once sorted.
    */

    ifstream wordFile(filename);
    string word;
    if(wordFile.is_open())
    {
        while(getline(wordFile, word))
        {
            /*
                Copy lines into dictionary and sort them for our approach. We need to
                pass in a range of values into sort, so we can't just std::sort(line).
                Thus we can use string's begin() and end() features.
            */

            string sortedstring = word;
            std::sort(sortedstring.begin(), sortedstring.end());
            dict[sortedstring].push_back(word);
        }
    }
    wordFile.close();
}

/**
 * Constructs an AnagramDict from a vector of words.
 * @param words The vector of strings to be used as source words.
 */
AnagramDict::AnagramDict(const vector<string>& words)
{
    /* Your code goes here! */
    /*
        Same concept, except now we just have a string of words. 
    */
    for(unsigned long i = 0; i < words.size(); i++)
    {
        string sortedstring = words[i];
        std::sort(sortedstring.begin(), sortedstring.end());
        dict[sortedstring].push_back(words[i]);
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
    /*
        This function asks us to get the anagrams of a given word. We can use
        our approach to vastly simplify the amount of work that needs to be done.
        We use our sorted approach to accomplish this function.

        First, we check to see if the word even exists in our dictionary, or if any
        anagrams actually exist for the word.
    */

    string sortedstring = word;
    std::sort(sortedstring.begin(), sortedstring.end());
    if(dict.find(sortedstring) == dict.end() || dict.at(sortedstring).size() == 1)
    {
        return vector<string>();
    }
    /*
        We have found that the word exists in the list, AND that it has existing anagrams.
        We can just return the associated vector using map's at() function, which returns
        a reference to the second value at the given key.
    */
    return dict.at(sortedstring);
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
    /*
        Similar to the above, except that now we want to return all known anagrams.
        Thus, we can employ a similar approach, except we just iterate throughout
        the entirety of our dictionary.

        If we want to iterate throughout maps, we need to iterate through its
        "pairs".
    */

    vector<vector<string>> out;
    for(pair<string, vector<string>> anagram_base: dict)
    {
        if(anagram_base.second.size() > 1)
        {
            out.push_back(anagram_base.second);
        }
    }
    return out;
}
