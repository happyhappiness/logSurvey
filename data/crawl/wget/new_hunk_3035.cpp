  int i;
  printf ("\nMalloc:  %d\nFree:    %d\nBalance: %d\n\n",
	  malloc_count, free_count, malloc_count - free_count);
  for (i = 0; i < SZ; i++)
    if (malloc_table[i].ptr != NULL)
      printf ("0x%0*lx: %s:%d\n", 2 * sizeof (void *),
	      (long) malloc_table[i].ptr,
	      malloc_table[i].file, malloc_table[i].line);
}

void *
debugging_malloc (size_t size, const char *source_file, int source_line)
{
  void *ptr = checking_malloc (size);
  ++malloc_count;
  register_ptr (ptr, source_file, source_line);
  return ptr;
}

void *
debugging_malloc0 (size_t size, const char *source_file, int source_line)
{
  void *ptr = checking_malloc0 (size);
  ++malloc_count;
  register_ptr (ptr, source_file, source_line);
  return ptr;
}

void *
debugging_realloc (void *ptr, size_t newsize, const char *source_file, int source_line)
{
  void *newptr = checking_realloc (ptr, newsize);
  if (!ptr)
    {
      ++malloc_count;
