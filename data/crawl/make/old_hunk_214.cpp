#ifndef MAKE_SYMLINKS
  if (check_symlink_flag)
    {
      error (NILF, _("Symbolic links not supported: disabling -L."));
      check_symlink_flag = 0;
    }
#endif
