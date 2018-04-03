#endif


/* Return the absolute name of file NAME which does not contain any `.',
   `..' components nor any repeated path separators ('/').   */

static char *
abspath (const char *name, char *apath)
{
  char *dest;
  const char *start, *end, *apath_limit;

  if (name[0] == '\0' || apath == NULL)
    return NULL;

  apath_limit = apath + PATH_MAX;

  if (name[0] != '/')
    {
      /* It is unlikely we would make it until here but just to make sure. */
      if (!starting_directory)
	return NULL;

      strcpy (apath, starting_directory);

      dest = strchr (apath, '\0');
    }
  else
    {
      apath[0] = '/';
      dest = apath + 1;
    }

  for (start = end = name; *start != '\0'; start = end)
    {
      unsigned long len;

      /* Skip sequence of multiple path-separators.  */
      while (*start == '/')
	++start;

      /* Find end of path component.  */
      for (end = start; *end != '\0' && *end != '/'; ++end)
        ;

      len = end - start;

      if (len == 0)
	break;
      else if (len == 1 && start[0] == '.')
	/* nothing */;
      else if (len == 2 && start[0] == '.' && start[1] == '.')
	{
	  /* Back up to previous component, ignore if at root already.  */
	  if (dest > apath + 1)
	    while ((--dest)[-1] != '/');
	}
      else
	{
	  if (dest[-1] != '/')
            *dest++ = '/';

	  if (dest + len >= apath_limit)
            return NULL;

	  dest = memcpy (dest, start, len);
          dest += len;
	  *dest = '\0';
	}
    }

  /* Unless it is root strip trailing separator.  */
  if (dest > apath + 1 && dest[-1] == '/')
    --dest;

  *dest = '\0';

  return apath;
}


static char *
func_realpath (char *o, char **argv, const char *funcname UNUSED)
{
  /* Expand the argument.  */
  char *p = argv[0];
  char *path = 0;
  int doneany = 0;
  unsigned int len = 0;

  char in[PATH_MAX];
  char out[PATH_MAX];

  while ((path = find_next_token (&p, &len)) != 0)
    {
      if (len < PATH_MAX)
        {
          strncpy (in, path, len);
          in[len] = '\0';

          if
          (
#ifdef HAVE_REALPATH
            realpath (in, out)
#else
            abspath (in, out)
#endif
          )
            {
              o = variable_buffer_output (o, out, strlen (out));
              o = variable_buffer_output (o, " ", 1);
              doneany = 1;
            }
        }
    }

  /* Kill last space.  */
  if (doneany)
    --o;

 return o;
}

static char *
func_abspath (char *o, char **argv, const char *funcname UNUSED)
{
  /* Expand the argument.  */
  char *p = argv[0];
  char *path = 0;
  int doneany = 0;
  unsigned int len = 0;

  char in[PATH_MAX];
  char out[PATH_MAX];

  while ((path = find_next_token (&p, &len)) != 0)
    {
      if (len < PATH_MAX)
        {
          strncpy (in, path, len);
          in[len] = '\0';

          if (abspath (in, out))
            {
              o = variable_buffer_output (o, out, strlen (out));
              o = variable_buffer_output (o, " ", 1);
              doneany = 1;
            }
        }
    }

  /* Kill last space.  */
  if (doneany)
    --o;

 return o;
}

/* Lookup table for builtin functions.

   This doesn't have to be sorted; we use a straight lookup.  We might gain
