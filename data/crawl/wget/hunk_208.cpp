   return true;
 }
 
+/* like cmd_file, but insist on just a single option usage */
+static bool
+cmd_file_once (const char *com _GL_UNUSED, const char *val, void *place)
+{
+  if (*(char **)place)
+    {
+      fprintf (stderr, _("%s: %s must only be used once\n"),
+               exec_name, com);
+      return false;
+    }
+
+  return cmd_file(com, val, place);
+}
+
 /* Like cmd_file, but strips trailing '/' characters.  */
 static bool
 cmd_directory (const char *com, const char *val, void *place)
