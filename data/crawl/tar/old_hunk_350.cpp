name_close (void)
{
  if (name_file && name_file != stdin)
    if (fclose (name_file) == EOF)
      ERROR ((0, errno, "%s", name_buffer));
}

/*-------------------------------------------------------------------------.
