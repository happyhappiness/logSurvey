
  if (d == 0)
    {
      show_goal_error ();

      /* Didn't find any dependencies to complain about. */
      if (file->parent)
        {
          size_t l = strlen (file->name) + strlen (file->parent->name) + 4;
          const char *m = _("%sNo rule to make target '%s', needed by '%s'%s");

          if (!keep_going_flag)
            fatal (NILF, l, m, "", file->name, file->parent->name, "");

          error (NILF, l, m, "*** ", file->name, file->parent->name, ".");
        }
      else
        {
          size_t l = strlen (file->name) + 4;
          const char *m = _("%sNo rule to make target '%s'%s");

          if (!keep_going_flag)
            fatal (NILF, l, m, "", file->name, "");

          error (NILF, l, m, "*** ", file->name, ".");
        }

      file->no_diag = 0;
