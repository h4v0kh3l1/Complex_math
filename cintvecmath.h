//
//  vecmath.h
//  cmath
//
//  Created by Heli Wang on 11/15/11.
//  Copyright (c) 2011 Carnegie Mellon. All rights reserved.
//


#ifndef cmath_cintvecmath_h
#define cmath_cintvecmath_h

#include <stdbool.h>
#include <stdlib.h>
#include "cintmath.h"

typedef struct cintvec* cintvec;
struct cintvec{
	int length;
	cint* carray;
};

bool is_cintvec(cintvec a);
bool can_add_cintvec(cintvec a, cintvec b);
cintvec new_cintvec(cint* carray, int l);
void free_cintvec(cintvec a);
cintvec add_cintvec(cintvec a, cintvec b);
cint dotprod_cintvec(cintvec a, cintvec b);



#endif
