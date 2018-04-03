/* Show a message stating the target failed to build.  */

static void
complain (const struct file *file)
{
  const char *msg_noparent
    = _("%sNo rule to make target `%s'%s");
  const char *msg_parent
    = _("%sNo rule to make target `%s', needed by `%s'%s");

  if (!keep_going_flag)
    {
      if (file->parent == 0)
        fatal (NILF, msg_noparent, "", file->name, "");

      fatal (NILF, msg_parent, "", file->name, file->parent->name, "");
    }

  if (file->parent == 0)
    error (NILF, msg_noparent, "*** ", file->name, ".");
  else
    error (NILF, msg_parent, "*** ", file->name, file->parent->name, ".");
}

/* Consider a single `struct file' and update it as appropriate.  */
