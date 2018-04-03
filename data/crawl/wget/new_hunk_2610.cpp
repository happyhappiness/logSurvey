  if (ptr == NULL)
    {
      fprintf (stderr, "%s: xfree(NULL) at %s:%d\n",
               exec_name, source_file, source_line);
      abort ();
    }
  if (!unregister_ptr (ptr))
    {
      fprintf (stderr, "%s: bad xfree(0x%0*lx) at %s:%d\n",
               exec_name, PTR_FORMAT (ptr), source_file, source_line);
      abort ();
    }
  ++free_count;
