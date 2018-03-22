  if (remove_files_option)
    {
      if (unlink (p) == -1)
	unlink_error (p);
    }
  return;

unknown:
  ERROR ((0, 0, _("%s: Unknown file type; file ignored"),
	  quotearg_colon (p)));
}
