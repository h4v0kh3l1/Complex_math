//
//  vecmath.c
//  cmath
//
//  Created by Heli Wang on 11/15/11.
//  Copyright (c) 2011 Carnegie Mellon. All rights reserved.
//

#include <stdio.h>

#include "cintvecmath.h"


bool is_cintvec(cintvec a)
{
	return a->length == sizeof(a) / sizeof(int);
}

bool can_add_cintvec(cintvec a, cintvec b)
{
	return a->length == b->length;
}

cintvec new_cintvec(cint* carray, int l)
{
	cintvec new = (cintvec) malloc(sizeof(struct cintvec));
	new->length = l;
	new->carray = malloc(sizeof(cint)*l);
	for (int i = 0; i < l; i++) {
		new->carray[i] = malloc(sizeof(int)*2);
		new->carray[i][0] = carray[i][0];
		new->carray[i][1] = carray[i][1];
	}
	return new;
}

void free_cintvec(cintvec a)
{
	for (int i = 0; i < a->length; i++) {
		free(a->carray[i]);
	}
	free(a->carray);
	free(a);
}

cintvec add_cintvec(cintvec a, cintvec b)
{
	if (can_add_cintvec(a, b)) {
		cintvec new = (cintvec) malloc(sizeof(struct cintvec));
		new->length = a->length;
		new->carray = malloc(sizeof(cint)*a->length);
		for (int i = 0; i < a->length; i++) {
			new->carray[i] = add_cint(a->carray[i], b->carray[i]);
		}
		return new;
	}
	else return NULL;
}

cint dotprod_cintvec(cintvec a, cintvec b)
{
	if (can_add_cintvec(a, b)) {
		cint dprod = cint(new_cint(0, 0));
		for (int i = 0; i < a->length; i++) {
			sadd_cint(dprod, mult_cint(a->carray[i], b->carray[i]));
		}
		return dprod;
	}
	else return NULL; 
}