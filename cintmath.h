//
//  cmath.h
//  cmath
//
//  Created by Heli Wang on 11/15/11.
//  Copyright (c) 2011 Carnegie Mellon. All rights reserved.
//

#include <stdbool.h>

#ifndef cmath_cintmath_h
#define cmath_cintmath_h
#define cint int*

bool is_cint(cint a);
cint new_cint(int r, int i);
void print_cint(cint a);
cint add_cint(cint a, cint b);
cint mult_cint(cint a, cint b);
cint conj_cint(cint a);
void sadd_cint(cint a, cint b);
void smult_cint(cint a, cint b);
void sconj_cint(cint a);


#endif
