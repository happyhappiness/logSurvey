  return status;
}

/* Generate an error/fatal message if no rules are available for the target.
 */
static void
no_rule_error(file)
  struct file *file;
{
  const char *msg_noparent
    = _("%sNo rule to make target `%s'%s");
  const char *msg_parent
    = _("%sNo rule to make target `%s', needed by `%s'%s");

  if (keep_going_flag || file->dontcare)
    {
      /* If the previous attempt was made while we were creating
         makefiles, but we aren't anymore, print an error now.  */
      if (!file->dontcare
          || (file->mfile_status && !updating_makefiles))
        {
          if (file->parent == 0)
            error (NILF, msg_noparent, "*** ", file->name, ".");
          else
            error (NILF, msg_parent, "*** ",
                   file->name, file->parent->name, ".");
        }
      file->update_status = 2;
      file->mfile_status = updating_makefiles;
    }
  else if (file->parent == 0)
    fatal (NILF, msg_noparent, "", file->name, "");
  else
    fatal (NILF, msg_parent, "", file->name, file->parent->name, "");
}

/* If FILE is not up to date, execute the commands for it.
   Return 0 if successful, 1 if unsuccessful;
   but with some flag settings, just call `exit' if unsuccessful.
