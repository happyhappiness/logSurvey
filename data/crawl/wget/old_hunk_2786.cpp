    }
  if (!unregister_ptr (ptr))
    {
      fprintf (stderr, "%s: bad xfree(%0*lx) at %s:%d\n",
	       exec_name, PTR_FORMAT (ptr), source_file, source_line);
      abort ();
    }
