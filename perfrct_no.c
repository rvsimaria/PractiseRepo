/**
 * @file      : perfect_no.c
 * @brief     : This file contains cource code for perfect number.
 * @author    : Vishal kumar (vishalkumar@vvdntech.in)
 * @Copyright : (c) 2012-2013 , VVDN Technologies Pvt. Ltd.
 *	        Permission is hereby granted to everyone in VVDN Technologies
 *	        to use the Software without restriction, including without
 *	        limitation the rights to use, copy, modify, merge, publish,
 *	        distribute, distribute with modifications.
 */

#include<stdio.h>

#define LKT

#define int_64 unsigned long long int

#ifndef LKT
static int isperfect(int_64);
#endif

int_64 lookup[] = {6, 28, 496, 8128, 33550336, 8589869056, 137438691328};

int main(void)
{
	int look_s = 0;
	int_64 i, j;

	#ifndef LKT
	int_64 in;

	printf("enter loop end point\n");
	scanf("%llu", &in);

	for (i = 1; i < in; i++) {
		if (isperfect(i))
			printf("%llu\n", i);
	}
	#else
	for (i = 1; i < 10000000000; i++) {
		for (j = look_s; j < 7; j++) {
			if (i < lookup[j])
				break;
			else if (i == lookup[j]) {
				look_s++;
				printf("%llu\n", i);
			}
		}
	}
	#endif

	return 0;
}

#ifndef LKT
int isperfect(int_64 number)
{
	int_64 i;
	int_64 rem = 0;
	int_64 sum = 0;

	for (i = 1; i <= (number - 1); i++) {
		rem = number % i;
		if (rem == 0)
			sum = sum + i;
	}
	if (sum == number)
		return 1;
	return 0;
}
#endif
