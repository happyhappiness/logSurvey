touch_file (struct file *file)
{
  if (!silent_flag)
    message (0, "touch %s", file->name);

  /* Print-only (-n) takes precedence over touch (-t).  */
  if (just_print_flag)
