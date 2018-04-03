

void *
xrealloc (void *ptr, unsigned int size)
{
  void *result;

  /* Some older implementations of realloc() don't conform to ANSI.  */
  if (! size)
    size = 1;
  result = ptr ? realloc (ptr, size) : malloc (size);
