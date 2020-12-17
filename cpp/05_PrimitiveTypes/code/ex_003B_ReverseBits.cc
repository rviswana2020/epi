#include <cassert>
#include <array>

unsigned long long ReverseBits(unsigned long long x) {
    std::array<int, 16> reverseLookUp{
                                    0,        //0b'0000
                                    8,        //0b'0001
                                    4,        //0b'0010
                                    12,        //0b'0011
                                    2,        //0b'0100
                                    10,        //0b'0101
                                    6,        //0b'0110
                                    14,        //0b'0111
                                    1,        //0b'1000
                                    9,        //0b'1001
                                    5,        //0b'1010
                                    13,        //0b'1011
                                    3,        //0b'1100
                                    11,        //0b'1101
                                    7,        //0b'1110
                                    15        //0b'1111
                                };

    constexpr int numBits = sizeof(x) * 8;

    constexpr int kBitMask = 0xf;
    constexpr int kWordSize = 4;

    unsigned long long result = 0;
    for(int i = 0; i < numBits / kWordSize; ++i) {
        int index = (x >> i * kWordSize) & kBitMask;
        result <<= kWordSize;
        result |= reverseLookUp[index];
    }

    return result;
}

int main(int argc, char* argv[]) {
    unsigned long long x = 0xABCD'1234'0000'0000;
    unsigned long long y = ReverseBits(x);
    assert(y == 0x2C48'B3D5);
}
