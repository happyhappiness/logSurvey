}

void
write_error_details (char const *name, ssize_t status, size_t size)
{
  if (status < 0)
    write_error (name);
  else
    ERROR ((0, 0,
	    ngettext ("%s: Wrote only %lu of %lu byte",
		      "%s: Wrote only %lu of %lu bytes",
		      record_size),
	    name, (unsigned long) status, (unsigned long) record_size));
}

void