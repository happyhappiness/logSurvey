}


/* Write an error message describing the exit status given in
   EXIT_CODE, EXIT_SIG, and COREDUMP, for the target TARGET_NAME.
   Append "(ignored)" if IGNORED is nonzero.  */

static void
child_error (struct child *child,
             int exit_code, int exit_sig, int coredump, int ignored)
{
  const char *pre = "*** ";
