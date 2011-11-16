//
//  cdoublemath.c
//  cmath
//
//  Created by Heli Wang on 11/15/11.
//  Copyright (c) 2011 Carnegie Mellon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "cdoublemath.h"

bool is_cdouble(cdouble a)
{
	return (a != NULL) && ((a+1) != NULL);
}

cdouble new_cdouble(double r, double i)
{
	cdouble new = (cdouble) malloc(sizeof(double)*2);
	*new = r;
	*(new+1) = i;
	return new;
}

void print_cdouble(cdouble a)
{
	printf("(%lf+%lfi)", *a, *(a+1));
}

cdouble add_cdouble(cdouble a, cdouble b)
{
	cdouble new = (cdouble) malloc(sizeof(double)*2);
	*new = *a + *b;
	*(new+1) = *(a+1) + *(b+1);
	return new;
}

cdouble mult_cdouble(cdouble a, cdouble b)
{
	cdouble new = (cdouble) malloc(sizeof(double)*2);
	new[0] = a[0] * b[0] - a[1] * b[1];
	new[1] = a[0] * b[1] + a[1] * b[0];
	return new;
}

cdouble conj_cdouble(cdouble a)
{
	cdouble new = (cdouble) malloc(sizeof(double)*2);
	*new = *a;
	*(new+1) = -*(a+1);
	return new;
}

void sadd_cdouble(cdouble a, cdouble b)
{
	cdouble new = (cdouble) malloc(sizeof(double)*2);
	*new = *a + *b;
	*(new+1) = *(a+1) + *(b+1);
	*a = *new;
	*(a+1) = *(new+1);
	free(new);
}

void smult_cdouble(cdouble a, cdouble b)
{
	cdouble new = (cdouble) malloc(sizeof(double)*2);
	new[0] = a[0] * b[0] - a[1] * b[1];
	new[1] = a[0] * b[1] + a[1] * b[0];
	*a = *new;
	*(a+1) = *(new+1);
	free(new);
}

void sconj_cdouble(cdouble a)
{
	*(a+1) = -*(a+1);
}