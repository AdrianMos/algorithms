/*
hashing - the division method

good practice in choosing a hash function:
  h(k) = k mod m
	1. don't pick m with a small divisor d
	   why? e.g. d=2 & all keys are even
	   => h(k) is even (k is even, m is even), meaning that half of the slots will not be used (the odd ones)

	2. don't pick m a power of two (=2^r)
	   why? k mod 2^r <=> extracting the lower r bits => h(k) doesn't depend on all the bits of k,
	   which is bad, considering that it is a regularity of data that the lower bits are the same

	3. choose a prime number, not to o close to the power of 2 or 10
	   (2 and 10 being common bases for data)
*/

#include "stdafx.h"

unsigned int hash(unsigned int key, unsigned int m) {
	return key % m;
}

const char LENGTH = 17;

void print_array(char *pArray) {
	printf("[ ");
	for (char i=0; i<LENGTH; i++) {
		printf("%2d ", *(pArray+i));
	}
	printf("]");
}

void print_line_break() {
	printf("------------------------------------------------------------------------\n");
}

void case1() {
	int m = 12;
	char subset[LENGTH] = { 0, 2, 4, 6,  8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32 };
	
	printf("\nsubset includes only odd numbers; m=%d is a multiple of d(=2); h(k)=k mod m\n", m);
	printf("\nsubset= ");
	print_array(&subset[0]);

	printf("\nhashed= [ ");
	for (int i = 0; i < LENGTH; i++) {
		printf("%2d ", hash(subset[i], m));
	}
	printf("] \n");
	print_line_break();
}

void case2() {
	int m = 12;
	char subset[LENGTH] = { 0, 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45, 48 };

	printf("\nsubset includes divisors of 3; m=%d is a multiple of d; h(k)=k mod m\n", m);
	printf("\nsubset= ");
	print_array(&subset[0]);

	printf("\nhashed= [ ");
	for (int i = 0; i < LENGTH; i++) {
		printf("%2d ", hash(subset[i], m));
	}
	printf("] \n");
	print_line_break();
}

void case3() {
	int m = 13;
	char subset[LENGTH] = { 0, 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45, 48 };

	printf("\nsubset includes divisors of 3; m=%d is a prime number; h(k)=k mod m\n", m);
	printf("\nsubset= ");
	print_array(&subset[0]);

	printf("\nhashed= [ ");
	for (int i = 0; i < LENGTH; i++) {
		printf("%2d ", hash(subset[i], m));
	}
	printf("] \n");
	print_line_break();
}

void case4() {
	int m = 13;
	char subset[LENGTH] = { 0, 2, 4, 6,  8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32 };

	printf("\nsubset includes only odd numbers; m=%d is a prime number; h(k)=k mod m\n", m);
	printf("\nsubset= ");
	print_array(&subset[0]);

	printf("\nhashed= [ ");
	for (int i = 0; i < LENGTH; i++) {
		printf("%2d ", hash(subset[i], m));
	}
	printf("] \n");
	print_line_break();
}


int main()
{
	case1();

	printf("\n=> CONCLUSION: - bad distribution when k and m have common factors;");
	printf("\n                 in this case the even slots are not used at all");
	printf("\n\n\n");

	case4();
	printf("\n=> CONCLUSION: - good distriution when m is prime");
	printf("\n\n\n");

	case2();
	case3();

	getchar();
	return 0;
}