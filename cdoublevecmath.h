//
//  cdoublevecmath.h
//  cmath
//
//  Created by Heli Wang on 11/15/11.
//  Copyright (c) 2011 Carnegie Mellon. All rights reserved.
//

#ifndef cmath_cdoublevecmath_h
#define cmath_cdoublevecmath_h

#include <stdbool.h>
#include <stdlib.h>
#include "cdoublemath.h"

typedef struct cdoublevec* cdoublevec;
struct cdoublevec{
	int length;
	cdouble* carray;
};

bool is_cdoublevec(cdoublevec a);
bool can_add_cdoublevec(cdoublevec a, cdoublevec b);
cdoublevec new_cdoublevec(cdouble* carray, int l);
void free_cdoublevec(cdoublevec a);
cdoublevec add_cdoublevec(cdoublevec a, cdoublevec b);

#endif
