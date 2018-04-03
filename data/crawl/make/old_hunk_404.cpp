}


/* Write an error message describing the exit status given in
   EXIT_CODE, EXIT_SIG, and COREDUMP, for the target TARGET_NAME.
   Append "(ignored)" if IGNORED is nonzero.  */

static void
child_error (const struct file *file,
             int exit_code, int exit_sig, int coredump, int ignored)
{
  const char *nm;
  const char *pre = "*** ";
  const char *post = "";
  const char *dump = "";
  gmk_floc *flocp = &file->cmds->fileinfo;

  if (ignored && silent_flag)
    return;
