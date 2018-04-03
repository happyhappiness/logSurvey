extern int errno;
#endif


/* Croak the fatal memory error and bail out with non-zero exit
   status.  */
static void
memfatal (const char *s)
{
  /* HACK: expose save_log_p from log.c, so we can turn it off in
     order to prevent saving the log.  Saving the log is dangerous
     because logprintf() and logputs() can call malloc(), so this
     could infloop.  When logging is turned off, infloop can no longer
     happen.  */
  extern int save_log_p;

  save_log_p = 0;
  logprintf (LOG_ALWAYS, _("%s: %s: Not enough memory.\n"), exec_name, s);
  exit (1);
}

/* xmalloc, xrealloc and xstrdup exit the program if there is not
   enough memory.  xstrdup also implements strdup on systems that do
   not have it.  xfree is provided to make leak-tracking easier.
   Currently it's a no-op.  */

void *
xmalloc (size_t size)
{
  void *res;

  res = malloc (size);
  if (!res)
    memfatal ("malloc");
  return res;
}

void
xfree (void *ptr)
{
  free (ptr);
}

void *
xrealloc (void *obj, size_t size)
{
  void *res;

  /* Not all Un*xes have the feature of realloc() that calling it with
     a NULL-pointer is the same as malloc(), but it is easy to
     simulate.  */
  if (obj)
    res = realloc (obj, size);
  else
    res = malloc (size);
  if (!res)
    memfatal ("realloc");
  return res;
}

char *
xstrdup (const char *s)
{
#ifndef HAVE_STRDUP
  int l = strlen (s);
  char *s1 = malloc (l + 1);
  if (!s1)
    memfatal ("strdup");
  memcpy (s1, s, l + 1);
  return s1;
#else  /* HAVE_STRDUP */
  char *s1 = strdup (s);
  if (!s1)
    memfatal ("strdup");
  return s1;
#endif /* HAVE_STRDUP */
}

/* Copy the string formed by two pointers (one on the beginning, other
   on the char after the last char) to a new, malloc-ed location.
