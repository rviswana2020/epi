#include <cassert>
#include <iostream>

short countBits(unsigned int x) {
   short setBitCount = 0;
   while(x) {
       setBitCount += (x & 1);
       x >>= 1;
   }
   return setBitCount;
}

int main() {
	short setBitCount = countBits(0xa);
	assert(setBitCount == 2);

	setBitCount = countBits(0xaa);
	assert(setBitCount == 4);

	return 0;
}
