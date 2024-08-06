/*
 * (c) 2022 BlackBerry Limited. All rights reserved.
 */

#pragma once

/** \addtogroup capilist
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef GD_C_API
#   if !defined(_WIN32)
#       define GD_C_API __attribute__((visibility("default")))
#   else
#       define GD_C_API
#   endif
#endif

#include <sys/types.h>

/** C API.
 */
GD_C_API ssize_t GD_sendfile(int out_fd, int in_fd, off_t *offset, size_t count);

#ifdef __cplusplus
}
#endif

/** @}
 */
