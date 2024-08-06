/*
 * (c) 2019 Blackberry Inc. All rights reserved.
 */

#pragma once

#include <unistd.h>

#include <sys/stat.h>

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
    /** C API.
     */
    GD_C_API off64_t GD_UNISTD_lseek64(int fd, off64_t offset, int whence);

    /** C API.
     */
    GD_C_API ssize_t GD_UNISTD_pwrite64(int fd, const void *buffer, size_t nbyte, off64_t offset);

    /** File statistics.
     * This is 64-bit version of stat.
     * This function returns information about the file at a specified path. Read,
     * write or execute permission of the named file is not required, but all
     * directories listed in the path name leading to the file must be searchable.
     *
     * @param path <tt>const char*</tt> pointer to a C string containing the path to the file.\n
     *
     * @param buf <tt>struct stat64*</tt> buffer in which to write the stat data.\n
     *
     * @return <tt>int</tt> 0 on success, -1 on failure.\n
     */
    GD_C_API int GD_stat64(const char* path, struct stat64* buf);

    /** File statistics.
     * This is 64-bit version of lstat.
     * This function returns information about the file at a specified path. Read,
     * write or execute permission of the named file is not required, but all
     * directories listed in the path name leading to the file must be searchable.
     * GD_UNISTD_lstat() is identical to GD_stat(), except that if path is a symbolic link, then
     * the link itself is stat-ed, not the file that it refers to.
     *
     * @param path <tt>const char*</tt> pointer to a C string containing the path to the file.\n
     *
     * @param buf <tt>struct stat64*</tt> buffer in which to write the stat data.\n
     *
     * @return <tt>int</tt> 0 on success, -1 on failure.\n
     */
    GD_C_API int GD_UNISTD_lstat64(const char *path, struct stat64 *buf);

    /** File statistics.
     * This is 64-bit version of fstat.
     * This function returns information about the file at a specified path. Read,
     * write or execute permission of the named file is not required, but all
     * directories listed in the path name leading to the file must be searchable.
     * GD_UNISTD_fstat() is identical to GD_stat(), except that the file to be
     * stat-ed is specified by the file descriptor fd.
     *
     * @param fd <tt>int</tt> file descriptor which specifies file to be stat-ed.\n
     *
     * @param buf <tt>struct stat64*</tt> buffer in which to write the stat data.\n
     *
     * @return <tt>int</tt> 0 on success, -1 on failure.\n
     */
    GD_C_API int GD_UNISTD_fstat64(int fd, struct stat64 *buf);

#ifdef __cplusplus
}
#endif

/** @}
 */
