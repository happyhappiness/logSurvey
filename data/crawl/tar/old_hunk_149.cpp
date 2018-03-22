# define GLOBAL extern
#endif

/* Exit status for GNU tar.  Let's try to keep this list as simple as
   possible.  -d option strongly invites a status different for unequal
   comparison and other errors.  */
GLOBAL int exit_status;

#define TAREXIT_SUCCESS 0
#define TAREXIT_DIFFERS 1
#define TAREXIT_FAILURE 2

/* Both WARN and ERROR write a message on stderr and continue processing,
   however ERROR manages so tar will exit unsuccessfully.  FATAL_ERROR
   writes a message on stderr and aborts immediately, with another message
   line telling so.  USAGE_ERROR works like FATAL_ERROR except that the
   other message line suggests trying --help.  All four macros accept a
   single argument of the form ((0, errno, _("FORMAT"), Args...)).  errno
   is zero when the error is not being detected by the system.  */

#define WARN(Args) \
  error Args
#define ERROR(Args) \
  (error Args, exit_status = TAREXIT_FAILURE)
#define FATAL_ERROR(Args) \
  (error Args, fatal_exit ())
#define USAGE_ERROR(Args) \
  (error Args, usage (TAREXIT_FAILURE))

#include "arith.h"
#include <backupfile.h>
