#pragma once

#include "config.h"

#define _VA1_(x, ...) "\x1b[31m" x "\x1b[39m"
#define _VAX_(x, ...) __VA_ARGS__

#ifdef Debug

#define print(...) printf( \
    _VA1_(__VA_ARGS__) _VAX_(__VA_ARGS__))

#else

#define print(...)

#endif