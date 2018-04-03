  int i;
  printf ("\nMalloc:  %d\nFree:    %d\nBalance: %d\n\n",
	  malloc_count, free_count, malloc_count - free_count);
  for (i = 0; i < countof (malloc_debug); i++)
    if (malloc_debug[i].ptr != NULL)
      printf ("0x%08ld: %s:%d\n", (long)malloc_debug[i].ptr,
	      malloc_debug[i].file, malloc_debug[i].line);
}

void *
xmalloc_debug (size_t size, const char *source_file, int source_line)
{
  void *ptr = xmalloc_real (size);
  ++malloc_count;
  register_ptr (ptr, source_file, source_line);
  return ptr;
}

void *
xmalloc0_debug (size_t size, const char *source_file, int source_line)
{
  void *ptr = xmalloc0_real (size);
  ++malloc_count;
  register_ptr (ptr, source_file, source_line);
  return ptr;
}

void *
xrealloc_debug (void *ptr, size_t newsize, const char *source_file, int source_line)
{
  void *newptr = xrealloc_real (ptr, newsize);
  if (!ptr)
    {
      ++malloc_count;
