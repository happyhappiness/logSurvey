    writes a message on stderr and aborts immediately, with another message
    line telling so.  USAGE_ERROR works like FATAL_ERROR except that the
    other message line suggests trying --help.  All four macros accept a
-   single argument of the form ((0, errno, _("FORMAT"), Args...)).  `errno'
-   is `0' when the error is not being detected by the system.  */
+   single argument of the form ((0, errno, _("FORMAT"), Args...)).  errno
+   is zero when the error is not being detected by the system.  */
 
 #define WARN(Args) \
   error Args
 #define ERROR(Args) \
   (error Args, exit_status = TAREXIT_FAILURE)
 #define FATAL_ERROR(Args) \
-  (error Args, error (TAREXIT_FAILURE, 0, \
-		      _("Error is not recoverable: exiting now")), 0)
+  (error Args, fatal_exit ())
 #define USAGE_ERROR(Args) \
-  (error Args, usage (TAREXIT_FAILURE), 0)
+  (error Args, usage (TAREXIT_FAILURE))
 
-/* Information gleaned from the command line.  */
-
 #include "arith.h"
-#include "modechange.h"
+#include <backupfile.h>
+#include <exclude.h>
+#include <full-write.h>
+#include <modechange.h>
+#include <quote.h>
+#include <safe-read.h>
+
+/* Log base 2 of common values.  */
+#define LG_8 3
+#define LG_64 6
+#define LG_256 8
+
+/* Information gleaned from the command line.  */
 
 /* Name of this program.  */
 GLOBAL const char *program_name;
