#pragma once
#include <bitset>
#include <cstdint>
#include <iostream>

using namespace std;

void printBits(uint64_t bb);
uint64_t setBit(uint64_t bb, int pos);
uint64_t resetBit(uint64_t bb, int pos);