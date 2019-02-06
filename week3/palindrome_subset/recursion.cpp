//
//  recursion.cpp
//  Recursion
//
//  Created by jim bailey on 1/23/19.
//
//  This work by Jim Bailey is licensed under a Creative Commons Attribution
//  4.0 International License.
//

#include "recursion.hpp"
#include <iostream>
#include <string>
#include <sstream>


using namespace std;

bool recPalindrome ( const std::string & word )
{
    unsigned int wsize = word.size();
    if( wsize < 2 )
        return true;
    if( word[0] != word[wsize-1] )
        return false;
    return recPalindrome( word.substr(1,wsize-2) );
}

bool isPalindrome(std::string word)
{
    return recPalindrome( word);
}

// Since output needs to start as an empty string, then set the default value of
// output to ""
void recPrintAllSubsets(const std::string & word, std::string output = "" ) {
    // Each call to recPrintAllSubsets excludes the first letter of the word,
    // move each recursive call to the base case.
    if ( word == "" ) {
        // couts the current contents of output.
        cout << output << "  ";
    }
    else {
        recPrintAllSubsets (word.substr(1), output + word[0]);
        recPrintAllSubsets (word.substr(1), output);
    }
}

void printAllSubsets(std::string word)
{
    recPrintAllSubsets(word);
}
