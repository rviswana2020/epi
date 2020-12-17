#include <cassert>
#include <iostream>

unsigned long long ReverseBits(unsigned long long x) {

    int end = sizeof(x) * 8 - 1;
    int start = 0;

    while(start < end) {
        if(((x >> start) & 1) != ((x >> end) & 1)) {
            unsigned long long mask = (1UL << start) | (1UL << end);
            x ^= mask;
        }
        start++;
        end--;
    }

    return x;
}

int main(int argc, char* argv[]) {
    unsigned long long x = 0xABCD'1234;
    unsigned long long y = ReverseBits(x);
	std::cout << "y" << y << std::endl;
    assert(y == 0x2C48'B3D5'0000'0000);
}
