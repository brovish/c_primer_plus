#ifndef BASIC_PRE_HELPERS_H

#define BASIC_PRE_HELPERS_H

#include <stdbool.h>

#define SQUARE(X) ((X)*(X))
#define MAX(X,Y) ((X)>(Y)?(X):(Y))
#define ABS(X) ((X)<0?-(X):(X))
#define INVERSE(X) (1/(X))
#define ISSIGN(X) ((X)=='+'||(X)=='-'?true:false)
#define PR(X, ...) printf("Message " #X ": " __VA_ARGS__)
#define HARM_MEAN(X,Y) (2/((INVERSE(X))+(INVERSE(Y))))

#endif

