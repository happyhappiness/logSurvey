}

void
write_fatal_details (char const *name, ssize_t status, size_t size)
{
  write_error_details (name, status, size);
  fatal_exit ();
}

/* Fork, aborting if unsuccessful.  */
pid_t
xfork (void)
