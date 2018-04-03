

void *
xcalloc (unsigned int size)
{
  /* Make sure we don't allocate 0, for pre-ISO implementations.  */
  void *result = calloc (size ? size : 1, 1);
  if (result == 0)
    fatal (NILF, _("virtual memory exhausted"));
  return result;
}


void *
xrealloc (void *ptr, unsigned int size)
{
  void *result;

  /* Some older implementations of realloc() don't conform to ISO.  */
  if (! size)
    size = 1;
  result = ptr ? realloc (ptr, size) : malloc (size);
