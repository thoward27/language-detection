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
    // Len is the length of the interal frequency array.
    const int len = 19683;
    // The internal frequency array.
    int *freq;
    // The name of the file.
    std::string name;

    // Computes power when given two ints, n(umber) and p(ower)
    int power(int n, int p);

    // Returns index given a character and current base.
    int get_index(int c, int b);

    // Fills frequency table based on language.
    void compute_freq(std::string language);

  public:
    //! Constructor
    /** 
     * Builds a Lang object. 
     * \param language is the filename to open.
     * 
     * Time: O(n)
     * Memory: O(n)
     */
    Lang(std::string language);
    Lang();

    //! Destructor
    /** 
     * Destroys the Lang object, and frees memory used for the table. 
     * 
     * Time: O(1)
     */
    ~Lang();

    //! Print frequencies (CAUTION)
    /** 
     * This prints the entire n_gram frequency table. This table is long.
     * For example, for a trigram analysis this prints 19683 numbers, each seperated by a single space.
     * 
     * Time: O(n)
     * Memory: O(1)
     */
    void print() const;

    //! Similarity
    /**
     * This computes similarity between two lang objects
     * 
     * Time: O(n)
     * Memory: O(1)
     */
    double similarity(Lang&) const;

    //! Get Name
    /** 
     * Returns the name of the file
     */
    std::string get_name() const;

    //! [] Operator
    /**
     * Yields the number at a given index in constant time.
     * 
     * Time: O(1)
     * Memory: O(1)
     */
    int operator[](int i) const;
};