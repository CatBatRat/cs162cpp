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
#include <sstream>


using namespace std;

bool recPalindrome(const std::string & word, int end, int start=0)
{
    if( start >= end )
        return true;
    if( word[start] != word[end] )
        return false;
    return recPalindrome( word, --end, ++start );
}

bool isPalindrome(std::string word)
{
    return recPalindrome( word, word.size()-1 );
}

void recPrintAllSubsets(std::string word, std::string output)
{
    static const string wordBase = word;
    if ( word == "" )
    {
        cout << output << "  ";
    }
    else
    {
        recPrintAllSubsets (word.substr(1), output);
        recPrintAllSubsets (word.substr(1), output + word[0]);
    }
}

void printAllSubsets(std::string word)
{
    recPrintAllSubsets(word, "");
}
