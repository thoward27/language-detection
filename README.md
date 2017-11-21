# Language Detection in C++ via Trigram Analysis

An attempt to decipher language via trigram analysis, completely in C++. 

## About

This project is not an attempt to utilize deep learning, nor to build an actual algorithm for this process; but rather, an on-the-fly processing unit that is capable of deciding the language of an input file, given a collection of testing data. You must provide *both* items each time you wish to run the program. This necesitates a large repository of language files, and will hopefully be addressed in future iterations. 

# Design

## Problems to solve

- Can language of an input file be determined via trigram analysis and comparison against a collection of labeled files. 
- Use minimum extra storage
- Performance should scale linearly

## Classes needed

- File
    - Constructed via filename
    - Must intepret filename properly, and read resulting contents
    - Parsing of contents into relevant trigrams
    - Contain a custom trigram array, capable of holding all valid trigrams in the English alphabet
    - Comparison method, which will return an integer value out of 100 as a measure of similarity

- Analysis
    - Constructed via a collection of filenames
    - Should instantiate a `file` object for every filename passed into itself
    - Should `compare` each trigram count, and select the name with the max similarity to the `target_file`

## Other Functions

- `TEST_CASE` to test functionality
- 

## File Object


