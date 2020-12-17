#include <cassert>
#include <array>

short parity(unsigned long long x) {
    std::array<int, 16> precomputedParity { 0, // 0x0000
                                            1, // 0x0001
                                            1, // 0x0010
                                            0, // 0x0011
                                            1, // 0x0100
                                            0, // 0x0101
                                            0, // 0x0110
                                            1, // 0x0111
                                            1, // 0x1000
                                            0, // 0x1001
                                            0, // 0x1010
                                            1, // 0x1011
                                            0, // 0x1100
                                            1, // 0x1101
                                            1, // 0x1110
                                            0 // 0x1111
                                          };
    constexpr int kWordSize = 4;
    constexpr int kBitMask = 0xF;

    return precomputedParity[x >> (15 * kWordSize) & kBitMask] ^
           precomputedParity[x >> (14 * kWordSize) & kBitMask] ^
           precomputedParity[x >> (13 * kWordSize) & kBitMask] ^
           precomputedParity[x >> (12 * kWordSize) & kBitMask] ^
           precomputedParity[x >> (11 * kWordSize) & kBitMask] ^
           precomputedParity[x >> (10 * kWordSize) & kBitMask] ^
           precomputedParity[x >> (9 * kWordSize) & kBitMask] ^
           precomputedParity[x >> (8 * kWordSize) & kBitMask] ^
           precomputedParity[x >> (7 * kWordSize) & kBitMask] ^
           precomputedParity[x >> (6 * kWordSize) & kBitMask] ^
           precomputedParity[x >> (5 * kWordSize) & kBitMask] ^
           precomputedParity[x >> (4 * kWordSize) & kBitMask] ^
           precomputedParity[x >> (3 * kWordSize) & kBitMask] ^
           precomputedParity[x >> (2 * kWordSize) & kBitMask] ^
           precomputedParity[x >> (1 * kWordSize) & kBitMask] ^
           precomputedParity[x & kBitMask];
}

int main(int argc, char* argv[]) {
    short result = parity(0xa);
    assert(result == 0);

    result = parity(0xb);
    assert(result == 1);
}
