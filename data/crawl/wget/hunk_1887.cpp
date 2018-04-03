 #include "utils.h"
 #include "log.h"
 
+/* 2005-10-25 SMS.
+   VMS log files are often VFC record format, not stream, so fputs() can
+   produce multiple records, even when there's no newline terminator in
+   the buffer.  The result is unsightly output with spurious newlines.
+   Using fprintf() instead of fputs(), along with inhibiting some
+   fflush() activity below, seems to solve the problem.
+*/
+#ifdef __VMS
+# define FPUTS( s, f) fprintf( (f), "%s", (s))
+#else /* def __VMS */
+# define FPUTS( s, f) fputs( (s), (f))
+#endif /* def __VMS [else] */
+
 /* This file impplement support for "logging".  Logging means printing
    output, plus several additional features:
 
