#include "../lib/word_2048.hpp"
#include <iomanip>



/**
 * Default Constructor
 * 
 * Initialize to zero
 * 
 */
Word_2048::Word_2048() {

    // Filling up the data
    data.fill(0);

}




/**
 * Default Constructor
 * 
 * Initialize to zero and setting the word_name
 * 
 */
Word_2048::Word_2048(std::string word_name_input) {

    // Filling up the data
    data.fill(0);


    // Setting up the word_name
    this->word_name = word_name_input;

}




/**
 * Destructor
 * 
 */
Word_2048::~Word_2048() {
    // Nothing to do here
}




/**
 * Randomize method
 * 
 * Setup a random value for the word
 * 
 */
void Word_2048::randomize() {

    // Running through each bloc
    for (size_t i = 0; i < data.size(); ++i) {

        // Reseting the bloc
        data[i] = 0;


        // Filling the bloc with random 0 and 1
        for (int j = 0; j < 32; ++j) {

            // If the random number can be divided by 2
            if (std::rand() % 2) {

                // Bit set
                data[i] |= (1ULL << j);

            }

        }

    }

}




/**
 * Display : display the entire data with it's hidden parts
 */
void Word_2048::display() {

    // Configure output stream to make it display uppercase hexa
    std::cout << std::hex << std::uppercase;


    // Beginning of the display
    std::cout << "########################" << std::endl;


    // If the word name is not empty
    if (!this->word_name.empty()) {

        // Adding the word name
        std::cout << " -> " << this->word_name << std::endl;
        std::cout << "------------------------" << std::endl;

    }


    // Running through each bloc
    for (long unsigned int i = 64; i > 0; i--) {

        // Getting the upper and lower part of the bloc
        unsigned int high   = static_cast<unsigned int>(this->data[i - 1] >> 32);
        unsigned int low    = static_cast<unsigned int>(this->data[i - 1] & 0xFFFFFFFF);


        // Display the bloc with this model [upper_part] lower_part
        std::cout   << "[0x" << std::setw(8) << std::setfill('0') << high << "] 0x"
                    << std::setw(8) << std::setfill('0') << low << std::endl;

    }


    // End of the display
    std::cout << "########################" << std::endl;


    // Reseting the output stream (to not disturb other other display)
    std::cout << std::dec;

}



/**
 * ============================================================================================
 * Overriding operators
 * ============================================================================================
 */



/**
 * Overrinding the addition
 * 
 */
Word_2048 Word_2048::operator+(Word_2048& word_2) {

    // Result
    Word_2048 sum = Word_2048();


    // Making the addition for each bloc separatly
    for (long unsigned int i = 0; i < 64; i++) {

        // Adding the bloc from the word_1 and the bloc from the word_2
        sum.setBloc(this->getBloc(i) + word_2.getBloc(i), i);


        // Taking the carry from the previous addition
        if (i != 0) {

            // Getting the upper part from the previous bloc
            uint64_t carry = static_cast<uint64_t>(sum.getBloc(i - 1) >> 32);
            sum.setBloc(sum.getBloc(i) + carry, i);


            // Deleting the carry
            uint64_t mask = 0x00000000FFFFFFFFULL;
            sum.setBloc(sum.getBloc(i - 1) & mask, i - 1);

        }

    }


    // Deleting the last carry
    uint64_t mask = 0x00000000FFFFFFFFULL;
    sum.setBloc(sum.getBloc(63) & mask, 63);


    // Returning the sum
    return sum;
}




/**
 * Overriding Cout :
 * 
 * Display the only data that is usable (each 32bit long lower part of blocs)
 */
std::ostream& operator<<(std::ostream& os, const Word_2048& word) {

    // Configure output stream to make it display uppercase hexa
    os << std::hex << std::uppercase;


    // Running through each bloc
    for (long unsigned int i = 64; i > 0; i--) {

        // Getting the lower part of the bloc
        unsigned int low    = static_cast<unsigned int>(word.data[i - 1] & 0xFFFFFFFF);


        // Display the lower_part
        os << "0x" << std::setw(8) << std::setfill('0') << low;


        // Rendering
        if (((i - 1) % 8) == 0) {

            // New line
            os << std::endl;

        }
        else {

            // Spacing
            os << " ";

        }

    }


    // Reseting the output stream (to not disturb other other display)
    os << std::dec << std::endl << std::endl;


    // Returning the stream
    return os;
}