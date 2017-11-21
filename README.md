# Language Detection in C++ via Trigram Analysis

An attempt to decipher language via trigram analysis, completely in C++. 

## About

This project is not an attempt to utilize deep learning, nor to build an actual algorithm for this process; but rather, an on-the-fly processing unit that is capable of deciding the language of an input file, given a collection of testing data. You must provide *both* items each time you wish to run the program. This necesitates a large repository of language files, and will hopefully be addressed in future iterations. 

# Design

## Problems to solve

- Producing a trigram analysis of a single document
    - O(n) Time, O(1) Memory
- Performing trigram analysis comparisons between two documents; finding a rapid way to determine the similarity of sparse matrices
    - O(n) Time, O(1) Memory
- Some method of testing correctness
    - Unconstrained, should be O(n)

## Classes needed

- File: a class to represent an individual file
    - Private Data:
        - Trigram Array: a simple array containing all possible trigram values (base 27)
        - Perhaps store the document? Is this needed? 
    - Public Methods:
        - `constructor(filename)`: Initiates the object and calls `trigram_analysis()` if the filename is valid, and the file readable
        - `trigram_analysis()`: Performs trigram analyis of document, parsing trigrams and incrementing its own trigram array
        - `compare(file)`: takes another file object, and returns the percent similar out of 100 to its trigram array

- Analysis
    - Private Data:
        - A vector of input files, as `File` objects
        - A single test file, as a `File` object
    - Public Methods:
        - `constructor([filenames])`: All filenames are constructed via `file.construct(filename)`, the last of which, is considered the test file. 
        - `predict()`: Calls compare on the test file against all input files, selecting the filename of the file with the maximum similarity

## Other Functions

- `main()`: 
    - Handles intaking filenames as command line arguments, and immediately passes them to the constructor method of `class Analysis`
    - Also used to test the correctness of the function
    - Will be defined via `CATCH_CONFIG_MAIN`

## Files Needed

- `file.h` and `file.cpp` for `class File`
- `analysis.h` and `analysis.cpp` for `class Analysis`
- `tests.cpp` to define `main` as well as perform tests
- `catch.hpp` used as a testing framework

## Libraries Needed

- `vector`
- `string`
- `iostream` and `fstream`

## Compile Script

- Will use VSCode Compile Script, allowing hot-key mapping and script-chaining to expedite development
    - For those wishing to unpack the scripts, please see the .vscode folder, inside of which you will find a tasks file containin an array version of the exact compile script I use.


