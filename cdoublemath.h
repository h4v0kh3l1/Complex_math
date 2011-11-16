//
//  cdblmath.h
//  cmath
//
//  Created by Heli Wang on 11/15/11.
//  Copyright (c) 2011 Carnegie Mellon. All rights reserved.
//

#include <stdbool.h>

#ifndef cmath_cdoublemath_h
#define cmath_cdoublemath_h

#define cdouble double*

bool is_cdouble(cdouble a);
cdouble new_cdouble(double r, double i);
void print_cdouble(cdouble a);
cdouble add_cdouble(cdouble a, cdouble b);
cdouble mult_cdouble(cdouble a, cdouble b);
cdouble conj_cdouble(cdouble a);
void sadd_cdouble(cdouble a, cdouble b);
void smult_cdouble(cdouble a, cdouble b);
void sconj_cdouble(cdouble a);


#endif

