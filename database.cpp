// Title: Lab 3 - database.cpp
//
// Purpose: **<state your purpose here>
//
// Class: CSC 2430 Winter 2020
// Author: **<your name goes here>

#include "database.h"

// Forward declaration
//** Put the declaration of the sub function you use for binary search here

// This is the value used to score a word not found in the database
const double neutral = 2.0;

// Checks the database for consistency, namely that the words are stored in sorted order
//      and the counts are positive
// Parameters:
//      database - the word database
// Returns:
//      true indicates the words are sored, false  false indicates they are not sorted
bool CheckDatabaseConsistency(Database& database) {
    bool passed;

    passed = true;
    if (database.countWords > 0) {
        // Check counts/scores for first word
        if (database.records[0].occurrenceCount <= 0 || database.records[0].scoreTotal == 0) {
            passed = false;
        }

        // Now do the rest in a loop including checking words are sorted
        for (int i = 1; i < database.countWords; i ++) {
            if (database.records[i-1].word >= database.records[i].word
                || database.records[i].occurrenceCount <= 0) {
                passed = false;
            }
        }
    }
    return passed;
}

// **Add your implementations for InitDatabase, AddWordToDatabase, FindWordInDatabase, and GetInfoAboutDatabase

// **Add your implementation for sub function that you are going to use for binary searching

// **Don't forget to add header comments before each function using the following format:
    // **<Describe what this function does
    // Parameters:
    //      **<parameter name> -- <description of parameter>
    //      **<parameter name> -- <description of parameter>
    //      **<parameter name> -- <description of parameter>
    //      ...
    // Returns:
    //      **<describe meaning of return value or put "nothing" if this is a function declared void>
    // Possible Errors:
    //      **<describe possible errors>
//

