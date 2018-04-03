   return var;
 }
 
+/* Given a string, shell-execute it and return a malloc'ed string of the
+ * result. This removes only ONE newline (if any) at the end, for maximum
+ * compatibility with the *BSD makes.  If it fails, returns NULL. */
+
+char *
+shell_result (const char *p)
+{
+  char *buf;
+  unsigned int len;
+  char *args[2];
+  char *result;
+
+  install_variable_buffer (&buf, &len);
+
+  args[0] = (char *) p;
+  args[1] = NULL;
+  variable_buffer_output (func_shell_base (variable_buffer, args, 0), "\0", 1);
+  result = strdup (variable_buffer);
+
+  restore_variable_buffer (buf, len);
+  return result;
+}
+
 /* Given a variable, a value, and a flavor, define the variable.
    See the try_variable_definition() function for details on the parameters. */
 
