}

/*
  Replace/remove the basename of a file name.

  The file name is permanently modified.

  Always set NAME to a string, even an empty one.

  Use REF's basename as replacement.  If REF is NULL or if it doesn't
  provide a valid basename candidate, then remove NAME's basename.
*/
void
replace_metalink_basename (char **name, char *ref)
{
  int n;
  char *p, *new, *basename;

  if (!name)
    return;

  /* Strip old basename.  */
  if (*name)
    {
      basename = last_component (*name);

      if (basename == *name)
        xfree (*name);
      else
        *basename = '\0';
    }

  /* New basename from file name reference.  */
  if (ref)
    ref = last_component (ref);

  /* Replace the old basename.  */
  new = aprintf ("%s%s", *name ? *name : "", ref ? ref : "");
  xfree (*name);
  *name = new;

  /* Remove prefix drive letters if required, i.e. when in w32
     environments.  */
  p = new;
  while (p[0] != '\0')
    {
      while ((n = FILE_SYSTEM_PREFIX_LEN (p)) > 0)
        p += n;

      if (p != new)
        {
          while (ISSLASH (p[0]))
            ++p;
          new = p;
          continue;
        }

      break;
    }

  if (*name != new)
    {
      new = xstrdup (new);
      xfree (*name);
      *name = new;
    }
}

/*
  Strip the directory components from the given name.

  Return a pointer to the end of the leading directory components.
