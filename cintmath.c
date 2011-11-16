//
//  cmath.c
//  cmath
//
//  Created by Heli Wang on 11/15/11.
//  Copyright (c) 2011 Carnegie Mellon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cintmath.h"

bool is_cint(cint a)
{
	return ((a != NULL) && ((a+1) != NULL));
}

cint new_cint(int r, int i)
{
	cint new = (cint) malloc(sizeof(int)*2);
	*new = r;
	*(new+1) = i;
	return new;
}

void print_cint(cint a)
{
	printf("(%d, %d)", *a, *(a+1));
}

cint add_cint(cint a, cint b)
{
	cint new = (cint) malloc(sizeof(int)*2);
	*new = *a + *b;
	*(new+1) = *(a+1) + *(b+1);
	return new;
}

cint mult_cint(cint a, cint b)
{
	cint new = (cint) malloc(sizeof(int)*2);
	new[0] = a[0] * b[0] - a[1] * b[1];
	new[1] = a[0] * b[1] + a[1] * b[0];
	return new;
}

cint conj_cint(cint a)
{
	cint new = (cint) malloc(sizeof(int)*2);
	*new = *a;
	*(new+1) = -*(a+1);
	return new;
}

void sadd_cint(cint a, cint b)
{
	cint new = (cint) malloc(sizeof(int)*2);
	*new = *a + *b;
	*(new+1) = *(a+1) + *(b+1);
	*a = *new;
	*(a+1) = *(new+1);
	free(new);
}

void smult_cint(cint a, cint b)
{
	cint new = (cint) malloc(sizeof(int)*2);
	new[0] = a[0] * b[0] - a[1] * b[1];
	new[1] = a[0] * b[1] + a[1] * b[0];
	*a = *new;
	*(a+1) = *(new+1);
	free(new);
}

void sconj_cint(cint a)
{
	*(a+1) = -*(a+1);
}