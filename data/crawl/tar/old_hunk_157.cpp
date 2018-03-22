}

void
truncate_error (char const *name)
{
  call_arg_error ("truncate", name);
}

void
truncate_warn (char const *name)
{
  call_arg_warn ("truncate", name);
}

void
unlink_error (char const *name)
{
  call_arg_error ("unlink", name);
}

void
utime_error (char const *name)
{
  call_arg_error ("utime", name);
}

void
waitpid_error (char const *name)
{
  call_arg_error ("waitpid", name);
}

void
write_error (char const *name)
{
  call_arg_error ("write", name);
}

void
write_error_details (char const *name, size_t status, size_t size)
{
  if (status == 0)
    write_error (name);
  else
    ERROR ((0, 0,
	    ngettext ("%s: Wrote only %lu of %lu byte",
		      "%s: Wrote only %lu of %lu bytes",
		      size),
	    name, (unsigned long int) status, (unsigned long int) size));
}

void
write_fatal (char const *name)
{
  call_arg_fatal ("write", name);
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
