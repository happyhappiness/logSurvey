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

