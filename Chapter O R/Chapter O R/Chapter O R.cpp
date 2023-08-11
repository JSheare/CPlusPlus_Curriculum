#include <iostream>

/*
    CHAPTER O
*/

/*
    O.1
*/
// Modifying individual bits within an object is called bit manipulation
// When individual bits of an object are used as Boolean values, the bits are called bit flags
// To define a set of bit flags, we'll typically use an unsigned integer of appropriate size, or std::bitset
#include <bitset>
// std::bitset<8> mybitset {}; // 8 bits in size means room for 8 flags

// Best practice: bit manipulation is one of the few times when you should unambiguously use unsigned integers (or std::bitset)

// Given a sequence of bits, we typically number the bits from reight to left, starting with 0 (not 1). Each number denotes a bit position 

// Bitset allows us to do a few things
/*
    * .test() allows us to query whether a bit is a 0 or 1
    * .set(0 allows us to turn a bit on (this will do nothing if hte bit is already on
    * .reset() allows us to turn a bit off (this will do nothing if the bit is already off
    * .flip() allows us to flip a bit value from 1 to 0 or from 0 to 1
*/

// std::bitset is optimized for speed, not memory savings

/*
    O.2
*/
// C++ provides 6 bit manipulation operators, often called bitwise operators
// List: https://www.learncpp.com/cpp-tutorial/bitwise-operators/
// Best practice: to avoid surprises, use the bitwise operators with unsigned operands or std::bitset

// The bitwise left shift (<<) operator shifts bits to the left
// The bitwise right shift (>>) operator shifts bits to the right
// The left operand is the expression to shift the bits of, and the right operand is an integer number of bits to shift by
// Note: bits that are shifted off the end of the binary number are lost forever

// Note that if you're using operator<< for both output and left shift, parenthesization is required

// The bitwise NOT operator (~) simply flips all bits from a 0 to a 1 or vice versa

// Bitwise OR (|) works like logical OR but it applies it to each bit:
// 0b0101 | 0b0110 would be 0b0111

// Bitwise AND (&) works similarly to bitwise OR but with and
// 0b0101 & 0b0110 would be 0b0100

// Bitwise XOR (^) evaluates to true (1) if one and only one of its operands is true (1). If neither or both are true, it evaluates to 0
// 0b0110 ^ 0b0011 would be 0b0101

// Bitwise assignment operators exist https://www.learncpp.com/cpp-tutorial/bitwise-operators/

/*
    O.3
*/
// A bit mask is a predefined set of bits that is used to select which specific bits will be modified by subsequent operations
// Bit flags make the most sense when you have many identical flag variables

#if 0
int main()
{
    std::bitset<8> bits{ 0b0000'0101 }; // we need 8 bits, start with bit pattern 0000 0101
    bits.set(3); // set bit position 3 to 1 (now we have 0000 1101)
    bits.flip(4); // flip bit 4 (now we have 0001 1101)
    bits.reset(4); // set bit 4 back to 0 (now we have 0000 1101)

    std::cout << "All the bits: " << bits << '\n';
    std::cout << "Bit 3 has value: " << bits.test(3) << '\n';
    std::cout << "Bit 4 has value: " << bits.test(4) << '\n';

    return 0;
}
#endif