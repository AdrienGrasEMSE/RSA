#ifndef WORD_2048
#define WORD_2048



#include <array>
#include <iostream>
#include <stdint.h>
#include <string>


#include <cstdlib> // For random function
#include <ctime>   // For random seed


class Word_2048 {
private:

    /**
     * The word itself
     * 
     * 
     * It is composed by 64 64bit long variables. Only the half bottom is considered.
     * The half top is used for operation, to store caries or the half top result.
     * 
     */
    std::array<uint64_t, 64>   data;


    // For visibily in the command line
    std::string                 word_name;


public:

    // Constructors
    Word_2048();
    Word_2048(std::string word_name_input);



    // Destructor
    ~Word_2048();


    // Bloc setter and getter
    void        setBloc(uint64_t bloc_input, long unsigned int bloc_id)     {this->data[bloc_id] = bloc_input;}
    uint64_t    getBloc(long unsigned int bloc_id)                          {return this->data[bloc_id];}


    // Word name setter and getter
    void        setName(std::string word_name_input)                        {this->word_name = word_name_input;}
    std::string getName()                                                   {return this->word_name;}



    // Fill a random value in the word
    void        randomize();


    // Display
    void        display();



    /**
     * ============================================================================================
     * Overriding operators
     * ============================================================================================
     */
    Word_2048 operator+(Word_2048& word_2);



    // Overriding Cout for display
    friend std::ostream& operator<<(std::ostream& os, const Word_2048& word);

};


#endif // WORD_2048




