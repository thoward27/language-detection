#pragma once

#include <string>

//! A Language object for analysis.
/** 
 * The Lang class is able to store n_gram frequencies of any textual language. 
 * It expects a string containing only spaces, and lowercase Engish letters a-z.
 * It does not store the document, but only the n_gram frequencies, user beware. 
 */
class Lang
{
private:
    // The valid ascii range, to compute length of frequencies.
    const int ascii_range = 27;
    // n signifies what n_gram analysis to provide.
    const int n;
    // Len is the length of the interal frequency array. 
    const int len;
    // The internal frequency array. 
    int* freq;

    // Computes the index for each character, uses ascii base. 
    int power(int c, int b);

    // Fills frequency table based on language.
    void compute_freq(std::string language);

public:
    //! Constructor
    /** 
     * Builds a Lang object. 
     * \param language a string of text.
     * \param n is the n_gram to use for analysis. Default is 3, for trigram analysis.
     * 
     * Time: O(n)
     * Memory: O(n)
     */
    Lang(std::string language, int n=3);
    
    //! Destructor
    /** 
     * Destroys the Lang object, and frees memory used for the table. 
     * 
     * Time: O(1)
     */
    ~Lang();

    //! Print frequencies (CAUTION)
    /** 
     * The prints the entire n_gram frequency table. This table is long.
     * For example, for a trigram analysis this prints 19683 numbers, each seperated by a single space.
     * 
     * Time: O(n)
     * Memory: O(1)
     */
    void print();

    //! [] Operator
    /**
     * Yields the number at a given index in constant time.
     * 
     * Time: O(1)
     * Memory: O(1)
     */
    int operator[](int i);
};