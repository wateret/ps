// pseudorandom number generator
// linear feedback shift register

unsigned short lfsr = 0xACE1u;
unsigned bit;

int next(int N)
{
	bit = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5) ) & 1;
	lfsr = (lfsr >> 1) | (bit << 15);
	return lfsr % N;
}

