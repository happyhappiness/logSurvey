void
xfree_debug (void *ptr, const char *source_file, int source_line)
{
  /* See xfree_real for rationale of this abort.  We repeat it here
     because we can print the file and the line where the offending
     free occurred.  */
  if (ptr == NULL)
    {
      fprintf ("%s: xfree(NULL) at %s:%d\n",
	       exec_name, source_file, source_line);
      abort ();
    }
  ++free_count;
  unregister_ptr (ptr);
  xfree_real (ptr);
}

#endif /* DEBUG_MALLOC */
