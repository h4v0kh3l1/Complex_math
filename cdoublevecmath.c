//
//  cdoublevecmath.c
//  cmath
//
//  Created by Heli Wang on 11/15/11.
//  Copyright (c) 2011 Carnegie Mellon. All rights reserved.
//

#include <stdio.h>
#include "cdoublevecmath.h"

bool is_cdoublevec(cdoublevec a)
{
	return a->length == sizeof(a) / sizeof(double);
}

bool can_add_cdoublevec(cdoublevec a, cdoublevec b)
{
	return a->length == b->length;
}

cdoublevec new_cdoublevec(cdouble* carray, int l)
{
	cdoublevec new = (cdoublevec) malloc(sizeof(struct cdoublevec));
	new->length = l;
	new->carray = malloc(sizeof(cdouble)*l);
	for (int i = 0; i < l; i++) {
		new->carray[i] = new_cdouble(carray[i][0], carray[i][1]);
	}
	return new;
}

void free_cdoublevec(cdoublevec a)
{
	for (int i = 0; i < a->length; i++) {
		free(a->carray[i]);
	}
	free(a->carray);
	free(a);
}

cdoublevec add_cdoublevec(cdoublevec a, cdoublevec b)
{
	if (can_add_cdoublevec(a, b)) {
		cdoublevec new = (cdoublevec) malloc(sizeof(struct cdoublevec));
		new->length = a->length;
		new->carray = malloc(sizeof(cdouble)*a->length);
		for (int i = 0; i < a->length; i++) {
			new->carray[i] = add_cdouble(a->carray[i], b->carray[i]);
		}
		return new;
	}
	else return NULL;
}