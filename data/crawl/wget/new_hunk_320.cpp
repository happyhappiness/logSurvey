/* The log file to which Wget writes to after HUP.  */
#define DEFAULT_LOGFILE "wget-log"

#include <stdio.h>

enum log_options { LOG_VERBOSE, LOG_NOTQUIET, LOG_NONVERBOSE, LOG_ALWAYS };

void log_set_warc_log_fp (FILE *);

void logprintf (enum log_options, const char *, ...)
     GCC_FORMAT_ATTR (2, 3);
void debug_logprintf (const char *, ...) GCC_FORMAT_ATTR (1, 2);
