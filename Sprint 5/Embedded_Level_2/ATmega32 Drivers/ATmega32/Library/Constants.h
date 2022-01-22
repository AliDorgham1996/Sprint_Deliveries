#ifndef CONSTANTS_H
#define CONSTANTS_H


#include <stdint.h>              
#include <stdbool.h>
#include <stdio.h>           

#ifndef _C
#define _C const
#endif

#ifndef _E
#define _E extern
#endif

#ifndef _S
#define _S static
#endif

#ifndef _V
#define _V volatile
#endif

#define HIGH      1U
#define LOW       0U

#define INPUT     0U
#define OUTPUT    1U

#define ENABLE    1U
#define DISABLE   0U

#define RESET     0U


#endif /* CONSTANTS_H */