/**
 * @file cartalk_puzzle.cpp
 * Holds the function which solves a CarTalk puzzler.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include <fstream>

#include "cartalk_puzzle.h"

using namespace std;

/**
 * Solves the CarTalk puzzler described here:
 * http://www.cartalk.com/content/wordplay-anyone.
 * @return A vector of (string, string, string) tuples
 * Returns an empty vector if no solutions are found.
 * @param d The PronounceDict to be used to solve the puzzle.
 * @param word_list_fname The filename of the word list to be used.
 */
vector<std::tuple<std::string, std::string, std::string>> cartalk_puzzle(PronounceDict d,
                                    const string& word_list_fname)
{
    vector<std::tuple<std::string, std::string, std::string>> ret;

    /* Your code goes here! */
    /*
        The code solves the specific carTalk puzzle. The word has five letters
        as given by the puzzle. We can read through the entire dictionary and
        determine any homophones that would qualify as such.

        We can determine a word is a homophone by using the homophone function
        we built earlier in pronounce_dict.cpp. If word a is a homophone of word b
        and word a is a homophone of word c, then word b is also a homophone of word c.

        We need to read the whole dictionary file and scan until we get homophones of our
        base word.

        word_list_fname is the list of words we will try to see if we can solve the
        carTalk puzzle with. We need to parse this file and check with our dictionary.

        Our dictionary is given by the member 'd'.
    */

    ifstream wordFile(word_list_fname);
    string word;
    if(wordFile.is_open())
    {
        while(getline(wordFile, word))
        {
            if(word.size() == 5)
            {
                string substr1 = word.substr(1);
                string substr2 = word[0] + word.substr(2);
                if(d.homophones(word, substr1) && d.homophones(word, substr2))
                {
                    ret.push_back(tuple<string, string, string> (word, substr1, substr2));
                }
            }
        }
    }
    return ret;
}
