name_close (void)
{
  if (name_file && name_file != stdin)
    if (fclose (name_file) != 0)
      close_error (name_buffer);
}

/*-------------------------------------------------------------------------.
