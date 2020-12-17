#include <cassert>

short parity(unsigned long long x) {
    // TODO - you fill in here.
    x = x ^ (x >> 32);
    x = x ^ (x >> 16);
    x = x ^ (x >> 8);
    x = x ^ (x >> 4);
    x = x ^ (x >> 2);
    x = x ^ (x >> 1);
    return x & 1;
}

int main(int argc, char* argv[]) {
    short result = parity(0xa);
    assert(result == 0);

    result = parity(0xb);
    assert(result == 1);
}
