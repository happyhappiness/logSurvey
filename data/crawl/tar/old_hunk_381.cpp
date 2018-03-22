  if (remove_files_option)
    {
      if (unlink (p) == -1)
	ERROR ((0, errno, _("Cannot remove %s"), p));
    }
  return;

unknown:
  ERROR ((0, 0, _("%s: Unknown file type; file ignored"), p));
}
