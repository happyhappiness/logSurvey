 #include "test.h"
 #endif 
 
+static void
+memfatal (const char *context, long attempted_size)
+{
+  /* Make sure we don't try to store part of the log line, and thus
+     call malloc.  */
+  log_set_save_context (false);
+
+  /* We have different log outputs in different situations:
+     1) output without bytes information
+     2) output with bytes information  */
+  if (attempted_size == UNKNOWN_ATTEMPTED_SIZE)
+    {
+      logprintf (LOG_ALWAYS,
+                 _("%s: %s: Failed to allocate enough memory; memory exhausted.\n"),
+                 exec_name, context);
+    }
+  else
+    {
+      logprintf (LOG_ALWAYS,
+                 _("%s: %s: Failed to allocate %ld bytes; memory exhausted.\n"),
+                 exec_name, context, attempted_size);
+    }
+
+  exit (1);
+}
+
 /* Utility function: like xstrdup(), but also lowercases S.  */
 
 char *
 src/Makefile.am | 4 ++--
 1 file changed, 2 insertions(+), 2 deletions(-)
