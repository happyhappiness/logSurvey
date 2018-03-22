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
