   error (enabled by default).
 * `indent-with-non-tab` treats a line that is indented with 8 or more
   space characters as an error (not enabled by default).
+* `cr-at-eol` treats a carriage-return at the end of line as
+  part of the line terminator, i.e. with it, `trailing-space`
+  does not trigger if the character before such a carriage-return
+  is not a whitespace (not enabled by default).
 
 alias.*::
 	Command aliases for the linkgit:git[1] command wrapper - e.g.
