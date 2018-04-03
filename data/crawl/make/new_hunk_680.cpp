#undef xrealloc
#undef xstrdup

void *
xmalloc (unsigned int size)
{
  /* Make sure we don't allocate 0, for pre-ANSI libraries.  */
  void *result = malloc (size ? size : 1);
  if (result == 0)
    fatal (NILF, _("virtual memory exhausted"));
  return result;
}


void *
xrealloc (void *ptr, unsigned int size)
{
  void *result;

  /* Some older implementations of realloc() don't conform to ANSI.  */
  if (! size)
