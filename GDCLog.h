/*
 * (c) 2015 Good Technology Corporation. All rights reserved.
 */

#ifndef GDC_LOG_H
#define GDC_LOG_H

#include "gt_definitions.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef GD_C_API
#if !defined(GD_WINDOWS) && !defined(GD_WIN32)
#define GD_C_API __attribute__((visibility("default")))
#else
#define GD_C_API
#endif
#endif
    
/** Log level constants for use with GDCLog.
 * This enumeration represents log levels.
 * The <TT>level</TT> parameter of the GDCLog function takes one of these values.
 */
typedef enum
{
    GDC_LOG_ERROR,
    /**< The log message is an error and is always logged.
     */
    GDC_LOG_WARNING,
    /**< The log message is a warning and is always logged.
     */
    GDC_LOG_INFO,
    /**< The log message is informational only and is always logged.
     */
    GDC_LOG_DETAIL
    /**< The log message is only logged when detailed logging is enabled from Good Control.
     */
} GDCLogLevel;

[[gnu::format(printf, 2, 3)]]
GD_C_API void GDCLog(GDCLogLevel level, const char* format, ...);
 /**< Logs an encrypted message persisted within the secure container.
 * Writes an encrypted message to the secure container log.
 *
 * The Good Dynamics Runtime also writes messages to the same log so application 
 * messages will be interleaved. When the log reaches 4 MB older messages are 
 * overwritten.
 * 
 * This function is thread-safe.
 *
 * The message may be formatted.  After the format argument, the function expects at 
 * least as many additional arguments as specified in <TT>format</TT>. See the 
 * <A HREF="http://www.cplusplus.com/reference/clibrary/cstdio/printf/" target="_blank"
 * >C Library Reference</A> for a detailed description of the embedded format tags 
 * that may be used.
 *
 * \param level \ref GDCLogLevel of the message.
 * \param format The message to be logged including optional embedded format tags.
 *
 * Unencrypted messages may be viewed in the Xcode console during execution,
 * or decrypted and exported to the applications's Documents folder later. The logs may also 
 * be securely uploaded to the Good Technology Network Operations Center (NOC).
 * \see \ss_exportlogs_link \ss_function
 * \see \ss_uploadlogs_link \ss_function
 *
 */

#ifdef __cplusplus
}
#endif

#endif
