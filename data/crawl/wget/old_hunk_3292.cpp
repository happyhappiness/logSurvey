void
xfree_debug (void *ptr, const char *source_file, int source_line)
{
  assert (ptr != NULL);
  ++free_count;
  unregister_ptr (ptr);
  free (ptr);
}

#endif /* DEBUG_MALLOC */
