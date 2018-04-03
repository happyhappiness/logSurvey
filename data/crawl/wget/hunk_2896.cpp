    Uses malloc to allocate space for command and value.
    If the line is invalid, data is freed and 0 is returned.
 
-   Return values:
-    1 - success
-    0 - error
-   -1 - empty
+   Returns one of line_ok, line_empty, line_syntax_error, or
+   line_unknown_command.
 
-   In case of success, *COM and *VAL point to freshly allocated
+   In case of line_ok, *COM and *VAL point to freshly allocated
    strings, and *COMIND points to com's index.  In case of error or
-   empty line, those values are unaffected.  */
+   empty line, their values are unmodified.  */
 
-static int
+static enum parse_line
 parse_line (const char *line, char **com, char **val, int *comind)
 {
   const char *p;
