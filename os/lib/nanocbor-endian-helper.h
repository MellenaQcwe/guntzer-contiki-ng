#pragma once

#include <stdint.h>
#include "uipopt.h"

/*
 * Verify that compiler and Contiki-NG byte orders agree.
 */
#if defined(__BYTE_ORDER__) && \
    defined(__ORDER_LITTLE_ENDIAN__) && \
    defined(__ORDER_BIG_ENDIAN__)

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__

#if UIP_BYTE_ORDER != UIP_LITTLE_ENDIAN
#error "Compiler byte order differs from UIP byte order"
#endif

#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__

#if UIP_BYTE_ORDER != UIP_BIG_ENDIAN
#error "Compiler byte order differs from UIP byte order"
#endif

#else
#error "Unknown byte order"
#endif

#else
#error "Compiler byte-order macros are unavailable"
#endif


/*
 * Linux already provides endian conversion macros.
 * Do not redefine them.
 */
#if defined(__linux__)

#include <endian.h>

/*
 * Non-Linux platforms use compiler byte-swap builtins.
 */
#else

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__

#define htobe16(x) __builtin_bswap16((uint16_t)(x))
#define htole16(x) ((uint16_t)(x))
#define be16toh(x) __builtin_bswap16((uint16_t)(x))
#define le16toh(x) ((uint16_t)(x))

#define htobe32(x) __builtin_bswap32((uint32_t)(x))
#define htole32(x) ((uint32_t)(x))
#define be32toh(x) __builtin_bswap32((uint32_t)(x))
#define le32toh(x) ((uint32_t)(x))

#define htobe64(x) __builtin_bswap64((uint64_t)(x))
#define htole64(x) ((uint64_t)(x))
#define be64toh(x) __builtin_bswap64((uint64_t)(x))
#define le64toh(x) ((uint64_t)(x))

#else

#define htobe16(x) ((uint16_t)(x))
#define htole16(x) __builtin_bswap16((uint16_t)(x))
#define be16toh(x) ((uint16_t)(x))
#define le16toh(x) __builtin_bswap16((uint16_t)(x))

#define htobe32(x) ((uint32_t)(x))
#define htole32(x) __builtin_bswap32((uint32_t)(x))
#define be32toh(x) ((uint32_t)(x))
#define le32toh(x) __builtin_bswap32((uint32_t)(x))

#define htobe64(x) ((uint64_t)(x))
#define htole64(x) __builtin_bswap64((uint64_t)(x))
#define be64toh(x) ((uint64_t)(x))
#define le64toh(x) __builtin_bswap64((uint64_t)(x))

#endif

#endif /* __linux__ */


/*
 * BSD-compatible aliases used by NanoCBOR.
 */
#ifndef betoh16
#define betoh16(x) be16toh(x)
#endif

#ifndef betoh32
#define betoh32(x) be32toh(x)
#endif

#ifndef betoh64
#define betoh64(x) be64toh(x)
#endif

#ifndef letoh16
#define letoh16(x) le16toh(x)
#endif

#ifndef letoh32
#define letoh32(x) le32toh(x)
#endif

#ifndef letoh64
#define letoh64(x) le64toh(x)
#endif