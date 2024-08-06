//
//  Copyright (c) 2015 Good Technology. All rights reserved.
//
#pragma once
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#if defined(__APPLE__)
#   if !defined(OVERRIDE)
#       define OVERRIDE override
#   endif
#   define GD_ATTRIBUTE __attribute__
#   define GD_ATTRIBUTE_NORETURN __attribute__((noreturn))
#   define GD_ATTRIBUTE_UNUSED __attribute__((unused))
#   define GD_FALLTHROUGH \
        /* FALLTHROUGH */ \
        [[clang::fallthrough]];
#   define GD_HAS_WARNING(warningText) \
__has_warning(warningText)
#   define GD_PRAGMA_DIAGNOSTIC_PUSH()
#   define GD_PRAGMA_DIAGNOSTIC_IGNORED(warningText) \
GD_PRAGMA(clang diagnostic push) \
GD_PRAGMA(clang diagnostic ignored warningText)
#   define GD_PRAGMA_DIAGNOSTIC_POP() \
GD_PRAGMA(clang diagnostic pop)
#   define GD_PRAGMA(t) _Pragma(#t)
#elif defined(NDK) || defined(__GNUC__)
#   define OVERRIDE override
#   define GD_ATTRIBUTE __attribute__
#   define GD_ATTRIBUTE_NORETURN __attribute__((noreturn))
#   define GD_ATTRIBUTE_UNUSED __attribute__((unused))
#   define GD_FALLTHROUGH \
        /* FALLTHROUGH */
#   define GD_HAS_WARNING(warningText) 0
#   define GD_PRAGMA_DIAGNOSTIC_PUSH()
#   define GD_PRAGMA_DIAGNOSTIC_IGNORED(warningText)
#   define GD_PRAGMA_DIAGNOSTIC_POP()
#   define GD_PRAGMA(t) _Pragma(#t)
#elif defined(_WIN32)
#   define OVERRIDE override
#   define GD_ATTRIBUTE(ignore)
#   define GD_ATTRIBUTE_NORETURN
#   define GD_ATTRIBUTE_UNUSED
#   define GD_FALLTHROUGH \
        /* FALLTHROUGH */
#   define GD_HAS_WARNING(warningText) 0
#   define GD_PRAGMA_DIAGNOSTIC_PUSH()
#   define GD_PRAGMA_DIAGNOSTIC_IGNORED(warningText)
#   define GD_PRAGMA_DIAGNOSTIC_POP()
#   define GD_PRAGMA(t) __pragma(t)
#endif
#if defined(__cplusplus)
namespace GD
{
    // Cross platform version of strlcpy
    // will copy up to size-1 bytes from src to dst
    // will null terminate dst
    // dst and src must not overlap
    // size should be equal dst buffer size, including +1 for NULL terminator
    inline void strlcpy(char * dst, const char * src, size_t size)
    {
#if defined(_WIN32)
        ::strcpy_s(dst, size, src);
#elif defined(__GNUC__) && !defined(NDK)
        /* glibc does not provide strlcpy/strlcat for theological reasons */
        assert(size);
        ::strncpy(dst, src, size - 1);
        dst[size - 1] = 0; /* guarantee termination */
#else
        ::strlcpy(dst, src, size);
#endif
    }

    template <size_t size>
    inline void strlcpy(char (&dst)[size], const char *src)
    {
        strlcpy(dst, src, size);
    }
    
    inline void strlcat(char * dst, const char * src, size_t size)
    {
#if defined(_WIN32)
        ::strcat_s(dst, size, src);
#elif defined(__GNUC__) && !defined(NDK)
        assert(size);
        ::strncat(dst, src, size - 1);
        dst[size - 1] = 0; /* guarantee termination */
#else
        ::strlcat(dst, src, size);
#endif
    }
    
    template <size_t size>
    inline void strlcat(char (&dst)[size], const char *src)
    {
        strlcat(dst, src, size);
    }
    
    // Create a new char buffer on heap that is a copy of another buffer
    // See: https://buildsecurityin.us-cert.gov/articles/knowledge/coding-practices/strcpy-and-strcat
    inline char* newStringBuffer(const char* src)
    {
        if (src) {
            auto const srcLen = ::strlen(src);
            char* buffer = new char[srcLen+1];
            ::strncpy(buffer, src, srcLen+1);
            return buffer;
        }
        return NULL;
    }
    
    inline char* mallocStringBuffer(const char* src)
    {
        if (src) {
            auto const srcLen = ::strlen(src);
            char* buffer = (char*)::malloc(srcLen+1);
            ::strncpy(buffer, src, srcLen+1);
            return buffer;
        }
        return NULL;
    }
}
#endif
