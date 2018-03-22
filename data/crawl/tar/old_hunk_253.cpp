  if (status < 0)
    write_error (name);
  else
    ERROR ((0, 0, _("%s: Wrote only %lu of %lu bytes"),
	    name, (unsigned long) status, (unsigned long) record_size));
}

