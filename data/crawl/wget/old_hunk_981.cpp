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
    {
      /* Do nothing if already equal */
      if (!strcasecmp (current, charset))
        return;
      xfree (current);
    }

  current = charset ? xstrdup (charset) : NULL;
}

void set_current_as_locale (void)
{
  /* sXXXav : assert opt.locale NULL ? */
  /*printf("[ current = locale = `%s'\n", opt.locale);*/
  if (current)
    {
      if (!strcasecmp (current, opt.locale))
        return;
      xfree (current);
    }

  current = xstrdup (opt.locale);
}

void
set_remote_charset (char *charset)
{
  /*printf("[ remote = `%s'\n", charset);*/
  if (remote)
    {
      /* Do nothing if already equal */
      if (!strcasecmp (remote, charset))
        return;
      xfree (remote);
    }
  remote = charset ? xstrdup (charset) : NULL;
}

void
set_remote_as_current (void)
{
  /*printf("[ remote = current = `%s'\n", current);*/
  if (remote)
    {
      /* Do nothing if already equal */
      if (current && !strcasecmp (remote, current))
        return;
      xfree (remote);
    }

  remote = current ? xstrdup (current) : NULL;
}

void reset_utf8_encode (void)
{
  set_utf8_encode (opt.enable_iri);
}

void set_utf8_encode (bool encode)
{
  utf8_encode = encode;
}

bool get_utf8_encode (void)
{
  return (!ugly_no_encode && utf8_encode);
}

void set_ugly_no_encode (bool ugly)
{
  ugly_no_encode = ugly;
}

