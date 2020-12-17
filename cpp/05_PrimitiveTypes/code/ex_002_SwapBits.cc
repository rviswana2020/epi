#include <cassert>

long long swapBits(long long x, int i, int j) {
	if( ((x >> i) & 1) == ((x >> j) & 1))
		return x;

	long long mask = (1L << i) | (1L << j);
	return x ^ mask;
}

int main(int argc, char* argv[]) {
	long long swappedX = swapBits(0xa, 0, 1);
	assert(swappedX == 9);  
 
}
