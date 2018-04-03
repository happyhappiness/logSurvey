 
   Close (child_stdout);
 
-  fold_newlines (buffer, &i);
+  fold_newlines (buffer, &i, trim_newlines);
   o = variable_buffer_output (o, buffer, i);
   free (buffer);
   return o;
 }
 #endif  /* _AMIGA */
+
+char *
+func_shell (char *o, char **argv, const char *funcname UNUSED)
+{
+  return func_shell_base (o, argv, 1);
+}
 #endif  /* !VMS */
 
 #ifdef EXPERIMENTAL
