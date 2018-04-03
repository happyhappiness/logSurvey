
  home = home_dir ();
  if (home)
    {
      char *dir = aprintf ("%s/.wget-hsts", home);
      xfree(home);
      return dir;
    }

  return NULL;
}
