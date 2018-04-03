  return new;
}

/* Return a new string */
bool
remote_to_utf8 (const char *str, const char **new)
{
  char *remote;
  iconv_t cd;
  bool ret = false;

  if (opt.encoding_remote)
    remote = opt.encoding_remote;
  else if (current)
    remote = current;
  else
    return false;

  cd = iconv_open ("UTF-8", remote);
  if (cd == (iconv_t)(-1))
    return false;

  if (do_conversion (cd, (char *) str, strlen ((char *) str), (char **) new))
    ret = true;

  iconv_close (cd);

  /* Test if something was converted */
  if (!strcmp (str, *new))
    {
      xfree ((char *) *new);
      return false;
    }

  return ret;
}

char *get_remote_charset (void)
{
  return remote;
}

char *get_current_charset (void)
{
  return current;
}

void set_current_charset (char *charset)
{
  /*printf("[ current = `%s'\n", charset);*/

  if (current)
    xfree (current);

  current = charset ? xstrdup (charset) : NULL;
}

void set_current_as_locale (void)
{
  /*printf("[ current = locale = `%s'\n", opt.locale);*/
  if (current)
    xfree (current);

  /* sXXXav : assert opt.locale NULL ? */
  current = xstrdup (opt.locale);
}

void
set_remote_charset (char *charset)
{
  /*printf("[ remote = `%s'\n", charset);*/
  if (remote)
    xfree (remote);

  remote = charset ? xstrdup (charset) : NULL;
}

void
set_remote_as_current (void)
{
  /*printf("[ remote = current = `%s'\n", current);*/
  if (remote)
    xfree (remote);

  remote = current ? xstrdup (current) : NULL;
}

