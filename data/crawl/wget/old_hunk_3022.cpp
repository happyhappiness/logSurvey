{
  int i;
  if (malloc_count - free_count > SZ)
    abort ();

  i = ptr_position (ptr);
  malloc_table[i].ptr = ptr;
