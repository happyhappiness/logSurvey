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

