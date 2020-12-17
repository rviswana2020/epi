#include <cassert>
unsigned long long ClosestIntSameBitCount(unsigned long long x) {
    for(int i = 0; i < 63; ++i) {
        if( ((x >> i) & 1) != ((x >> (i+1)) & 1) ) {
            unsigned long long mask = (1UL << i) | (1UL << (i+1));
            x ^= mask;
            break;
        }
    }
  return x;
}

int main(int argc, char* argv[]) {
    unsigned long long x = 48;
    unsigned long long y = ClosestIntSameBitCount(x);
	assert( y == 40);
}
