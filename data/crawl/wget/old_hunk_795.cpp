{
  /*printf("[ remote = `%s'\n", charset);*/
  if (remote)
    xfree (remote);

  remote = charset ? xstrdup (charset) : NULL;
}

