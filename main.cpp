/// Title: Lab 3 - main.cpp
//
// Purpose: Practice using structs and sorted arrays by implementing  a naive algorithm for performing
// sentiment analysis on movie reviews.
//
// Class: CSC 2430 Winter 2020
// Author: Max Benson
#include <fstream>
#include <chrono>
#include <assert.h>
#include "database.h"

using namespace std;

// Forward declarations
bool BuildDatabase(const string& fileName, Database& database);
double AnalyzeReview(const Database& database, const string& review);

//
// Main program:
//
// First prompts the user for a movie review file which is used to generate a database of
// words, each word being stored by a count of its occurrences and the total score
// associated with it.
//
// Then the main program will repeatedly prompt the user to enter the text of a review
// at console.  When the user enters return the review text is scored using the word database
// and a prediction for the rating is printed.
int main() {
    // Declaration of database structure.  This database should only be
    // using functions defined in database.h
    Database database;

    string fileName;
    string review;

    int numberWords;
    int maxOccurrences;
    int minOccurrences;
    double maxScore;
    double minScore;

    // For timing BuildDatabase
    chrono::time_point<chrono::steady_clock> start;
    chrono::time_point<chrono::steady_clock> end;

    // Get name of file containing movie reviews
    cout << "Enter name of movie review file: ";
    getline(cin, fileName);
    if (fileName.length()== 0) {
        fileName = "movieReviews.txt";
    }

    // Build database from movie review file
    start = chrono::steady_clock::now();
    if (!BuildDatabase(fileName, database)) {
        cout << "Database build failure -- you may need to increase the value of CAPACITY." << endl;
        return 0;
    }
    end = chrono::steady_clock::now();
    cout << chrono::duration<double,milli>(end-start).count() << "ms" << endl;

    // Display some information about the database to
    // check if it seems correct
    GetInfoAboutDatabase(database, numberWords,
                         maxOccurrences, minOccurrences, maxScore, minScore);
    cout << "Number of Words:                   " << numberWords << endl;
    cout << "Max # of occurrences for any word: " << maxOccurrences << endl;
    cout << "Min # of occurrences for any word: " << minOccurrences << endl;
    cout << "Max score for any word:            " << maxScore << endl;
    cout << "Min score for any word:            " << minScore << endl;

    // Now prompt user for reviews to analyze
    cout << "Enter review you want to analyze: ";
    getline(cin, review);
    while (review.length() > 0) {
        double score;

        score = AnalyzeReview(database, review );
        cout << "The review has an average value of " << score << endl;
        cout << "Enter review you want to analyze: ";
        getline(cin, review);
    }
}

// Reads the file consisting of movie review -- one per line, with numerical rating at the start of
// the line.  Breaks the review text into words using blanks as the delimiter, and inserts each
// word into the database along with the rating for the review
// Parameters:
//      filename - name of movie review file
//      database - the word database
// Returns:
//      true indicates database successfully built, false indicates a problem
//  Possible Errors:
//      could not read file
//      database full
bool BuildDatabase(const string& fileName, Database& database) {
    assert(false);
}

// Splits the review text into words and averages the scores of all the words that are found
// to produce a score for the review.
// Parameters:
//      database - the word database
//      review - the movie review text
// Returns:
//      true indicates database successfully built, false indicates a problem
// Possible Errors:
//      none
double AnalyzeReview(const Database& database, const string& review) {
    assert(false);
}
