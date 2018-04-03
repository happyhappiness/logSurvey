/* Show a message stating the target failed to build.  */

static void
complain (struct file *file)
{
  const char *msg_noparent
    = _("%sNo rule to make target `%s'%s");
  const char *msg_parent
    = _("%sNo rule to make target `%s', needed by `%s'%s");

  /* If this file has no_diag set then it means we tried to update it
     before in the dontcare mode and failed. The target that actually
     failed is not necessarily this file but could be one of its direct
     or indirect dependencies. So traverse this file's dependencies and
     find the one that actually caused the failure. */

  struct dep *d;

  for (d = file->deps; d != 0; d = d->next)
    {
      if (d->file->updated && d->file->update_status > 0 && file->no_diag)
        {
          complain (d->file);
          break;
        }
    }

  if (d == 0)
    {
      /* Didn't find any dependencies to complain about. */
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

      file->no_diag = 0;
    }
}

/* Consider a single `struct file' and update it as appropriate.  */
