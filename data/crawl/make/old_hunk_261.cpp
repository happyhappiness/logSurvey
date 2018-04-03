
  if (d == 0)
    {
      const char *msg_noparent
        = _("%sNo rule to make target '%s'%s");
      const char *msg_parent
        = _("%sNo rule to make target '%s', needed by '%s'%s");

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
