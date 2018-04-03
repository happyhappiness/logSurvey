
  if (d == 0)
    {
      /* Didn't find any dependencies to complain about. */
      if (file->parent)
        {
          size_t l = strlen (file->name) + strlen (file->parent->name) + 4;

          if (!keep_going_flag)
            fatal (NILF, l,
                   _("%sNo rule to make target '%s', needed by '%s'%s"),
                   "", file->name, file->parent->name, "");

          error (NILF, l, _("%sNo rule to make target '%s', needed by '%s'%s"),
                 "*** ", file->name, file->parent->name, ".");
        }
      else
        {
          size_t l = strlen (file->name) + 4;

          if (!keep_going_flag)
            fatal (NILF, l,
                   _("%sNo rule to make target '%s'%s"), "", file->name, "");

          error (NILF, l,
                 _("%sNo rule to make target '%s'%s"), "*** ", file->name, ".");
        }

      file->no_diag = 0;
    }
