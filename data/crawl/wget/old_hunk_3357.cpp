}

/* Parse the line pointed by line, with the syntax:
   <sp>* command <sp>* = <sp>* value <newline>
   Uses malloc to allocate space for command and value.
   If the line is invalid, data is freed and 0 is returned.

   Return values:
    1 - success
    0 - failure
   -1 - empty */

static int
parse_line (const char *line, char **com, char **val, int *comind)
