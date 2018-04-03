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

