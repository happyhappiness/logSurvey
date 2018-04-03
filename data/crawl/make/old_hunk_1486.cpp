     register struct file *file;
{
  if (!silent_flag)
    {
      printf ("touch %s\n", file->name);
      fflush (stdout);
    }

#ifndef	NO_ARCHIVES
  if (ar_name (file->name))
