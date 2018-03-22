   writes a message on stderr and aborts immediately, with another message
   line telling so.  USAGE_ERROR works like FATAL_ERROR except that the
   other message line suggests trying --help.  All four macros accept a
   single argument of the form ((0, errno, _("FORMAT"), Args...)).  `errno'
   is `0' when the error is not being detected by the system.  */

#define WARN(Args) \
  error Args
#define ERROR(Args) \
  (error Args, exit_status = TAREXIT_FAILURE)
#define FATAL_ERROR(Args) \
  (error Args, error (TAREXIT_FAILURE, 0, \
		      _("Error is not recoverable: exiting now")), 0)
#define USAGE_ERROR(Args) \
  (error Args, usage (TAREXIT_FAILURE), 0)

/* Information gleaned from the command line.  */

#include "arith.h"
#include "modechange.h"

/* Name of this program.  */
GLOBAL const char *program_name;
