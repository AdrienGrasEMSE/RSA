/**
 * Test file : implementation
 * 
 * File filled with test function wich test different features.
 */
#include "../lib/Tests.hpp"



// Main funtion
int all_test() {

    // Test start
    std::cout << "==========Test : START==========" << std::endl;


    // All tests
    test_Word2048_addition();


    // Program end
    std::cout << "===========Test : END===========" << std::endl;
    return 0;

}




/**
 * Test : addition for Word_2048 objects
 * 
 * 
 * Test with 3 different calculations if the addition is implemented correctly.
 * 
 * A + B = Ctest
 * 
 * If Ctest = Ccorrect, then the test is passed.
 */
void test_Word2048_addition() {

    // Number of tested passed
    int nb_pass = 0;


    // Test var
    Word_2048 word_1 = Word_2048();
    Word_2048 word_2 = Word_2048();
    Word_2048 word_3 = Word_2048();




    /**
     * Calculation 1 :
     * 
     * A = 0xA38C F998 ->   . 0 1010 0011 1000 1100 1111 1001 1001 1000
     * B = 0xB12F DDB8 ->   + 0 1011 0001 0010 1111 1101 1101 1011 1000
     *                      =
     *                      +                                    1 0000
     *                      +                               1 0100
     *                      +                          1 0110
     *                      +                     1 1100
     *                      +                1 1011
     *                      +             1010
     *                      +        0100
     *                      + 1 0101
     *                      = 1 0101 0100 1011 1100 1101 0111 0101 0000
     * 
     * C => 0x1 54BC D750
     */
    word_1.setBloc(0xA38CF998, 0);
    word_2.setBloc(0xB12FDDB8, 0);
    word_3 = word_1 + word_2;


    // Test
    if (word_3.getBloc(0) == 0x54BCD750 && word_3.getBloc(1) == 0x00000001) {
        nb_pass ++;
    }




    // Reset
    word_1 = Word_2048();
    word_2 = Word_2048();
    word_3 = Word_2048();




    /**
     * Calculation 2 :
     * 
     * A = 0x72AB 6B3D ->   . 0 0111 0010 1010 1011 0110 1011 0011 1101
     * B = 0xC430 CA49 ->   + 0 1100 0100 0011 0000 1100 1010 0100 1001
     *                      =
     *                      +                                    1 0110
     *                      +                                 0111
     *                      +                          1 0101
     *                      +                     1 0010
     *                      +                  1011
     *                      +             1101
     *                      +        0110
     *                      + 1 0011
     *                      = 1 0011 0110 1101 1100 0011 0101 1000 0110
     * 
     * C => 0x1 36DC 3586
     */
    word_1.setBloc(0x72AB6B3D, 0);
    word_2.setBloc(0xC430CA49, 0);
    word_3 = word_1 + word_2;


    // Test
    if (word_3.getBloc(0) == 0x36DC3586 && word_3.getBloc(1) == 0x00000001) {
        nb_pass ++;
    }




    // Reset
    word_1 = Word_2048();
    word_2 = Word_2048();
    word_3 = Word_2048();



    /**
     * Calculation 3 :
     * 
     * A = 0x72AB 6B3D | A38C F998 ->   . 0 0111 0010 1010 1011 0110 1011 0011 1101 |   1010 0011 1000 1100 1111 1001 1001 1000
     * B = 0xC430 CA49 | B12F DDB8 ->   + 0 1100 0100 0011 0000 1100 1010 0100 1001 |   1011 0001 0010 1111 1101 1101 1011 1000
     *                                  =                                           |
     *                                  +                                           |                                    1 0000
     *                                  +                                           |                               1 0100
     *                                  +                                           |                          1 0110
     *                                  +                                           |                     1 1100
     *                                  +                                           |                1 1011
     *                                  +                                           |             1010
     *                                  +                                           |        0100  
     *                                  +                                         1 |   0101  
     *                                  +                                    1 0110 
     *                                  +                                 0111
     *                                  +                          1 0101
     *                                  +                     1 0010
     *                                  +                  1011
     *                                  +             1101
     *                                  +        0110
     *                                  + 1 0011
     *                                  = 1 0011 0110 1101 1100 0011 0101 1000 0111 |   0101 0100 1011 1100 1101 0111 0101 0000
     * 
     * C => 0x1 36DC 3587 | 54BC D750
     */
    word_1.setBloc(0xA38CF998, 0);
    word_2.setBloc(0xB12FDDB8, 0);
    word_1.setBloc(0x72AB6B3D, 1);
    word_2.setBloc(0xC430CA49, 1);
    word_3 = word_1 + word_2;


    // Test
    if (word_3.getBloc(0) == 0x54BCD750 && word_3.getBloc(1) == 0x36DC3587 && word_3.getBloc(2) == 0x00000001) {
        nb_pass ++;
    }




    // Final test
    if (nb_pass != 3) {
        std::cout << "TEST FAILED : ADDITION" << std::endl;
    } else {
        std::cout << "TEST PASSED : ADDITION" << std::endl;
    }

}
