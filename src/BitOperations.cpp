#include "BitOperations.hpp"

using namespace std;

void printBits(uint64_t bb) {
    const size_t len = 5;
    cout << bitset<len>(bb) << endl;
}
uint64_t setBit(uint64_t bb, int pos) {
    bb |= 1 << pos;
    return bb;
}

uint64_t resetBit(uint64_t bb, int pos) {
    bb &= ~(1 << pos);
    return bb;
}