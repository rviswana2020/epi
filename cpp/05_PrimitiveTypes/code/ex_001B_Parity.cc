#include <cassert>

short parity(unsigned long long x) {
    short result = 0;
    while(x) {
        result ^= 1;
        x = x & (x-1);
    }
    return result;
}

int main(int argc, char* argv[]) {
    short result = parity(0xa);
    assert(result == 0);

    result = parity(0xb);
    assert(result == 1);
}
