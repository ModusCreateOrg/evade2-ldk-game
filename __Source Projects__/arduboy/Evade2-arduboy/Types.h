#ifndef TYPES_H
#define TYPES_H

#include <Arduboy2Core.h>

typedef uint8_t UBYTE;
typedef int8_t BYTE;
typedef uint16_t UWORD;
typedef int16_t WORD;
typedef uint8_t BOOL;
typedef void *APTR;
typedef uint32_t ULONG;
typedef int32_t LONG;
typedef float FLOAT;

#ifndef TRUE
#define TRUE (!0)
#endif
#ifndef FALSE
#define FALSE 0
#endif
#ifndef NULL
#define NULL (void *)0
#endif

#ifndef PI
#define PI 3.1415926
#endif

#ifndef RADIANS
#define RADIANS(degrees) (FLOAT(degrees) * PI / 180)
#endif

#endif
